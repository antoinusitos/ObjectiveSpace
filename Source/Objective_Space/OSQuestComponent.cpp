// Fill out your copyright notice in the Description page of Project Settings.

#include "OSQuestComponent.h"

// Sets default values for this component's properties
UOSQuestComponent::UOSQuestComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UOSQuestComponent::UsedItem(int anID)
{
	for (int i = 0; i < myQuests.Num(); i++)
	{
		if (myQuests[i].myQuestCompleted)
		{
			continue;
		}

		if (myQuests[i].myActivatedItemID == anID)
		{
			myQuests[i].myQuestCompleted = true;
		}
	}
}