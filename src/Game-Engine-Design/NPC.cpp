
#include "MonsterFile.h"
#include "Objects.h"
#include "Player.h"
#include "NPC.h"

NPC::NPC(Character * charector) : Character(*charector)
{
    this->file = NULL;
}

NPC::NPC(MonsterFile * file) : Character()
{
    this->file = file;
}

NPC::~NPC()
{
}

void NPC::dropItem(Player * playerCharacter)
{
    playerCharacter->getStats().cash += getStats().cash;

    int chances = stats.dropChance;
    int base = rand() % 100;

    if (rand() % 100 < chances)
    {
        if (base > 80 && base < 80)
        {
            CombatPack itemDrop;
            itemDrop.onConsume(playerCharacter);
        }
        else if (base < 60)
        {
            HealthPack itemDrop;
            itemDrop.onConsume(playerCharacter);
        }
        else
        {
            StimulantPack itemDrop;
            itemDrop.onConsume(playerCharacter);
        }
    }
}

void NPC::reset()
{
    stats = file->getStats(num);
    stats.health = file->getStats(num).startHealth;
    stats.dead = 0;

    file->setStats(num, stats);
    file->push();

    turnOnObservers();
}

bool NPC::isKilled()
{
    return stats.dead;
}

void NPC::load()
{
    text.textToTexture(file->getName(num));

    int x = file->getPosition(num).getX();
    int y = file->getPosition(num).getY();
    int w = file->getSize(num).getX();
    int h = file->getSize(num).getY();

    colour = file->getColour(num);
    stats = file->getStats(num);

    if (stats.dead)
    {
        Kill();
    }

    setPosition(Vector<int>(x, y));
    setSize(Vector<int>(w, h));
}

void NPC::save()
{
    file->setPosition(num, getPosition());
    file->setStats(num, stats);
    file->push();
}

void NPC::Kill() {
    stats.dead = true;
    turnOffObservers();
}