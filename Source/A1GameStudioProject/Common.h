#pragma once

UENUM()
enum EOwnerType { None, Player, Enemy, World };

UENUM(BlueprintType)
enum ERarity { Common, Uncommon, Rare };

void Print(const std::string &Message, const FColor &Colour=FColor::Blue);
