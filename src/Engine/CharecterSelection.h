
/* ------------------------------------------------

	@File		: CharacterSelection.h
	@Date		: 08/11/2013
	@Purpose	:
		
		Just a simple state where multiple
		characters will be available to 
		play as. As for now it has a single
		title and any key will take the player
		to the main menu.

 ------------------------------------------------ */

#pragma once

#include "StateManager.h"
#include "Label.h"

class CharactorSelection : public State {
	private:

		Label * title;

	public:

	CharactorSelection(Factory *);

		void onEvent(StateManager&, SDL_Event&);
		void onDraw(Renderer&, StateManager&);
		void onUpdate(StateManager&);

		void onEnter(StateManager&);
		void onExit(StateManager&);

	~CharactorSelection();
};