// Fill out your copyright notice in the Description page of Project Settings.


#include "Chest.h"
#include "A1GameStudioProject/WorldItem.h"

void AChest::Setup(const TSubclassOf<AWorldItem> NewItem, const TEnumAsByte<ERarity> NewRarity)
{
	Item	= NewItem;
	Rarity	= NewRarity;
}
