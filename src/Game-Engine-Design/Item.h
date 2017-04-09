
/* ------------------------------------------------

    @File		: Item.h
    @Date		: 21/11/2013
    @Purpose	:

        A base class which items must inherit
        & define what should happen the player
        consumes the item on contact

 ------------------------------------------------ */

#pragma once

#include "Object.h"

class ItemFile;
class Player;

class Item : public Object 
{
protected:
    ItemFile * file;
    Colour colour;
    bool used;
    int num;
public:
    Item(ItemFile *);
    Item();
    ~Item();

    virtual void onConsume(Player *) = 0;

    void setColour(float, float, float);
    void setItemNumber(int);
    void reset();
    void load();
    void save();

    bool isUsed();

    Colour& getColour();
};