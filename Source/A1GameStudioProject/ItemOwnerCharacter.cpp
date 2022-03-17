// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemOwnerCharacter.h"

// Sets default values
AItemOwnerCharacter::AItemOwnerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	OnHitCallback = CreateDefaultSubobject<UHitCallback>("Hit Callback");
}

// Called when the game starts or when spawned
void AItemOwnerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemOwnerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AItemOwnerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

