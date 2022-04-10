// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemOwner.h"

#include "Callbacks/HitCallback.h"
#include "Callbacks/HurtCallback.h"
#include "Projectiles/Projectile.h"
#include "Items/ItemComponent.h"
#include "Kismet/GameplayStatics.h"


UItemOwner::UItemOwner()
{
	PrimaryComponentTick.bCanEverTick = true;
	
	MaxHealth			= CreateDefaultSubobject<UStat>("Max Health");
	Speed				= CreateDefaultSubobject<UStat>("Speed");
	JumpHeight			= CreateDefaultSubobject<UStat>("Jump Height");
	DamageMultiplier	= CreateDefaultSubobject<UStat>("Damage Multiplier");
}

UItemComponent* UItemOwner::AddItem(const TSubclassOf<UItemComponent> ItemClass, const int32 Quantity)
{
	auto *const Actor = GetOwner();
	
	auto *const FoundItem = Cast<UItemComponent>(Actor->FindComponentByClass(ItemClass));
	if (FoundItem)
	{
		FoundItem->Increase(Quantity);
		return FoundItem;
	}
	
	auto *const Item = NewObject<UItemComponent>(Actor, ItemClass);
	if (Item)
	{
		Actor->AddOwnedComponent(Item);
		Item->RegisterComponent();
		Item->Attach(Quantity);
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
		GetOwner()->Destroy();
	}
}

void UItemOwner::OnKill(const FVector& Location, const int Money)
{
	if (KillCallback)
		KillCallback->Broadcast(Location, Money);
}

void UItemOwner::LevelUp(const int32 NewLevel)
{
	Level = NewLevel;
	Health = MaxHealth->IncreaseBase(Level);
	Speed->IncreaseBase(Level);
	JumpHeight->IncreaseBase(Level);
	DamageMultiplier->IncreaseBase(Level);
}

void UItemOwner::SpawnProjectile(const TSubclassOf<AProjectile> Class, const FTransform& Transform)
{
	auto *Projectile = Cast<AProjectile>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, Class, Transform));
	Projectile->SetupProjectile(GetOwner(), this);
	UGameplayStatics::FinishSpawningActor(Projectile, Transform);
}

void UItemOwner::ResetBase() const
{
	MaxHealth->OriginalBase			= MaxHealth->Base;
	Speed->OriginalBase				= Speed->Base;
	JumpHeight->OriginalBase		= JumpHeight->Base;
	DamageMultiplier->OriginalBase	= DamageMultiplier->Base;
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

	ResetBase();
	LevelUp(Level);
}

void UItemOwner::Warn(const FString &Item) const
{
	const auto ActorName = GetOwner()->GetName();
	const FString Out = Item + " has not been added to " + ActorName;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, Out);
}

