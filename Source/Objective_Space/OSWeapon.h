// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OSPickup.h"
#include "OSWeapon.generated.h"

class USkeletalMeshComponent;

UCLASS()
class OBJECTIVE_SPACE_API AOSWeapon : public AOSPickup
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOSWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = OS)
	USkeletalMeshComponent* myWeaponMesh = nullptr;

	float myFireRate = 0.13f;
	float myCurrentRate = 0;
	bool myCanShoot = true;
	bool myMustReload = false;

	bool myIsEmpty = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = OS)
	int myBullets = 20;
	int myBulletsInMagazine = 20;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = OS)
	int myBulletInStock = 100;

	bool myIsReloading = false;

public:
	void Shoot();

	bool CanReload();

	UFUNCTION(BlueprintCallable, Category = OS)
	void Reload();

	UFUNCTION(BlueprintCallable, Category = OS)
	void ShowMesh(bool aNewState);

	virtual void Interact(AOSPlayer* aPlayer) override;

	virtual const FString GetInteractionText() override;
};
