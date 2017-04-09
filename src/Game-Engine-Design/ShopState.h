
#pragma once

#include "StateManager.h"
#include "State.h"

enum ItemType
{
    STIMULANT = 2,
    COMBAT = 1,
    HEALTH = 0,
};

class Store : public State 
{
    Player* playerCharacter;
    Label* storeLabels[4];
public:
    Store(Factory *);
    ~Store();

    void onEvent(StateManager&, SDL_Event&);
    void onDraw(Renderer&, StateManager&);
    void onUpdate(StateManager&);
    void onEnter(StateManager&);
    void onExit(StateManager&);
    void buyItem(ItemType);
};