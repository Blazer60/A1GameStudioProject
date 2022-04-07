// Fill out your copyright notice in the Description page of Project Settings.


#include "Stat.h"

UStat::UStat(const float B)
	: Base(B) 
{
}

float UStat::Total() const
{
	return Base + Additional + Multiplier * (Base + Additional);
}
