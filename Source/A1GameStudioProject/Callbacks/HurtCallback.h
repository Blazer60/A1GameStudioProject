// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Callback.h"
#include "HurtCallback.generated.h"

class UItemOwner;

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnHurtSignature, UItemOwner*, HurtBy, float, Damage);

UCLASS(ClassGroup=(Callback), meta=(BlueprintSpawnableComponent))
class A1GAMESTUDIOPROJECT_API UHurtCallback
	: public UActorComponent, public TCallback<UItemOwner *, float>
{
	GENERATED_BODY()
public:
	UHurtCallback();

	UFUNCTION(BlueprintCallable)
	void Broadcast(UItemOwner *HurtBy, float Damage);

	UFUNCTION(BlueprintCallable)
	int Subscribe(const FOnHurtSignature &Callback);
	
	UFUNCTION(BlueprintCallable)
	void Unsubscribe(int Token);
};
