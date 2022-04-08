// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayState.h"

#include "SceneDirector.h"
#include "SpawnDirector.h"

AGameplayState::AGameplayState()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGameplayState::BeginPlay()
{
	Super::BeginPlay();
	auto *World = GetWorld();
	World->SpawnActor<ASpawnDirector>(SpawnDirectorClass);
	auto *SceneDirector = World->SpawnActor<ASceneDirector>(SceneDirectorClass);
	SceneDirector->PopulateWorld();
}

void AGameplayState::Tick(const float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
}
