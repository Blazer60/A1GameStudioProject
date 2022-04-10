// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "A1GameStudioProject/ItemOwner.h"
#include "Kismet/GameplayStatics.h"


AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = true;
	SphereComponent = CreateDefaultSubobject<USphereComponent>("Sphere Collision");

	// The projectile movement component needs a collision object at root. So we force it here.
	RootComponent = SphereComponent;
	
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::OnOverlapDelegate);
}

AProjectile::AProjectile(AActor* NewActorOwner, UItemOwner* ItemOwnerComponent)
	: ActorOwner(NewActorOwner), ItemOwner(ItemOwnerComponent)
{
	PrimaryActorTick.bCanEverTick = true;
	SphereComponent = CreateDefaultSubobject<USphereComponent>("Sphere Collision");

	// The projectile movement component needs a collision object at root. So we force it here.
	RootComponent = SphereComponent;
	
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::OnOverlapDelegate);
}

void AProjectile::SpawnProjectile(TSubclassOf<AProjectile> Class, const FTransform& Transform)
{
	auto *Projectile = Cast<AProjectile>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, Class, Transform));
	Projectile->SetupProjectile(ActorOwner, ItemOwner);
	UGameplayStatics::FinishSpawningActor(Projectile, Transform);
}

void AProjectile::SetupProjectile(AActor* NewActorOwner, UItemOwner* ItemOwnerComponent)
{
	this->ActorOwner = NewActorOwner;
    this->ItemOwner = ItemOwnerComponent;
	if (ItemOwnerComponent)
	{
		this->OwnerType = ItemOwnerComponent->Type;
		if (ItemOwnerComponent->DamageMultiplier)
        		Damage *= ItemOwnerComponent->DamageMultiplier->Total();
	}
}

void AProjectile::OnOverlapDelegate(
	UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
	if (!CheckOwner())
		return;
	
	auto *OtherOwner = OtherActor->FindComponentByClass<UItemOwner>();
	if (!OtherOwner || OwnerType == None)
		return;

	// Always hurt things if they are not set to type None.
	if (OtherOwner->Type != OwnerType)
	{
		OtherOwner->OnHurt(ItemOwner, Damage);
		if (ItemOwner)
		{
			ItemOwner->OnHit(OtherOwner, ProcRate, Damage, SweepResult.Location);
			OnHit(OtherOwner, SweepResult.Location);
            if (OtherOwner->Health <= 0)
            	ItemOwner->OnKill(SweepResult.Location, OtherOwner->RewardCredits);
		}
	}
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();
}

bool AProjectile::CheckOwner()
{
	if (OwnerType != EOwnerType::World)
	{
		if (!ActorOwner && !ItemOwner)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,
				//"Hit Registered but no actor owner or item owner was registered before. Use SetupProjectile"
				//);
			return false;
		}
	}
	return true;
}
