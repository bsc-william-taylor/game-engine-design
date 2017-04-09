
#pragma once

#include "StateManager.h"
#include "Objects.h"
#include "States.h"
#include "State.h"

class Combat : public State
{
    Vector<int> monsterPos;
    Vector<int> playerPos;

    Player* playerCharacter;
    Label* title;
    NPC* opponent;

    bool playersTurn, firsthit, finish;
    int previousHealth;
    int playerWin;
public:
    Combat(Factory *);
    ~Combat();

    void onEvent(StateManager&, SDL_Event&);
    void onDraw(Renderer&, StateManager&);
    void onUpdate(StateManager&);
    void onEnter(StateManager&);
    void onExit(StateManager&);

    void determineVictor(StateManager&);
    void setOpponent(NPC *);
    void firstHit();
};