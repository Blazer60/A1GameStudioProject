// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Callback.h"
#include "HitCallback.generated.h"

DECLARE_DYNAMIC_DELEGATE(FOnHitSignature);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class A1GAMESTUDIOPROJECT_API UHitCallback
	: public UActorComponent, public TCallback<>
{
	GENERATED_BODY()
public:
	UHitCallback();

	UFUNCTION(BlueprintCallable)
	void Broadcast();

	UFUNCTION(BlueprintCallable)
	int Subscribe(const FOnHitSignature &Callback);
	
	UFUNCTION(BlueprintCallable)
	void Unsubscribe(int Token);
};
