// Fill out your copyright notice in the Description page of Project Settings.

#include "OSWeapon.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AOSWeapon::AOSWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	myWeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
}

// Called when the game starts or when spawned
void AOSWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOSWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(!myCanShoot)
	{
		myCurrentRate += DeltaTime;
		if (myCurrentRate >= myFireRate)
		{
			myCurrentRate = 0;
			myCanShoot = true;
		}
	}
}

void AOSWeapon::Shoot()
{
	myCanShoot = false;
	myBullets--;
	if (myBullets == 0)
	{
		myMustReload = true;
	}
}

bool AOSWeapon::CanReload()
{
	if (myBullets == myBulletsInMagazine)
		return false;

	if (myBulletInStock == 0)
	{
		myIsEmpty = true;
		return false;
	}

	if (myIsReloading)
		return false;

	return true;
}

void AOSWeapon::Reload()
{
	myMustReload = false;
	myIsReloading = false;

	int diff = myBulletsInMagazine - myBullets;

	if (diff > myBulletInStock)
	{
		myBullets += myBulletInStock;
		myBulletInStock = 0;
	}
	else
	{
		myBullets += diff;
		myBulletInStock -= diff;
	}
}

void AOSWeapon::ShowMesh(bool aNewState)
{
	myWeaponMesh->SetVisibility(aNewState);
}