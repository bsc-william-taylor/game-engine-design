
#include "StimulantPack.h"

StimulantPack::StimulantPack(ItemFile * file) : Item(file)
{
    setColour(0.0, 0.0, 1.0);
}

StimulantPack::StimulantPack()
{
    setColour(0.0, 0.0, 1.0);
}

StimulantPack::~StimulantPack()
{
}

void StimulantPack::onConsume(Player * playerCharacter)
{
    PlayerStats& stats = playerCharacter->getStats();
    stats.speed++;
    turnOffObservers();
    used = true;
}