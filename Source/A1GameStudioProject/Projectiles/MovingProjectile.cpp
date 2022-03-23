// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingProjectile.h"

AMovingProjectile::AMovingProjectile()
{
	PrimaryActorTick.bCanEverTick = false;
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("Projectile Movement");
}
