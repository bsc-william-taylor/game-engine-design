
#pragma once

#include "ItemFile.h"
#include "Player.h"
#include "Item.h"

class CombatPack : public Item 
{
public:
    CombatPack(ItemFile *);
    CombatPack();
    ~CombatPack();

    void onConsume(Player *);
};