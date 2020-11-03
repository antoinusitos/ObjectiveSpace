// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OSUsableEntity.generated.h"

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

public:
	virtual const FString GetInteractionText();

	virtual void Interact();
};
