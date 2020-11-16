// Fill out your copyright notice in the Description page of Project Settings.

#include "OSDoor.h"
#include "OSPlayer.h"

const FString AOSDoor::GetInteractionText()
{
	return FString("Open Door");
}

void AOSDoor::Interact(AOSPlayer* aPlayer)
{
	if (myIsOpening)
		return;

	myIsOpening = true;
	PlayAnimation();
	myIsOpen = !myIsOpen;
}

void AOSDoor::PostAnimation()
{
	myIsOpening = false;
}