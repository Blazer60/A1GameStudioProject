// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemComponent.h"

UItemComponent::UItemComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UItemComponent::BeginPlay()
{
	Super::BeginPlay();
}

