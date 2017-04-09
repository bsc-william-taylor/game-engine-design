
#pragma once

#include "StateManager.h"
#include "Label.h"

class CharactorSelection : public State 
{
    Label* title;
public:
    CharactorSelection(Factory *);
    ~CharactorSelection();

    void onEvent(StateManager&, SDL_Event&);
    void onDraw(Renderer&, StateManager&);
    void onUpdate(StateManager&);
    void onEnter(StateManager&);
    void onExit(StateManager&);   
};