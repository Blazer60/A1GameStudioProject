// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemComponent.generated.h"

UENUM()
enum class EStack { Logarithmic, Linear, Exponential };

UCLASS(ClassGroup=(Item), meta=(BlueprintSpawnableComponent), Blueprintable)
class A1GAMESTUDIOPROJECT_API UItemComponent
	: public UActorComponent
{
	GENERATED_BODY()
public:	
	UItemComponent();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnAttach();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnDetach();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnIncrease();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnDecrease();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count { 0 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EStack Stack { EStack::Linear };

	uint32_t CallBackToken { 0 };
};
