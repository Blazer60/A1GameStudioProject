// Fill out your copyright notice in the Description page of Project Settings.


#include "SceneDirector.h"
#include "A1GameStudioProject/Chest.h"
#include "A1GameStudioProject/WorldItem.h"

void ASceneDirector::PopulateWorld()
{
	for (int i = 0; i < ChestSpawnAmount; ++i)
		SpawnChest(ChestClass);
}
