// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerOwner.h"

#include "A1GameStudioProject/Callbacks/HurtCallback.h"


UPlayerOwner::UPlayerOwner()
	: UItemOwner()
{
}

void UPlayerOwner::OnKill(const FVector& Location, const int Money)
{
	Credits += Money;
	Super::OnKill(Location, Money);
}

void UPlayerOwner::OnHurt(UItemOwner* By, const float Damage)
{
	if (HurtCallback)
		HurtCallback->Broadcast(By, Damage);
	
	Health -= Damage;
	if (Health <= 0.f)
	{
		OnDeath(By, Damage);
	}
}
