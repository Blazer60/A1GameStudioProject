// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SceneDirector.generated.h"

class AChest;

/** Responsible for spawning intractable items within the world. */
UCLASS()
class A1GAMESTUDIOPROJECT_API ASceneDirector
	: public AActor
{
	GENERATED_BODY()
public:
	void PopulateWorld();

	UFUNCTION(BlueprintImplementableEvent)
	void SpawnChest(TSubclassOf<AChest> Chest);
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Chests)
	TSubclassOf<AChest> ChestClass;

	UPROPERTY(EditAnywhere, Category=Chests)
	int32 ChestSpawnAmount { 30 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category=Items)
	TArray<class UItemDetails*> Items;
};
