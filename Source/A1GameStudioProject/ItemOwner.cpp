// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemOwner.h"

#include "HitCallback.h"
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

void UItemOwner::OnHit(UItemOwner *Target, const float ProcRate, const float Damage, const FVector HitLocation) const
{
	if (HitCallback)
		HitCallback->Broadcast(Target, ProcRate, Damage, HitLocation);
}

void UItemOwner::BeginPlay()
{
	Super::BeginPlay();
	auto *Owner = GetOwner();
	HitCallback = Owner->FindComponentByClass<UHitCallback>();
	if (!HitCallback)
		Warn("Hit Callback");
}

void UItemOwner::Warn(const FString &Item) const
{
	const auto ActorName = GetOwner()->GetName();
	const FString Out = Item + " has not been added to " + ActorName;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, Out);
}

