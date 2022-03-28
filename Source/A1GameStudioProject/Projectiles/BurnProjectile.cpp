// Fill out your copyright notice in the Description page of Project Settings.


#include "BurnProjectile.h"

#include "A1GameStudioProject/ItemOwner.h"


ABurnProjectile::ABurnProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	FScriptDelegate BeginOverlapDelegate;
	BeginOverlapDelegate.BindUFunction(this, "BeginOverlap");
	SphereComponent->OnComponentBeginOverlap.AddUnique(BeginOverlapDelegate);
	
	// SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ABurnProjectile::BeginOverlap);
	// SphereComponent->OnComponentEndOverlap.AddDynamic(this, &ABurnProjectile::EndOverlap);
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
        	ItemOwner->OnHit(OtherOwner, ProcRate, Damage, Location);

        OnHit(OtherOwner, Location);
	}
}

void ABurnProjectile::BeginPlay()
{
	Super::BeginPlay();
	// Hit Delegates must always be attached at runtime.
    SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ABurnProjectile::BeginOverlap);
    SphereComponent->OnComponentEndOverlap.AddDynamic(this, &ABurnProjectile::EndOverlap);
}

