// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Common.h"

#include "CoreMinimal.h"
#include "Stat.h"
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
	UItemComponent *AddItem(TSubclassOf<UItemComponent> ItemClass, int32 Quantity=1);

	UFUNCTION(BlueprintCallable)
	void SpawnProjectile(TSubclassOf<AProjectile> Class, const FTransform &Transform);
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnDeath(UItemOwner* By, float Damage);

	UFUNCTION(BlueprintCallable, Category=Callbacks)
	void OnHit(UItemOwner *Target, float ProcRate, float Damage, FVector HitLocation) const;

	UFUNCTION(BlueprintCallable, Category=Callbacks)
	void OnHurt(UItemOwner *By, float Damage);
	
	virtual void OnKill(const FVector &Location, const int Money);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats)
	float Health			{ 100.f };
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Instanced, Category=Stats)
	UStat *MaxHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Instanced, Category=Stats)
	UStat *Speed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Instanced, Category=Stats)
	UStat *JumpHeight;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Instanced, Category=Stats)
	UStat *DamageMultiplier;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Level { 0 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 BaseReward { 100 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<EOwnerType> Type { Enemy };
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UHitCallback* HitCallback { nullptr };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UHurtCallback* HurtCallback { nullptr };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UKillCallback* KillCallback { nullptr };

protected:
	virtual void BeginPlay() override;
	
	void Warn(const FString &Item) const;
};
