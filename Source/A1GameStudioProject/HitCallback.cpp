// Fill out your copyright notice in the Description page of Project Settings.


#include "HitCallback.h"


UHitCallback::UHitCallback()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UHitCallback::Broadcast()
{
	Broadcast_Impl();
}

int UHitCallback::Subscribe(const FOnHitSignature& Callback)
{
	const auto Lambda = [=](){ Callback.ExecuteIfBound(); };
	return Subscribe_Impl(std::move(Lambda));
}

void UHitCallback::Unsubscribe(const int Token)
{
	Unsubscribe_Impl(Token);
}

