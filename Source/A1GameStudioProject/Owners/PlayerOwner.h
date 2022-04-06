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
	virtual void OnKill(const FVector& Location, const int Money) override;

protected:
	UPROPERTY(EditAnywhere, Category=PlayerOwner)
	int32 Credits { 0 };
};
