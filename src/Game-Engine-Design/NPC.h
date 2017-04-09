
#pragma once

#include "Character.h"

class MonsterFile;
class Player;

struct MonsterStats 
{
    int startHealth;
    int dropChance;
    int strength;
    int health;
    int speed;
    int cash;
    int dead;
};

class NPC : public Character 
{
    MonsterStats stats;
    MonsterFile* file;
public:
    NPC(MonsterFile *);
    NPC(Character *);
    ~NPC();

    MonsterStats& getStats() { return stats; }
    bool isKilled();

    void dropItem(Player *);
    void reset();
    void load();
    void save();
    void Kill();
};