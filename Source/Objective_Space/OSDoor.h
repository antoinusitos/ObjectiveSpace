// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OSStaticEntity.h"
#include "OSDoor.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTIVE_SPACE_API AOSDoor : public AOSStaticEntity
{
	GENERATED_BODY()

public:
	virtual void Interact() override;

	virtual const FString GetInteractionText();

	virtual void PostAnimation() override;

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = OS)
	bool myIsOpen = false;
	bool myIsOpening = false;
};
