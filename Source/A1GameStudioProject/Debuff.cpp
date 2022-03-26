// Fill out your copyright notice in the Description page of Project Settings.


#include "Debuff.h"
#include "ItemComponent.h"

UDebuff::UDebuff()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UDebuff::TickComponent(
	float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	Timer -= DeltaTime;
	if (Timer <= 0)
	{
		Timer += 1.f;
		Decrease();
	}
}

