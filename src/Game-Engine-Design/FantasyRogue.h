
/* ------------------------------------------------

	@File		: FantasyRogue.h
	@Date		: 08/11/2013
	@Purpose	:

		A class the extends the game class
		to add states and to select a 
		renderer

 ------------------------------------------------ */

#pragma once

#include "Main.h"
#include "Game.h"

// Extended game class
class FantasyRogue : public Game {
	public:
	FantasyRogue();

		void Initialise();
		void Start();

	~FantasyRogue();
};