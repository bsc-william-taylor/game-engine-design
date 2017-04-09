
/* ------------------------------------------------

	@File		: PlayerFile.h
	@Date		: 21/11/2013
	@Purpose	:

		A class that opens the player file
		and gets all relevant data. The engine
		then reads this and constructs the player 
		from data listed in the file.

 ------------------------------------------------ */

#pragma once

#include "FileReader.h"
#include "Objects.h"
#include "Vector.h"

class Character;
class Game;

class PlayerFile {
	private:

		FileReader * file;

	public:

	PlayerFile(Game&, string);

		PlayerStats getStats();
		Colour getColour();
		string getName();
		
		Vector<int> getPosition();
		Vector<int> getStart();
		Vector<int> getSize();

		void setPosition(Vector<int>);
		void setStats(PlayerStats);
		void push();

	~PlayerFile();
};