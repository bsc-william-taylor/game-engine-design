
#pragma once

#include "Factory.h"
#include "State.h"

class Factory;
class Game;

class StateManager
{
private:
    vector<State *> gameStates;
    Factory* factory;
    State* preState;
    State* curState;
    Game* game;

    unsigned int position;
public:
    StateManager(Game*, Factory*);
    ~StateManager();

    State* getCurrentState();

    void SwitchState(unsigned int);
    void StartFrom(unsigned int);
    void PreviousState();
    void ExitStates();
    void NextState();

    template<class State>
    State* getState(unsigned int i)
    {
        if (i < gameStates.size()) 
        {
            return (State *)gameStates[i];
        }

        string message = "Couldnt get state : " + i;
        game->ExitError(message.c_str());
        return NULL;
    }

    template<class State>
    void addState() 
    {
        gameStates.push_back(new State(factory));
    }
};