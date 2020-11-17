// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OSStaticEntity.h"
#include "OSInterruptor.generated.h"

class AOSUsableEntity;

UCLASS()
class OBJECTIVE_SPACE_API AOSInterruptor : public AOSStaticEntity
{
	GENERATED_BODY()
	
public:
	virtual void Interact(AOSPlayer* aPlayer) override;

	virtual const FString GetInteractionText();

	virtual void PostAnimation() override;

public:
	bool myIsOpening = false;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = OS)
	bool myIsLocked = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = OS)
	AOSUsableEntity* myUsableEntity = nullptr;
};
