
/* ------------------------------------------------

	@File		: Combat.h
	@Date		: 08/11/2013
	@Purpose	:
		
		The following the a class that
		represents the combat state where
		the player combats the monster

 ------------------------------------------------ */

#pragma once

#include "StateManager.h"
#include "Objects.h"
#include "States.h"
#include "State.h"

class Combat : public State {
	private:

		Vector<int> monsterPos;
		Vector<int> playerPos;

		Player * player;
		Label * Title;
		NPC * opponent;

		void determineVictor(StateManager&);
		void firstHit();

		bool playersTurn, firsthit, finish;
		int previousHealth;
		int playerWin;

	public:

	Combat(Factory *);

		void onEvent(StateManager&, SDL_Event&);
		void onDraw(Renderer&, StateManager&);
		void onUpdate(StateManager&);
		void onEnter(StateManager&);
		void onExit(StateManager&);

		void setOpponent(NPC *);

	~Combat();
};