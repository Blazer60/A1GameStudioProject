// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Stat.generated.h"

/**
 * A Stat that can change depending on what items impact it. Items may only modify Additional and Multiplier. 
 */
UCLASS(Blueprintable, BlueprintType)
class A1GAMESTUDIOPROJECT_API UStat
	: public UObject
{
	GENERATED_BODY()
public:
	UStat() = default;
	explicit  UStat(float B);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Stats)
	float Base { 1.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats)
	float Additional { 0.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats)
	float Multiplier { 0.f };

	/** The rate at which base should increase based on the level? Base' = StackRate * Base */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats)
	float StackRate { 1.f };

	/** Gets the total amount of this stat based on all of its properties */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=Stats)
	float Total() const;

	UFUNCTION(BlueprintCallable, Category=Leveling)
	float IncreaseBase(int32 Level);

	float OriginalBase { Base };
};
