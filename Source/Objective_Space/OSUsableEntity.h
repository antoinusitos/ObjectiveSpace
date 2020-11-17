// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OSUsableEntity.generated.h"

class AOSPlayer;

UCLASS()
class OBJECTIVE_SPACE_API AOSUsableEntity : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOSUsableEntity();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	FString myName = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	int myID = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	int myNumberOfUse = -1;

public:
	virtual const FString GetInteractionText();

	virtual void Interact(AOSPlayer* aPlayer);
};
