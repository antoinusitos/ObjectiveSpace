// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OSData.h"
#include "OSQuestComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OBJECTIVE_SPACE_API UOSQuestComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOSQuestComponent();

public:
	void UsedItem(int anID);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	TArray<FQuestInfo> myQuests;
};
