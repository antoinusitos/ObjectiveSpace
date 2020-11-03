// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OSUsableEntity.h"
#include "OSStaticEntity.generated.h"

class AOSPlayer;

/**
 * 
 */
UCLASS()
class OBJECTIVE_SPACE_API AOSStaticEntity : public AOSUsableEntity
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent, Category = OS)
	void PlayAnimation();

	UFUNCTION(BlueprintImplementableEvent, Category = OS)
	void BlueprintPostAnimation();

public:
	UFUNCTION(BlueprintCallable, Category = OS)
	virtual void PostAnimation();

	virtual void Interact(AOSPlayer* aPlayer) override;
};
