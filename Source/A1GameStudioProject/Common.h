#pragma once

UENUM()
enum EOwnerType { None, Player, Enemy, World };

void Print(const std::string &Message, const FColor &Colour=FColor::Blue);
