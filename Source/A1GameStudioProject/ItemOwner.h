// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemOwner.generated.h"


UCLASS(ClassGroup=(Item), meta=(BlueprintSpawnableComponent))
class A1GAMESTUDIOPROJECT_API UItemOwner
	: public UActorComponent
{
	GENERATED_BODY()
public:
	UItemOwner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Health { 100.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BaseMaxHealth { 100.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TotalMaxHealth { 100.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BaseMovementSpeed { 600.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TotalMovementSpeed { 600.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BaseJumpHeight { 400.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TotalJumpHeight { 400.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BaseDamageMultiplier { 1.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TotalDamageMultiplier { 1.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level { 0 };
	
};
