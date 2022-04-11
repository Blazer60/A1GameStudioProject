// Fill out your copyright notice in the Description page of Project Settings.


#include "Stat.h"

UStat::UStat(const float B)
	: Base(B), OriginalBase(B)
{
}

float UStat::Total() const
{
	return Base + Additional + Multiplier * (Base + Additional);
}

float UStat::IncreaseBase(const int32 Level)
{
	Base = OriginalBase + OriginalBase * StackRate * static_cast<float>(Level - 1);
	return Base;
}
