
/* ------------------------------------------------

	@File		: MainMenu.h
	@Date		: 08/11/2013
	@Purpose	:
		
		A class that represents the 
		main menu state.

 ------------------------------------------------ */

#pragma once

#include "StateManager.h"
#include "Renderer.h"
#include "Factory.h"
#include "Label.h"

enum MENU_TEXT {
	CONTINUE,
	CREDITS,
	LOAD,
	QUIT,
	NEW
};

class MainMenu : public State {
	private:

		Label * menuLabels[5];
		bool gameInProgress;

	public:

	MainMenu(Factory *);

		void onEvent(StateManager&, SDL_Event&);
		void onDraw(Renderer&, StateManager&);
		void onUpdate(StateManager&);
		void onEnter(StateManager&);
		void onExit(StateManager&);
		void restart();

	~MainMenu();
};