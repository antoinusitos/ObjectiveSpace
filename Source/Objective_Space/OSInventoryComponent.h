// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OSData.h"
#include "OSInventoryComponent.generated.h"

class AOSPickup;
class AOSPlayer;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OBJECTIVE_SPACE_API UOSInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOSInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	AOSData* myData = nullptr;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SpawnParams)
	int myGold = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SpawnParams)
	int myBullets = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SpawnParams)
	TArray<FInventoryInfo> myInventory;

	//Item that cannot be sold or removed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SpawnParams)
	TArray<FInventoryInfo> myQuestInventory;

	AOSPlayer* myOwner = nullptr;

public:
	void EquipItem(AOSPickup* aPickup);

	void PickupItem(AOSPickup* aPickup);
};
