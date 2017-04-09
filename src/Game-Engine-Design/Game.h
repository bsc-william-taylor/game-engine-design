
#pragma once

#include "StateManager.h"
#include "GameFile.h"
#include "Renderer.h"

class StateManager;
class Factory;

class Game
{
protected:
    StateManager* states;
    Renderer* renderer;
    GameFile* gameFile;
    Factory* factory;

    SDL_Window* window;
    SDL_Event event;
    bool loop;
public:
    Game();
    virtual ~Game();

    void initialise();
    void exitError(const char *);
    void exit();
    void run();

    SDL_Window* setupRenderContext(SDL_GLContext &);
};
