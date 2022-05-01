// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "A1GameStudioProject/ItemOwner.h"
#include "PlayerOwner.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class A1GAMESTUDIOPROJECT_API UPlayerOwner
	: public UItemOwner
{
	GENERATED_BODY()
public:
	UPlayerOwner();
	virtual void OnKill(const FVector& Location, const int Money) override;
	
	virtual void OnHurt(UItemOwner* By, float Damage) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=ItemOwner)
	int32 Credits { 0 };
};
