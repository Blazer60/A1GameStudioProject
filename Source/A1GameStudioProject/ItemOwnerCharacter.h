// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Callback.h"
#include "HitCallback.h"
#include "ItemOwnerCharacter.generated.h"

UCLASS()
class A1GAMESTUDIOPROJECT_API AItemOwnerCharacter
	: public ACharacter
{
	GENERATED_BODY()
public:
	AItemOwnerCharacter();

	virtual void Tick(float DeltaTime) override;
    
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Health;

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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UHitCallback *OnHitCallback;
};
