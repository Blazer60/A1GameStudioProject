// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Callback.h"
#include "KillCallback.generated.h"

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnKillSignature, FVector, Location, int, Money);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class A1GAMESTUDIOPROJECT_API UKillCallback
	: public UActorComponent, public TCallback<FVector, int>
{
	GENERATED_BODY()
public:
	UKillCallback();
	
	UFUNCTION(BlueprintCallable)
	void Broadcast(const FVector &Location, int Money);
	
	UFUNCTION(BlueprintCallable)
	int Subscribe(const FOnKillSignature &Callback);
	
	UFUNCTION(BlueprintCallable)
	void Unsubscribe(const int Token);
};
