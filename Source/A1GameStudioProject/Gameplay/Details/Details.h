// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Details.generated.h"


UCLASS(Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew)
class A1GAMESTUDIOPROJECT_API UDetails
	: public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Cost		{ 10 };
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoneyBack { 0.2f };
};

UCLASS()
class UEnemyDetails
	: public UDetails
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ToSpawn;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 GroupSize { 1 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Spawning)
	float MinRange { 0.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Spawning)
	float MaxRange { 0.f };

	/** How close enemies should spawn next to each other. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Spawning)
	float GroupCoherence { 0.f };
};

UCLASS()
class UItemDetails
	: public UDetails
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UItemComponent> ToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Quantity { 1 };
};
