
/* ------------------------------------------------

	@File		: StateManager.h
	@Date		: 21/11/2013
	@Purpose	:

		A state manager class that will manage
		state transitions and which state
		it to be rendered update etc.
		New states must be added using newState
		before they can be accessed

 ------------------------------------------------ */

#pragma once

#include "Factory.h"
#include "State.h"

class Factory;
class Game;

class StateManager {
	private:

		vector<State *> gameStates;
		
		Factory * factory;
		State * preState;
		State * curState;
		Game * game;

		unsigned int position;

	public:

	StateManager(Game *, Factory *);

		State * getCurrentState();

		// Various methods to switch state
		void SwitchState(unsigned int);
		void StartFrom(unsigned int);
		void PreviousState();
		void ExitStates();
		void NextState();

		// Template functions for adding new states
		#pragma region Template Functions
		template<class state>
		state * getState(unsigned int i){
			if(i < gameStates.size()){
				return (state *)gameStates[i];
			}
			
			// You should never reach this code
			string message = "Couldnt get state : " + i;
			game->ExitError(message.c_str());
			return NULL;
		}

		template<class state>
		void addState(){
			gameStates.push_back(new state(factory));
		}
		#pragma endregion

	~StateManager();
};