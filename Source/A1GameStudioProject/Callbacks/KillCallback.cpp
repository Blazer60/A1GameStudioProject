// Fill out your copyright notice in the Description page of Project Settings.


#include "KillCallback.h"


UKillCallback::UKillCallback()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UKillCallback::Broadcast(const FVector& Location, const int Money)
{
	Broadcast_Impl(Location, Money);
}

int UKillCallback::Subscribe(const FOnKillSignature& Callback)
{
	const auto Lambda = [=](const FVector &Location, const int Money)
	{
		Callback.ExecuteIfBound(Location, Money);
	};
	return Subscribe_Impl(std::move(Lambda));
}

void UKillCallback::Unsubscribe(const int Token)
{
	Unsubscribe_Impl(Token);
}
