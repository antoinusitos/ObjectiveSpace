// Fill out your copyright notice in the Description page of Project Settings.

#include "OSWeaponSpawner.h"
#include "OSPlayer.h"
#include "OSWeapon.h"

void AOSWeaponSpawner::Interact(AOSPlayer* aPlayer)
{
	if (myWeaponToGive != nullptr && aPlayer->myChildActorComponent != nullptr)
	{
		aPlayer->myChildActorComponent->SetChildActorClass(*myWeaponToGive);
		aPlayer->myChildActorComponent->CreateChildActor();
		aPlayer->SetWeapon(Cast<AOSWeapon>(aPlayer->myChildActorComponent->GetChildActor()));
		if (aPlayer->GetWeaponIsHolstered())
		{
			aPlayer->Holster();
			aPlayer->UpdateWeaponUI();
		}
	}
}