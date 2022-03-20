// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "A1GameStudioProject/ItemOwner.h"


AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = true;
	SphereComponent				= CreateDefaultSubobject<USphereComponent>("Sphere Collision");
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("Projectile Movement");

	// The projectile movement component needs a collision object at root. So we force it here.
	RootComponent = SphereComponent;
	// FScriptDelegate Delegate;
	// SphereComponent->OnComponentHit.Add(Delegate);
	SphereComponent->OnComponentHit.AddDynamic(this, &AProjectile::OnHitDelegate);
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void AProjectile::SetupProjectile(AActor* NewActorOwner, UItemOwner* ItemOwnerComponent)
{
	this->ActorOwner = NewActorOwner;
	this->ItemOwner = ItemOwnerComponent;
	this->OwnerType = ItemOwnerComponent->Type;
}

void AProjectile::OnHitDelegate(
	UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit
	)
{
	if (!ActorOwner && !ItemOwner)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,
			"Hit Registered but no actor owner or item owner was registered before. Use SetupProjectile"
			);
		return;
	}

	auto *OtherOwner = OtherActor->FindComponentByClass<UItemOwner>();
	if (!OtherOwner || OwnerType == None)
		return;

	if (OtherOwner->Type != OwnerType)
		ItemOwner->OnHit(OtherOwner, ProcRate, Damage, Hit.Location);

	// Always hurt things if they are not set to type None.
	OtherOwner->OnHurt(ItemOwner, Damage);
}



