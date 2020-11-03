// Fill out your copyright notice in the Description page of Project Settings.

#include "OSPickup.h"
#include "Components/StaticMeshComponent.h"

AOSPickup::AOSPickup()
{
	myMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	//myMesh->SetupAttachment();
}

const FString AOSPickup::GetInteractionText()
{
	return FString("Pick up " + myName);
}