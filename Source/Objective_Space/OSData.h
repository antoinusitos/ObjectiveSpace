// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OSData.generated.h"

class AOSPickup;

UENUM()
enum EPickupType
{
	WEAPON		UMETA(DisplayName = "WEAPON"),
	AMMO		UMETA(DisplayName = "AMMO"),
	QUEST		UMETA(DisplayName = "QUEST"),
	OTHER		UMETA(DisplayName = "OTHER"),
};

USTRUCT(BlueprintType)
struct FInventoryInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	int myID = -1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	int myQuantity = 1;
};

USTRUCT(BlueprintType)
struct FItemInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	int myID = -1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	FString myName = "";
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	TSubclassOf<AOSPickup> myObject;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	UTexture2D* myIcon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	int myWeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	TEnumAsByte<EPickupType> myPickupType;
};

UCLASS()
class OBJECTIVE_SPACE_API AOSData : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOSData();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OS)
	TArray<FItemInfo> myAllItems;

public:
	const FItemInfo GetItemInfoWithID(int anID);
};
