
#pragma once

#include "ItemFile.h"
#include "Item.h"

class HealthPack : public Item
{
public:
    HealthPack(ItemFile *);
    HealthPack();
    ~HealthPack();

    void onConsume(Player *);    
};