// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile.h"
#include "Components/SphereComponent.h"
#include "A1GameStudioProject/Common.h"

#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "MovingProjectile.generated.h"

class UItemOwner;

UCLASS()
class A1GAMESTUDIOPROJECT_API AMovingProjectile
	: public AProjectile
{
	GENERATED_BODY()
public:
	AMovingProjectile();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UProjectileMovementComponent* ProjectileMovementComponent;
};
