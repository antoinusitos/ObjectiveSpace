// Fill out your copyright notice in the Description page of Project Settings.

#include "OSInterruptor.h"
#include "OSUsableEntity.h"

const FString AOSInterruptor::GetInteractionText()
{
	if (myIsLocked)
	{
		return FString("Interruptor is locked");
	}

	return FString("Use Interruptor");
}

void AOSInterruptor::Interact(AOSPlayer* aPlayer)
{
	if (myIsOpening)
		return;

	if (myNumberOfUse == 0)
		return;
	else if (myNumberOfUse > 0)
	{
		myNumberOfUse--;
	}

	myIsOpening = true;
	PlayAnimation();
}

void AOSInterruptor::PostAnimation()
{
	myIsOpening = false;
	if (myUsableEntity != nullptr)
	{
		myUsableEntity->Interact(nullptr);
	}
}