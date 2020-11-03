// Fill out your copyright notice in the Description page of Project Settings.

#include "OSDoor.h"

const FString AOSDoor::GetInteractionText()
{
	return FString("Open Door");
}

void AOSDoor::Interact()
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