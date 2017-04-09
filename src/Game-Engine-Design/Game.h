
#pragma once

#include "StateManager.h"
#include "GameFile.h"
#include "Renderer.h"

class StateManager;
class Factory;

class Game 
{
protected:
    SDL_Window * SetupRC(SDL_GLContext &);
    SDL_Window * Window;
    SDL_Event event;

    StateManager* states;
    Renderer* renderer;
    GameFile* gameFile;
    Factory* factory;

    bool loop;
public:
    Game();
    virtual ~Game();

    void ExitError(const char *);
    void Exit();
    void Initialise();
    void Run();
};
