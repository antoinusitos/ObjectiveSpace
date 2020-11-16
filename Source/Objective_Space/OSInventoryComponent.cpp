// Fill out your copyright notice in the Description page of Project Settings.

#include "OSInventoryComponent.h"
#include "OSPickup.h"
#include "EngineUtils.h"

// Sets default values for this component's properties
UOSInventoryComponent::UOSInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UOSInventoryComponent::BeginPlay()
{
	
}

// Called every frame
void UOSInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{

}

void UOSInventoryComponent::EquipItem(AOSPickup* aPickup)
{
	if (aPickup == nullptr)
		return;

	if (myData == nullptr)
	{
		for (TActorIterator<AOSData> It(GetWorld()); It; ++It)
		{
			myData = *It;
		}
	}

	FItemInfo itemInfo = myData->GetItemInfoWithID(aPickup->myID);

	switch (itemInfo.myPickupType)
	{
		case EPickupType::WEAPON:
		{
			aPickup->Interact(myOwner);
			break;
		}
	}
}

void UOSInventoryComponent::PickupItem(AOSPickup* aPickup)
{
	if (aPickup == nullptr)
		return;

	if (myData == nullptr)
	{
		for (TActorIterator<AOSData> It(GetWorld()); It; ++It)
		{
			myData = *It;
		}
	}

	FItemInfo itemInfo = myData->GetItemInfoWithID(aPickup->myID);

	switch (itemInfo.myPickupType)
	{
		case EPickupType::QUEST:
		{
			FInventoryInfo info = FInventoryInfo();
			info.myID = aPickup->myID;
			info.myQuantity = 1;
			myQuestInventory.Add(info);
			break;
		}
		case EPickupType::WEAPON:
		{
			FInventoryInfo info = FInventoryInfo();
			info.myID = aPickup->myID;
			info.myQuantity = 1;
			myInventory.Add(info);
			EquipItem(aPickup);
			break;
		}
	}

	aPickup->Destroy();
}