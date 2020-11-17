// Fill out your copyright notice in the Description page of Project Settings.

#include "OSDoor.h"
#include "OSPlayer.h"

const FString AOSDoor::GetInteractionText()
{
	if (myIsLocked)
	{
		return FString("Door is locked");
	}
	else if (!myOpenByHand)
	{
		return FString("");
	}

	return FString("Open Door");
}

void AOSDoor::Interact(AOSPlayer* aPlayer)
{
	if (aPlayer != nullptr && !myOpenByHand)
		return;

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
	myIsOpen = !myIsOpen;
}

void AOSDoor::PostAnimation()
{
	myIsOpening = false;
}