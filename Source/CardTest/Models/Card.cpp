#include "Card.h"

FLinearColor FCard::GetBackground() const
{
	switch (Type)
	{
	case ECardType::Creature: return {FColor::Red};
	case ECardType::Spell: return {FColor::Green};
	case ECardType::Instant: return {FColor::Blue};
	case ECardType::Artifact: return {FColor::Magenta};
	case ECardType::Qi: return {FColor::Cyan};
	default: return {FColor::White};
	}
}
