// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OSTriggerEvent.h"
#include "OSTriggerEvent_Tuto.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTIVE_SPACE_API AOSTriggerEvent_Tuto : public AOSTriggerEvent
{
	GENERATED_BODY()

public:
	AOSTriggerEvent_Tuto();

public:
	virtual void OnEnterEvent(AActor* anActor) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	float myDelayToShow = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	FString myHintToShow = "";
	
};
