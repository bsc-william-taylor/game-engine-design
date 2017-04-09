
#pragma once

#include "RendererGL.h" 
#include "StateManager.h"
#include "Timer.h"
#include "States.h"
#include "Label.h"

class Credits : public State
{
    Label* publisherName;
    Label* studioName;
    Label* myName;
    Timer timer;
public:
    Credits(Factory*);
    ~Credits();

    void onDraw(Renderer&, StateManager&);
    void onUpdate(StateManager&);
    void onEvent(StateManager&, SDL_Event&);
    void onEnter(StateManager&);
    void onExit(StateManager&);
};