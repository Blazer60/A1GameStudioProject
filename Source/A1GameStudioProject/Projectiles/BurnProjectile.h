// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile.h"
#include "GameFramework/Actor.h"
#include "BurnProjectile.generated.h"

UCLASS()
class A1GAMESTUDIOPROJECT_API ABurnProjectile
	: public AProjectile
{
	GENERATED_BODY()
public:
	ABurnProjectile();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void BeginOverlap(
		UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult &SweepResult);

	UFUNCTION()
	void EndOverlap(
		UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void BurnTick();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TickRate { 1.f };

protected:
	virtual void BeginPlay() override;

	TArray<UItemOwner*> BurnedOwners;
	float Timer { TickRate };
};
