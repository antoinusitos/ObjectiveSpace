// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OSStaticEntity.h"
#include "OSWeaponSpawner.generated.h"

class AOSWeapon;
class AOSPlayer;

/**
 * 
 */
UCLASS()
class OBJECTIVE_SPACE_API AOSWeaponSpawner : public AOSStaticEntity
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = OS)
	TSubclassOf<AOSWeapon> myWeaponToGive;

public:
	virtual void Interact(AOSPlayer* aPlayer) override;
};
