
#include "CombatPack.h"

CombatPack::CombatPack(ItemFile * file) : Item(file)
{
    setColour(0.0, 1.0, 0.0);
}

CombatPack::CombatPack()
{
    setColour(0.0, 1.0, 0.0);
}

CombatPack::~CombatPack()
{
}

void CombatPack::onConsume(Player * playerCharacter)
{
    PlayerStats& stats = playerCharacter->getStats();
    stats.strength += 2;
    turnOffObservers();
    used = true;
}