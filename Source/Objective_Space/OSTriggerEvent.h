// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OSTriggerEvent.generated.h"

class UBoxComponent;

UCLASS()
class OBJECTIVE_SPACE_API AOSTriggerEvent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOSTriggerEvent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void OnTriggerEnter(AActor* aEnteringActor);

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = OS)
	UBoxComponent* myBoxComponent = nullptr;

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	bool myUsePlayer = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	bool myDestroyAfterUse = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	AActor* myActorToCast = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	int myNumberOfUse = -1;

public:
	virtual void OnEnterEvent(AActor* anActor);

};
