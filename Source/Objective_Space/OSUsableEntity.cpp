// Fill out your copyright notice in the Description page of Project Settings.

#include "OSUsableEntity.h"
#include "OSPlayer.h"

// Sets default values
AOSUsableEntity::AOSUsableEntity()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOSUsableEntity::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOSUsableEntity::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

const FString AOSUsableEntity::GetInteractionText()
{
	return "";
}

void AOSUsableEntity::Interact(AOSPlayer* aPlayer)
{
}