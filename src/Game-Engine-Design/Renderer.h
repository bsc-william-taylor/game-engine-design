
#pragma once

#include "Objects.h"

class Renderer 
{
public:
    Renderer() {}
    virtual ~Renderer() {}
    virtual void backgroundColour(float, float, float, float) = 0;
    virtual void drawCharacterVector(vector<Character*>&) = 0;
    virtual void drawLabelArray(Label*[], int, int) = 0;
    virtual void drawItemVector(vector<Item*>&) = 0;
    virtual void drawLabelArray(Label*[], int) = 0;
    virtual void drawCharacter(Character*) = 0;
    virtual void drawPlayerStats(Player*) = 0;
    virtual void drawPlayer(Character*) = 0;
    virtual void drawFullNpc(NPC *) = 0;
    virtual void drawLabel(Label*) = 0;
    virtual void drawItem(Item *) = 0;
    virtual void drawShop(Shop *) = 0;
    virtual void clearScreen() = 0;
};