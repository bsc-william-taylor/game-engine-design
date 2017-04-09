
#pragma once

#include "ItemFile.h"
#include "Item.h"

class StimulantPack : public Item
{
public:
    StimulantPack(ItemFile *);
    StimulantPack();
    ~StimulantPack();

    void onConsume(Player *);
};