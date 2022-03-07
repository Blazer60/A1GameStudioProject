// Fill out your copyright notice in the Description page of Project Settings.


#include "SetupComponent.h"

USetupComponent::USetupComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void USetupComponent::BeginPlay()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Congrats, your project is working");
}

void USetupComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

