// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpawnDirector.h"
#include "GameFramework/GameStateBase.h"
#include "GameplayState.generated.h"


/**
 * 
 */
UCLASS()
class A1GAMESTUDIOPROJECT_API AGameplayState
	: public AGameStateBase
{
	GENERATED_BODY()
public:
	AGameplayState();

	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<ASpawnDirector> SpawnDirectorClass;
protected:
	virtual void Tick(float DeltaSeconds) override;

	
	// UPROPERTY()
	// ASpawnDirector* SpawnDirector;
};
