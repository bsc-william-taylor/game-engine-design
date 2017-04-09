
#pragma once

#include "StateManager.h"
#include "RendererGL.h" 
#include "Object.h"
#include "Label.h"
#include "Timer.h"

class GameOver : public State 
{
    Label * result;
    Label * title;
    bool playerWin;
public:
    GameOver(Factory *);
    ~GameOver();
    
    void onEvent(StateManager&, SDL_Event&);
    void onDraw(Renderer&, StateManager&);
    void onUpdate(StateManager&);
    void onEnter(StateManager&);
    void onExit(StateManager&);
    void setWinner(bool);
};

