// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemComponent.h"

#include "A1GameStudioProject/ItemOwner.h"

UItemComponent::UItemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UItemComponent::BeginPlay()
{
	Super::BeginPlay();
}

UItemOwner* UItemComponent::Owner()
{
	auto *Owner = GetOwner();
	return Owner->FindComponentByClass<UItemOwner>();
}

UItemOwner* UItemComponent::ItemOwner() const
{
	const auto * const Owner = GetOwner();
	return Owner->FindComponentByClass<UItemOwner>();
}

void UItemComponent::Attach(int NewCount)
{
	Count = NewCount;
	OnAttach();
}

void UItemComponent::Increase(int Quantity)
{
	Count += Quantity;
	OnIncrease();
}

void UItemComponent::Decrease(int Quantity)
{
	Count = fmax(Count - Quantity, 0);
	OnDecrease();
	if (Count <= 0)
	{
		OnDetach();
		DestroyComponent();
	}
}

