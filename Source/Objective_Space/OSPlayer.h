// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "OSPlayer.generated.h"

class USkeletalMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class AOSWeapon;
class UChildActorComponent;
class AOSUsableEntity;

UENUM()
enum MovementType
{
	WALKING     UMETA(DisplayName = "WALKING"),
	RUNNING     UMETA(DisplayName = "RUNNING"),
	SPRINTING   UMETA(DisplayName = "SPRINTING"),
	CROUCHING   UMETA(DisplayName = "CROUCHING"),
	STOP		UMETA(DisplayName = "STOP"),
};

UCLASS()
class OBJECTIVE_SPACE_API AOSPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AOSPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	  void MoveForward(float aValue);

	  void MoveRight(float aValue);

	  void Turn(float aValue);

	  void LookUp(float aValue);

	  void StartSprint();
	  void StopSprint();

	  void ChangedMovementType();

	  void StartFire();
	  void StopFire();

	  void Reload();

//Link to blueprint
public:
	UFUNCTION(BlueprintImplementableEvent, Category = OS)
	void SetAnimationSprint(bool aNewState);

	UFUNCTION(BlueprintImplementableEvent, Category = OS)
	void PlayAnimationFire();

	UFUNCTION(BlueprintImplementableEvent, Category = OS)
	void SpawnUI();

	UFUNCTION(BlueprintImplementableEvent, Category = OS)
	void PlayAnimationReload();

	UFUNCTION(BlueprintImplementableEvent, Category = OS)
	void ShowInteractUI(bool aNewState);

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = OS)
	USkeletalMeshComponent* myArmMesh = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = OS)
	USkeletalMeshComponent* myWeaponMesh = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = OS)
	USpringArmComponent* mySpringArmComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = OS)
	UCameraComponent* myCameraComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = OS)
	UChildActorComponent* myChildActorComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	float myBaseSpeed = 600;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	float myWalkRatio = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	float myCrouchRatio = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	float mySprintRatio = 1.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	float myRaycastLength = 1000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PCK)
	TSubclassOf<AOSWeapon> myWeaponToSpawn;

private:
	void RaycastInFront();

	void UseInteractable();

private:
	float myCurrentPitchAngle = 0;

	MovementType myMovementType = MovementType::RUNNING;

	float myMovementForward = 0;
	float myMovementRight = 0;

	AOSWeapon* myWeapon = nullptr;

	bool myWantToShoot = false;

	AOSUsableEntity* myLastUsableEntity = nullptr;
};
