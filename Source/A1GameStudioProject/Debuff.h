// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemComponent.h"
#include "Components/ActorComponent.h"
#include "Debuff.generated.h"


UCLASS(ClassGroup=(Item), meta=(BlueprintSpawnableComponent))
class A1GAMESTUDIOPROJECT_API UDebuff
	: public UItemComponent
{
	GENERATED_BODY()
public:
	UDebuff();

	virtual void TickComponent(
		float DeltaTime, ELevelTick TickType,
		FActorComponentTickFunction* ThisTickFunction) override;
	
	float Timer { 1.f };
};
