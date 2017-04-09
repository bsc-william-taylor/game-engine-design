
#include "HealthPack.h"

HealthPack::HealthPack(ItemFile * file) : Item(file)
{
}

HealthPack::HealthPack()
{
}

HealthPack::~HealthPack()
{
}

void HealthPack::onConsume(Player * playerCharacter)
{
    PlayerStats& stats = playerCharacter->getStats();

    if (stats.health < stats.startHealth)
    {
        stats.health = stats.startHealth;
    }
    else
    {
        stats.health++;
    }

    turnOffObservers();
    used = true;
}