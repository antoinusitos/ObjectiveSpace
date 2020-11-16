// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OSUsableEntity.h"
#include "OSPickup.generated.h"

class UStaticMeshComponent;

/**
 * 
 */
UCLASS()
class OBJECTIVE_SPACE_API AOSPickup : public AOSUsableEntity
{
	GENERATED_BODY()

public:
	AOSPickup();
	
	virtual const FString GetInteractionText() override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = OS)
	UStaticMeshComponent* myMesh = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	int myID = -1;
};
