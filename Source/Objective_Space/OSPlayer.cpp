// Fill out your copyright notice in the Description page of Project Settings.

#include "OSPlayer.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "OSWeapon.h"
#include "Components/ChildActorComponent.h"
#include "OSUsableEntity.h"

// Sets default values
AOSPlayer::AOSPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	myArmMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ArmMesh"));
	myArmMesh->SetupAttachment(GetMesh());

	mySpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	mySpringArmComponent->SetupAttachment(myArmMesh, FName("CameraSocket"));

	myCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	myCameraComponent->SetupAttachment(mySpringArmComponent);

	myChildActorComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("ChildActorComponent"));
	myChildActorComponent->SetupAttachment(myArmMesh, FName("R_GunSocket"));
}

// Called when the game starts or when spawned
void AOSPlayer::BeginPlay()
{
	Super::BeginPlay();

	SpawnUI();
	
}

// Called every frame
void AOSPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RaycastInFront();

	if (GetVelocity().Size() <= 0)
	{
		StopSprint();
	}

	if (myWeapon == nullptr)
	{
		myWeapon = Cast<AOSWeapon>(myChildActorComponent->GetChildActor());
	}

	if (myWantToShoot && myWeapon != nullptr && myWeapon->myCanShoot && !myWeapon->myIsReloading && !myWeapon->myIsEmpty)
	{
		myWeapon->Shoot();
		PlayAnimationFire();
		if (myWeapon->myMustReload && myWeapon->CanReload())
		{
			Reload();
		}
	}
}

// Called to bind functionality to input
void AOSPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &AOSPlayer::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &AOSPlayer::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &AOSPlayer::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &AOSPlayer::LookUp);

	PlayerInputComponent->BindAction("Sprint", EInputEvent::IE_Pressed, this, &AOSPlayer::StartSprint);

	PlayerInputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &AOSPlayer::StartFire);
	PlayerInputComponent->BindAction("Fire", EInputEvent::IE_Released, this, &AOSPlayer::StopFire);

	PlayerInputComponent->BindAction("Reload", EInputEvent::IE_Pressed, this, &AOSPlayer::Reload);

	PlayerInputComponent->BindAction("Action", EInputEvent::IE_Pressed, this, &AOSPlayer::UseInteractable);
}

void AOSPlayer::MoveForward(float aValue)
{
	if ((Controller != NULL) && (aValue != 0.0f))
	{
		myMovementForward = aValue;

		if (aValue < 0)
			StopSprint();

		//Find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();
		//limit pitch when walking or falling
		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
		{
			Rotation.Pitch = 0.0f;
		}

		//add movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, aValue);
	}
	else
	{
		myMovementForward = 0;
	}
}

void AOSPlayer::MoveRight(float aValue)
{
	if ((Controller != NULL) && (aValue != 0.0f))
	{
		myMovementRight = aValue;

		StopSprint();

		//Find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();
		//add movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, aValue);
	}
	else
	{
		myMovementRight = 0;
	}
}

void AOSPlayer::Turn(float aValue)
{
	AddControllerYawInput(aValue);
}

void AOSPlayer::LookUp(float aValue)
{
	if (aValue == 0)
		return;

	if (myCurrentPitchAngle + aValue > 89 || myCurrentPitchAngle + aValue < -89)
		return;

	myCurrentPitchAngle += aValue;
	FVector newRot = FVector(myCurrentPitchAngle, 0, -90);
	GetMesh()->SetRelativeRotation(FRotator::MakeFromEuler(newRot));
}

void AOSPlayer::StartSprint()
{
	myMovementType = MovementType::SPRINTING;
	ChangedMovementType();
}

void AOSPlayer::StopSprint()
{
	if (myMovementType != MovementType::SPRINTING)
		return;

	SetAnimationSprint(false);
	myMovementType = MovementType::RUNNING;
	ChangedMovementType();
}

void AOSPlayer::ChangedMovementType()
{
	switch (myMovementType)
	{
		case MovementType::RUNNING:
		{
			GetCharacterMovement()->MaxWalkSpeed = myBaseSpeed;
			break;
		}

		case MovementType::SPRINTING:
		{
			SetAnimationSprint(true);
			GetCharacterMovement()->MaxWalkSpeed = myBaseSpeed * mySprintRatio;
			break;
		}

		case MovementType::WALKING:
		{
			GetCharacterMovement()->MaxWalkSpeed = myBaseSpeed * myWalkRatio;
			break;
		}
	}
}

void AOSPlayer::StartFire()
{
	StopSprint();
	myWantToShoot = true;
}

void AOSPlayer::StopFire()
{
	myWantToShoot = false;
}

void AOSPlayer::Reload()
{
	if (myWeapon != nullptr && !myWeapon->myIsReloading && !myWeapon->myIsEmpty && myWeapon->CanReload())
	{
		myWeapon->myIsReloading = true;
		StopSprint();
		PlayAnimationReload();
	}
}

void AOSPlayer::RaycastInFront()
{
	FHitResult OutHit;
	FVector Start = myCameraComponent->GetComponentLocation();

	FVector ForwardVector = myCameraComponent->GetForwardVector();
	FVector End = ((ForwardVector * myRaycastLength) + Start);
	FCollisionQueryParams CollisionParams;

	if (GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParams))
	{
		if (OutHit.Actor == nullptr)
		{
			ShowInteractUI("");
			myLastUsableEntity = nullptr;
			return;
		}
		
		AOSUsableEntity* entity = Cast<AOSUsableEntity>(OutHit.Actor);
		if (entity != nullptr)
		{
			ShowInteractUI(entity->GetInteractionText());
			myLastUsableEntity = entity;
		}
		else
		{
			myLastUsableEntity = nullptr;
			ShowInteractUI("");
		}
	}
	else
	{
		myLastUsableEntity = nullptr;
		ShowInteractUI("");
	}
}

void AOSPlayer::UseInteractable()
{
	if (myLastUsableEntity == nullptr)
		return;

	UE_LOG(LogTemp, Warning, TEXT("Interacting with %s"), *myLastUsableEntity->myName);
	myLastUsableEntity->Interact();
}