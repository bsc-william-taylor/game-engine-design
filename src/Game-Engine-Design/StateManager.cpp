
/* ------------------------------------------------

	@File		: StateManager.cpp
	@Date		: 21/11/2013
	@Purpose	:

		StateManager class implementation

 ------------------------------------------------ */

#include "StateManager.h"
#include "Game.h"

// Constructor & Deconstructor
StateManager::StateManager(Game *game,  Factory * factory) {
	// Factory class is passed to states upon creation
	this->factory = factory;
	this->game = game;

	preState = NULL;
	curState = NULL;
	position = NULL;
}

StateManager::~StateManager() {
	// Clean up all states
	gameStates.erase(gameStates.begin(), gameStates.end());
}

void StateManager::StartFrom(unsigned int position) {
	// if state exists set starting point 
	// & previous state if the position > 0
	if(position < gameStates.size() && position > 0){
		curState = gameStates[position];
		preState = gameStates[0];
		this->position = position;
	} 

	if(position < gameStates.size() && position == 0){
		curState = gameStates[position];
		this->position = position;
	} 
}

State * StateManager::getCurrentState(){
	return curState; 
}

void StateManager::ExitStates() {
	if(game != NULL) {
		// Exit last state & call game Exit method
		curState->onExit(*this);
		game->Exit();
	}
}

void StateManager::SwitchState(unsigned int position) {
	preState = curState;

	// only go to state is it exists
	if(position < gameStates.size()) {
		curState->onExit(*this);
		curState = gameStates[position];
		curState->onEnter(*this);

		this->position = position;
	}
}

void StateManager::PreviousState() {
	// Go back to previous state
	SwitchState(position - 1);
}

void StateManager::NextState() {
	// Increment to next state
	SwitchState(position + 1);
}