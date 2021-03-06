
/* ------------------------------------------------

    @File		: SplashScreen.h
    @Date		: 08/11/2013
    @Purpose	:

        This is a simple splashscreen state
        which will as requested display the
        company & studio name for 3 seconds.

 ------------------------------------------------ */

#pragma once

#include "StateManager.h"
#include "RendererGL.h" 
#include "Objects.h"
#include "Timer.h"

class SplashScreen : public State 
{
    Label* publisherName;
    Label* studioName;
    Timer timer;
public:
    SplashScreen(Factory *);
    ~SplashScreen();
    
    void onEvent(StateManager&, SDL_Event&);
    void onDraw(Renderer&, StateManager&);
    void onUpdate(StateManager&);
    void onEnter(StateManager&);
    void onExit(StateManager&);
};

