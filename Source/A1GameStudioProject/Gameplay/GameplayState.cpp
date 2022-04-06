// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayState.h"

#include "SpawnDirector.h"

AGameplayState::AGameplayState()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGameplayState::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->SpawnActor<ASpawnDirector>(SpawnDirectorClass);
}

void AGameplayState::Tick(const float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
}
