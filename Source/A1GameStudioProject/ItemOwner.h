﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Common.h"

#include "CoreMinimal.h"
#include "Callbacks/KillCallback.h"
#include "Components/ActorComponent.h"
#include "ItemOwner.generated.h"

class UHitCallback;
class UHurtCallback;
class UItemComponent;
class AProjectile;

UCLASS(ClassGroup=(Item), meta=(BlueprintSpawnableComponent))
class A1GAMESTUDIOPROJECT_API UItemOwner
	: public UActorComponent
{
	GENERATED_BODY()
public:
	UItemOwner();

	UFUNCTION(BlueprintCallable)
	UItemComponent *AddItem(TSubclassOf<UItemComponent> ItemClass);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Health { 100.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BaseMaxHealth { 100.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TotalMaxHealth { 100.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BaseMovementSpeed { 600.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TotalMovementSpeed { 600.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BaseJumpHeight { 400.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TotalJumpHeight { 400.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BaseDamageMultiplier { 1.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TotalDamageMultiplier { 1.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level { 0 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<EOwnerType> Type { Enemy };
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UHitCallback* HitCallback { nullptr };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UHurtCallback* HurtCallback { nullptr };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UKillCallback* KillCallback { nullptr };

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnDeath(UItemOwner* By, float Damage);
	
	void OnHit(UItemOwner *Target, float ProcRate, float Damage, FVector HitLocation) const;
	void OnHurt(UItemOwner *By, float Damage);
	void OnKill(const FVector &Location, const int Money) const;

	UFUNCTION(BlueprintCallable)
	void SpawnProjectile(TSubclassOf<AProjectile> Class, const FTransform &Transform);

	virtual void BeginPlay() override;
	// UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// TArray<UItemComponent *> Items;

	// UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// UItemComponent *ItemPtr;
protected:
	void Warn(const FString &Item) const;
};
