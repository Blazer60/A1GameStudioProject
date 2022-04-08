// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerOwner.h"


UPlayerOwner::UPlayerOwner()
	: UItemOwner()
{
}

void UPlayerOwner::OnKill(const FVector& Location, const int Money)
{
	Credits += Money;
	Super::OnKill(Location, Money);
}
