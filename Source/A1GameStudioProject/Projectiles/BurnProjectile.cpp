// Fill out your copyright notice in the Description page of Project Settings.


#include "BurnProjectile.h"

#include "A1GameStudioProject/ItemOwner.h"


ABurnProjectile::ABurnProjectile()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}


void ABurnProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Timer -= DeltaTime;
	if (Timer <= 0)
	{
		Timer += TickRate;
		BurnTick();
	}
}

void ABurnProjectile::BeginOverlapProxy(
	UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
	bool bFromSweep, const FHitResult& SweepResult)
{
	BeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	OnOverlapDelegate(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}

void ABurnProjectile::BeginOverlap(
	UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	if (!CheckOwner())
		return;

	auto *OtherOwner = OtherActor->FindComponentByClass<UItemOwner>();
	if (!OtherOwner || OwnerType == None)
		return;

	if (BurnedOwners.Find(OtherOwner) == INDEX_NONE)
		BurnedOwners.Add(OtherOwner);
}

void ABurnProjectile::EndOverlap(
	UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	auto *OtherOwner = OtherActor->FindComponentByClass<UItemOwner>();
	if (OtherOwner)
		BurnedOwners.Remove(OtherOwner);
}

void ABurnProjectile::BurnTick()
{
	const FVector &Location = GetActorLocation();
	for (int i = 0; i < BurnedOwners.Num(); ++i)
	{
		UItemOwner* OtherOwner = BurnedOwners[i];
		if (!IsValid(OtherOwner))
		{
			BurnedOwners.Remove(OtherOwner); // Ignore actors that are deemed invalid.
			--i;
			continue;
		}
        		
        OtherOwner->OnHurt(ItemOwner, Damage);

        if (OtherOwner->Type != OwnerType && ItemOwner)
        {
	        ItemOwner->OnHit(OtherOwner, ProcRate, Damage, Location);
        	if (OtherOwner->Health <= 0)
        	{
        		ItemOwner->OnKill(Location, OtherOwner->BaseReward);
        	}
        }
        OnHit(OtherOwner, Location);
	}
}

void ABurnProjectile::BeginPlay()
{
	// Hit Delegates must always be attached at runtime.
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ABurnProjectile::BeginOverlapProxy);
    SphereComponent->OnComponentEndOverlap.AddDynamic(this, &ABurnProjectile::EndOverlap);
}

