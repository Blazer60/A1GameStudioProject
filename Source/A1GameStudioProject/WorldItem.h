// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Common.h"
#include "WorldItem.generated.h"

UCLASS(Blueprintable, BlueprintType)
class A1GAMESTUDIOPROJECT_API AWorldItem
	: public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Item)
	TEnumAsByte<ERarity> Rarity { Common };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Item)
	TSubclassOf<class UItemComponent> Item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Item)
	int32 Quantity { 1 };
};
