// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Common.h"
#include "GameFramework/Actor.h"
#include "Chest.generated.h"

UCLASS()
class A1GAMESTUDIOPROJECT_API AChest
	: public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Item)
	TSubclassOf<class AWorldItem> Item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Item)
	TEnumAsByte<ERarity> Rarity { Common };

	UFUNCTION(BlueprintCallable)
	void Setup(TSubclassOf<AWorldItem> NewItem, TEnumAsByte<ERarity> NewRarity);
};
