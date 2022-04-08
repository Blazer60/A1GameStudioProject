// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "A1GameStudioProject/Common.h"
#include "A1GameStudioProject/ItemOwner.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class UItemOwner;
UCLASS()
class A1GAMESTUDIOPROJECT_API AProjectile
	: public AActor
{
	GENERATED_BODY()
public:
	AProjectile();
	AProjectile(AActor *NewActorOwner, UItemOwner* ItemOwnerComponent);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnHit(UItemOwner* OtherOwner, FVector Location);

	UFUNCTION(BlueprintCallable)
	void SpawnProjectile(TSubclassOf<AProjectile> Class, const FTransform &Transform);
	
	UFUNCTION()
    void SetupProjectile(AActor* NewActorOwner, UItemOwner* ItemOwnerComponent);

	UFUNCTION(BlueprintCallable)
    void OnOverlapDelegate(
    	UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
    	int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult
    	);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    AActor* ActorOwner { nullptr };

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UItemOwner* ItemOwner { nullptr };

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TEnumAsByte<EOwnerType> OwnerType { None };

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ProcRate { 1.f };

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Damage { 10.f };

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    USphereComponent* SphereComponent;

protected:
	virtual void BeginPlay() override;
	
	bool CheckOwner();
};
