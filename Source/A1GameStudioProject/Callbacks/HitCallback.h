// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Callback.h"
#include "HitCallback.generated.h"

class UItemOwner;

DECLARE_DYNAMIC_DELEGATE_FourParams(FOnHitSignature, UItemOwner*, Target, float, ProcRate, float, Damage, FVector, HitLocation);

UCLASS(ClassGroup=(Callback), meta=(BlueprintSpawnableComponent))
class A1GAMESTUDIOPROJECT_API UHitCallback
	: public UActorComponent, public TCallback<UItemOwner*, float, float, FVector>
{
	GENERATED_BODY()
public:
	UHitCallback();

	UFUNCTION(BlueprintCallable)
	void Broadcast(UItemOwner *Target, float ProcRate, float Damage, FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	int Subscribe(const FOnHitSignature &Callback);
	
	UFUNCTION(BlueprintCallable)
	void Unsubscribe(int Token);
};
