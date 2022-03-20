// Fill out your copyright notice in the Description page of Project Settings.


#include "HurtCallback.h"


UHurtCallback::UHurtCallback()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UHurtCallback::Broadcast(UItemOwner* HurtBy, float Damage)
{
	Broadcast_Impl(HurtBy, Damage);
}

int UHurtCallback::Subscribe(const FOnHurtSignature& Callback)
{
	const auto Lambda = [=](UItemOwner* HurtBy, const float Damage)
	{
		Callback.ExecuteIfBound(HurtBy, Damage);
	};
	return Subscribe_Impl(std::move(Lambda));
}

void UHurtCallback::Unsubscribe(const int Token)
{
	Unsubscribe_Impl(Token);
}

