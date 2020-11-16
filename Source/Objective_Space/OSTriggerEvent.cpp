// Fill out your copyright notice in the Description page of Project Settings.

#include "OSTriggerEvent.h"
#include "Components/BoxComponent.h"
#include "OSPlayer.h"

// Sets default values
AOSTriggerEvent::AOSTriggerEvent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	myBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
}

// Called when the game starts or when spawned
void AOSTriggerEvent::BeginPlay()
{
	Super::BeginPlay();
	
	myBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AOSTriggerEvent::OnOverlapBegin);
}

// Called every frame
void AOSTriggerEvent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOSTriggerEvent::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (myNumberOfUse == 0)
		return;
	else if (myNumberOfUse > 0)
	{
		myNumberOfUse--;
	}

	if (myUsePlayer)
	{
		AOSPlayer* player = Cast<AOSPlayer>(OtherActor);
		if (player != nullptr)
		{
			OnEnterEvent(player);
		}
	}
	else if (myActorToCast != nullptr && myActorToCast == OtherActor)
	{
		OnEnterEvent(OtherActor);
	}

	if (myNumberOfUse == 0 && myDestroyAfterUse)
	{
		Destroy();
	}
}

void AOSTriggerEvent::OnEnterEvent(AActor* anActor)
{
	UE_LOG(LogTemp, Warning, TEXT("an actor overlap"));
}