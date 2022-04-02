#include "Common.h"

void Print(const std::string& Message, const FColor& Colour)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, Colour, Message.c_str());
}
