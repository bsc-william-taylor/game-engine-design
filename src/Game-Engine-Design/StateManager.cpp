
#include "StateManager.h"
#include "Game.h"

StateManager::StateManager(Game *game, Factory * factory)
{
    this->factory = factory;
    this->game = game;

    preState = NULL;
    curState = NULL;
    position = NULL;
}

StateManager::~StateManager()
{
    for (auto& state : gameStates)
    {
        delete state;
    }

    gameStates.clear();
}

void StateManager::StartFrom(unsigned int position)
{
    if (position < gameStates.size() && position > 0)
    {
        curState = gameStates[position];
        preState = gameStates[0];
        this->position = position;
    }

    if (position < gameStates.size() && position == 0)
    {
        curState = gameStates[position];
        this->position = position;
    }
}

State* StateManager::getCurrentState()
{
    return curState;
}

void StateManager::ExitStates()
{
    if (game != NULL)
    {
        curState->onExit(*this);
        game->Exit();
    }
}

void StateManager::SwitchState(unsigned int position)
{
    preState = curState;

    if (position < gameStates.size())
    {
        curState->onExit(*this);
        curState = gameStates[position];
        curState->onEnter(*this);

        this->position = position;
    }
}

void StateManager::PreviousState()
{
    SwitchState(position - 1);
}

void StateManager::NextState()
{
    SwitchState(position + 1);
}