
/* ------------------------------------------------

	@File		: GameOver.h
	@Date		: 08/11/2013
	@Purpose	:
		
		A class that represents a state
		which i made active when the game
		end upon which it will display
		the appropiate text indicating
		weather the player won or lossed 
		the game.

 ------------------------------------------------ */

#pragma once

#include "StateManager.h"
#include "GL_Renderer.h" 
#include "Object.h"
#include "Label.h"
#include "Timer.h"

class GameOver : public State {
	private:

		Label * Result;
		Label * Title;

		bool playerWin;

	public:

	GameOver(Factory *);
	
		void onEvent(StateManager&, SDL_Event&);
		void onDraw(Renderer&, StateManager&);
		void onUpdate(StateManager&);
		void onEnter(StateManager&);
		void onExit(StateManager&);
		void setWinner(bool);

	~GameOver();
};

