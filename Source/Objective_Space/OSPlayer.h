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
class UOSInventoryComponent;
class UOSQuestComponent;

UENUM()
enum EMovementType
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

	  void Holster();

	  UFUNCTION(BlueprintCallable, BlueprintPure, Category = OS)
	  const bool GetWeaponIsHolstered();

	  void SetWeapon(AOSWeapon* aWeapon);

	  void UpdateWeaponUI();

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
	void ShowInteractUI(const FString& aText);

	UFUNCTION(BlueprintImplementableEvent, Category = OS)
	void HolsterWeapon(bool aNewState);

	UFUNCTION(BlueprintImplementableEvent, Category = OS)
	void BPUpdateWeaponUI();

	UFUNCTION(BlueprintImplementableEvent, Category = OS)
	void ShowTutoHint(const FString& aHintToShow, float aDelayToShow);

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
	UOSInventoryComponent* myInventoryComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	UOSQuestComponent* myQuestComponent = nullptr;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	TSubclassOf<AOSWeapon> myWeaponToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	bool myIsSwitchingWeapon = false;

private:
	void RaycastInFront();

	void UseInteractable();

private:
	float myCurrentPitchAngle = 0;

	TEnumAsByte<EMovementType> myMovementType = EMovementType::RUNNING;

	float myMovementForward = 0;
	float myMovementRight = 0;

	AOSWeapon* myWeapon = nullptr;

	bool myWantToShoot = false;

	bool myWeaponIsHolstered = false;

	AOSUsableEntity* myLastUsableEntity = nullptr;
};
