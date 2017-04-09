
#pragma once

#include "Character.h"

class PlayerFile;

struct PlayerStats 
{
    int startHealth;
    int StartStrength;
    int StartSpeed;
    int strength;
    int health;
    int speed;
    int cash;
    int dead;
};

class Player : public Character 
{
    PlayerStats playerStats;
    PlayerFile* playerfile;
public:
    Player(PlayerFile *);
    ~Player();

    void moveX(int);
    void moveY(int);

    PlayerStats& getStats() { return playerStats; }

    bool isKilled() { return playerStats.dead; }
    void reset();
    void load();
    void save();
    void Kill();
};