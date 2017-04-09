
#pragma once

#include "MonsterFile.h"
#include "PlayerFile.h"
#include "Renderer.h"
#include "Factory.h"

class StateManager;
class GameFile;

class State
{
public:
    static MonsterFile* npcFile;
    static PlayerFile* playerFile;
    static ItemFile* itemFile;
    static GameFile* file;
public:
    State() {}
    virtual ~State() = default;

    virtual void onEvent(StateManager&, SDL_Event&) = 0;
    virtual void onDraw(Renderer&, StateManager&) = 0;
    virtual void onUpdate(StateManager&) = 0;
    virtual void onEnter(StateManager&) = 0;
    virtual void onExit(StateManager&) = 0;
};
