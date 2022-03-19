// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemOwner.h"
#include "ItemComponent.h"


UItemOwner::UItemOwner()
{
	PrimaryComponentTick.bCanEverTick = true;
}

UItemComponent* UItemOwner::AddItem(TSubclassOf<UItemComponent> ItemClass)
{
	// auto *ItemPtr = NewObject<UItemComponent>(ItemClass);
	// Items.Emplace(ItemPtr);
	// GetOwner()->AddOwnedComponent(ItemPtr);
	// GetOwner()->CreateDefaultSubobject<UItemComponent, ItemClass>(FName("Item"));
	// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Successfully Created Item");
	// return ItemPtr;
	
	
	// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Failed to get Owner");
	return nullptr;
}

