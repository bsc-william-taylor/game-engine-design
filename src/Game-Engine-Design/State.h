
/* ------------------------------------------------

	@File		: State.h
	@Date		: 21/11/2013
	@Purpose	:

		A abstract State class that is to be
		inherited by new states as it is 
		the skelton of which all states must
		follow.

 ------------------------------------------------ */

#pragma once

#include "MonsterFile.h"
#include "PlayerFile.h"
#include "Renderer.h"
#include "Factory.h"

class StateManager;
class GameFile;

class State {
	public:
		// static files is used so all
		// states can access the various files
		static MonsterFile * npcFile;
		static PlayerFile * playerFile;
		static ItemFile * itemFile;
		static GameFile * file;

	public:
	State() {
		// Not needed
	}

		// Methods that need to be implemented
		virtual void onEvent(StateManager&, SDL_Event&) = 0;
		virtual void onDraw(Renderer&, StateManager&) = 0;
		virtual void onUpdate(StateManager&) = 0;
		virtual void onEnter(StateManager&) = 0;
		virtual void onExit(StateManager&) = 0;

	virtual ~State() {
		// Not needed
	}
};
