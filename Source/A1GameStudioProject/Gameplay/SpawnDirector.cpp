// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnDirector.h"
#include "Details/Details.h"

ASpawnDirector::ASpawnDirector()
{
	PrimaryActorTick.bCanEverTick = true;
}

int ASpawnDirector::EnemyLevel() const
{
	const float Level = (1.f / Alpha) * FMath::Pow(0.016f * GetGameTimeSinceCreation(), Beta) + 1.f;
	return FMath::FloorToInt(Level);	
}

float ASpawnDirector::GetCostOf(const UEnemyDetails* EnemyDetails) const
{
	return EnemyLevel() * EnemyDetails->GroupSize * EnemyDetails->Cost;	
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
	Enemy = Enemies[RandomIndex];
	NextSpawnCost = GetCostOf(Enemy);	
}

void ASpawnDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Credits += 2.f * DeltaTime * EnemyLevel();
	if (Credits >= NextSpawnCost)
	{
		Credits -= NextSpawnCost;
		if (Enemy)
			SpawnEnemy(Enemy);
		RollNewEnemy();
	}
}

