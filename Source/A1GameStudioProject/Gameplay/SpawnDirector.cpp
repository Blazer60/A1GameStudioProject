// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnDirector.h"
#include "Details/Details.h"

ASpawnDirector::ASpawnDirector()
{
	PrimaryActorTick.bCanEverTick = true;
}

int ASpawnDirector::EnemyLevel() const
{
	const float Level = (1.f / Alpha) * FMath::Pow(0.016f * GetGameTimeSinceCreation() + TimeOffset, Beta) + 1.f;
	return FMath::FloorToInt(Level);	
}

float ASpawnDirector::GetCostOfEnemy(const UEnemyDetails* EnemyDetails) const
{
	return EnemyLevel() * EnemyDetails->GroupSize * EnemyDetails->Cost;	
}

float ASpawnDirector::GetCostOfItem(const UItemDetails* ItemDetails) const
{
	return ItemDetails->Cost * ItemDetails->Quantity;
}

int32 ASpawnDirector::GetItemCount() const
{
	return FMath::FloorToInt(0.5f * EnemyLevel());
}

FVector ASpawnDirector::GetRandomPointInZone(const float Min, const float Max)
{
	FVector2D Point = { FMath::FRand(), FMath::FRand() };
	Point.Normalize();
	const float Scalar = FMath::FRandRange(Min, Max);
	Point *= Scalar;
	return { Point.X, Point.Y, 0.f }; 
}

void ASpawnDirector::BeginPlay()
{
	Super::BeginPlay();
    RollNewEnemy();
}

void ASpawnDirector::RollNewEnemy()
{
	if (Enemies.Num() <= 0)
		return;
	const int32 RandomIndex = FMath::RandRange(0, Enemies.Num() - 1);
	EnemyToSpawn = Enemies[RandomIndex];
	NextSpawnCost = GetCostOfEnemy(EnemyToSpawn);
	
	if (Items.Num() <= 0)
		return;

	const int32 ItemCount = GetItemCount();
    ItemsToSpawn.Empty();
    ItemsToSpawn.Reserve(ItemCount);
	
	for (int i = 0; i < ItemCount; ++i)
	{
		const int32 RandomINT32 = FMath::RandRange(0, Items.Num() - 1);
		auto *const Item = Items[RandomINT32];
		ItemsToSpawn.Add(Item);
		NextSpawnCost += GetCostOfItem(Item);
	}
}

void ASpawnDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Credits += 2.f * DeltaTime * EnemyLevel();
	if (Credits >= NextSpawnCost)
	{
		Credits -= NextSpawnCost;
		if (EnemyToSpawn)
			SpawnEnemy(EnemyToSpawn, ItemsToSpawn);
		RollNewEnemy();
	}
}

