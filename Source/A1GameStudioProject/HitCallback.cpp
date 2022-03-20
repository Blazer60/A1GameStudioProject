// Fill out your copyright notice in the Description page of Project Settings.


#include "HitCallback.h"


UHitCallback::UHitCallback()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UHitCallback::Broadcast(UItemOwner* Target, const float ProcRate, const float Damage, const FVector HitLocation)
{
	Broadcast_Impl(Target, ProcRate, Damage, HitLocation);
}

int UHitCallback::Subscribe(const FOnHitSignature& Callback)
{
	const auto Lambda = [=](UItemOwner* Target, const float ProcRate, const float Damage, const FVector HitLocation)
	{
		Callback.ExecuteIfBound(Target, ProcRate, Damage, HitLocation);
	};
	return Subscribe_Impl(std::move(Lambda));
}

void UHitCallback::Unsubscribe(const int Token)
{
	Unsubscribe_Impl(Token);
}

