// Fill out your copyright notice in the Description page of Project Settings.

#include "OSData.h"

// Sets default values
AOSData::AOSData()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

const FItemInfo AOSData::GetItemInfoWithID(int anID)
{
	for (int i = 0; i < myAllItems.Num(); i++)
	{
		if (myAllItems[i].myID == anID)
		{
			return myAllItems[i];
		}
	}

	return FItemInfo();
}