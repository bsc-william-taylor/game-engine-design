
/* ------------------------------------------------

	@File		: Game.h
	@Date		: 08/11/2013
	@Purpose	:

		A simple game class to shorten the 
		main class and acts as a center
		point for the game framework.

 ------------------------------------------------ */

#pragma once

#include "StateManager.h"
#include "GameFile.h"
#include "Renderer.h"

class StateManager;
class Factory;

class Game {
	protected:
		
		// Sets up the Render context for the window
		SDL_Window * SetupRC(SDL_GLContext &); 
		SDL_Window * Window;
		SDL_Event event;
		
		// Following Objects are passed to states
		StateManager * states;
		Renderer * renderer;
		GameFile * gameFile;
		Factory * factory;
		
		bool loop;

	public:
	Game();

		void ExitError(const char *);
		void Exit();
		void Initialise();
		void Run();

	virtual ~Game();
};
