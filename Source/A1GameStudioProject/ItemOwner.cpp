// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemOwner.h"

#include "Callbacks/HitCallback.h"
#include "Callbacks/HurtCallback.h"
#include "ItemComponent.h"


UItemOwner::UItemOwner()
{
	PrimaryComponentTick.bCanEverTick = true;
}

UItemComponent* UItemOwner::AddItem(TSubclassOf<UItemComponent> ItemClass)
{
	auto *const Actor = GetOwner();
	auto *const Item = NewObject<UItemComponent>(Actor, ItemClass);

	if (Item)
	{
		Actor->AddOwnedComponent(Item);
		Item->RegisterComponent();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Successfully Created Item");
	}
	
	return Item;
}

void UItemOwner::OnHit(UItemOwner *Target, const float ProcRate, const float Damage, const FVector HitLocation) const
{
	if (HitCallback)
		HitCallback->Broadcast(Target, ProcRate, Damage, HitLocation);
}

void UItemOwner::OnHurt(UItemOwner* By, float Damage)
{
	if (HurtCallback)
		HurtCallback->Broadcast(By, Damage);
	
	Health -= Damage;
	if (Health <= 0.f)
	{
		OnDeath(By, Damage);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, "Item Owner has died.");
		GetOwner()->Destroy();
	}
}

void UItemOwner::OnKill(const FVector& Location, const int Money) const
{
	if (KillCallback)
		KillCallback->Broadcast(Location, Money);
}

void UItemOwner::BeginPlay()
{
	Super::BeginPlay();
	auto *Owner = GetOwner();
	HitCallback  = Owner->FindComponentByClass<UHitCallback>();
	HurtCallback = Owner->FindComponentByClass<UHurtCallback>();
	KillCallback = Owner->FindComponentByClass<UKillCallback>();
	if (!HitCallback)
		Warn("Hit Callback");
	if (!HurtCallback)
		Warn("Hurt Callback");
	if (!KillCallback)
		Warn("Kill Callback");
}

void UItemOwner::Warn(const FString &Item) const
{
	const auto ActorName = GetOwner()->GetName();
	const FString Out = Item + " has not been added to " + ActorName;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, Out);
}

