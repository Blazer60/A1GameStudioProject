// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Details/Details.h"
#include "GameFramework/Actor.h"
#include "SpawnDirector.generated.h"

class UItemDetails;
class UEnemyDetails;

UCLASS()
class A1GAMESTUDIOPROJECT_API ASpawnDirector
	: public AActor
{
	GENERATED_BODY()
public:
	ASpawnDirector();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure, Category=SpawnDirector)
	int EnemyLevel() const;

	UFUNCTION(BlueprintPure, Category=SpawnDirector)
	float GetCostOfEnemy(const UEnemyDetails *EnemyDetails) const;

	UFUNCTION(BlueprintPure, Category=SpawnDirector)
	float GetCostOfItem(const UItemDetails *ItemDetails) const;

	UFUNCTION(BlueprintPure, Category=SpawnDirector)
	int32 GetItemCount() const;

	UFUNCTION(BlueprintPure, Category=Spawning)
	static FVector GetRandomPointInZone(float Min, float Max);
	
protected:
	virtual void BeginPlay() override;

	/**
	 * Dictates the linear scaling of an enemy's level.
	 */
	UPROPERTY(EditAnywhere, Category=SpawnDirector)
	float Alpha { 8.5f };

	/**
	 * Dictates the exponential scaling of an enemy's level.
	 */
	UPROPERTY(EditAnywhere, Category=SpawnDirector)
	float Beta { 1.47f };

	UPROPERTY(EditAnywhere, Category=SpawnDirector)
	float Credits { 0.f };

	UPROPERTY(EditAnywhere, Instanced, Category=SpawnDirector)
	TArray<UEnemyDetails*> Enemies;

	UPROPERTY(EditAnywhere, Instanced, Category=SpawnDirector)
	TArray<UItemDetails*> Items;

	/** How far into the game should it start (in seconds) */
	UPROPERTY(EditAnywhere, Category=SpawnDirector)
	float TimeOffset { 0.f };
	
	UPROPERTY()
	UEnemyDetails* EnemyToSpawn { nullptr };

	UPROPERTY()
	TArray<UItemDetails*> ItemsToSpawn;
	
	UPROPERTY(EditAnywhere, Category=SpawnDirector)
	float NextSpawnCost { 0.f };
	
	UFUNCTION(BlueprintCallable)
	void RollNewEnemy();

	UFUNCTION(BlueprintImplementableEvent)
	void SpawnEnemy(const UEnemyDetails *EnemyDetails, const TArray<UItemDetails*>& EnemyItems);	
};
