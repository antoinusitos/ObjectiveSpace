// Fill out your copyright notice in the Description page of Project Settings.

#include "OSTriggerEvent_Tuto.h"
#include "OSPlayer.h"

AOSTriggerEvent_Tuto::AOSTriggerEvent_Tuto()
{
	myNumberOfUse = 1;
}

void AOSTriggerEvent_Tuto::OnEnterEvent(AActor* anActor)
{
	AOSPlayer* player = Cast<AOSPlayer>(anActor);
	if (player != nullptr)
	{
		player->ShowTutoHint(myHintToShow, myDelayToShow);
	}
}