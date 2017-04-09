
/* ------------------------------------------------

	@File		: Credits.h
	@Date		: 08/11/2013
	@Purpose	:
		
		The following the a class that
		represents a Credits state where
		the publisher name & studio name
		are shown.

 ------------------------------------------------ */

#pragma once

#include "RendererGL.h" 
#include "StateManager.h"
#include "Timer.h"
#include "States.h"
#include "Label.h"

class Credits : public State{
	private:

		Label * publisherName;
		Label * studioName;
		Label * myName;

		Timer * timer;

	public:

	Credits(Factory*);

		void onDraw(Renderer&, StateManager&);
		void onUpdate(StateManager&);
		void onEvent(StateManager&, SDL_Event&);

		void onEnter(StateManager&);
		void onExit(StateManager&);

	~Credits();
};