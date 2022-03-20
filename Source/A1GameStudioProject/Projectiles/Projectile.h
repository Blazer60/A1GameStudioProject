// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "A1GameStudioProject/Common.h"

#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Projectile.generated.h"

class UItemOwner;

UCLASS()
class A1GAMESTUDIOPROJECT_API AProjectile
	: public AActor
{
	GENERATED_BODY()

public:
	AProjectile();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void SetupProjectile(AActor* ActorOwner, UItemOwner* ItemOwnerComponent);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AActor* ActorOwner { nullptr };

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UItemOwner* ItemOwner { nullptr };

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TEnumAsByte<EOwnerType> OwnerType { None };

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float ProcRate { 1.f };

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Damage { 10.f };

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USphereComponent* SphereComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UProjectileMovementComponent* ProjectileMovementComponent;

	UFUNCTION()
	void OnHitDelegate(
		UPrimitiveComponent* HitComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit
		);
};
