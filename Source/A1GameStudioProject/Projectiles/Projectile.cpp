// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "A1GameStudioProject/ItemOwner.h"


AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = false;
	SphereComponent = CreateDefaultSubobject<USphereComponent>("Sphere Collision");

	// The projectile movement component needs a collision object at root. So we force it here.
	RootComponent = SphereComponent;
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::OnOverlapDelegate);
}

void AProjectile::SetupProjectile(AActor* NewActorOwner, UItemOwner* ItemOwnerComponent)
{
	this->ActorOwner = NewActorOwner;
    this->ItemOwner = ItemOwnerComponent;
    this->OwnerType = ItemOwnerComponent->Type;
}

void AProjectile::OnOverlapDelegate(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
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

	// Always hurt things if they are not set to type None.
    	OtherOwner->OnHurt(ItemOwner, Damage);

	if (OtherOwner->Type != OwnerType)
		ItemOwner->OnHit(OtherOwner, ProcRate, Damage, SweepResult.Location);
}
