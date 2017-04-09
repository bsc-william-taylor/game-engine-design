
/* ------------------------------------------------

	@File		: MonsterFile.h
	@Date		: 21/11/2013
	@Purpose	:

		A class that opens the item file
		and gets all relevant data. The engine
		then reads this and constructs the monsters
		listed in the file.

 ------------------------------------------------ */

#pragma once

#include "FileReader.h"
#include "Object.h"
#include "Vector.h"
#include "NPC.h"

class Character;
class Game;

class MonsterFile {
	private:

		FileReader * file;

	public:

	MonsterFile(Game&, string);
		
		// get & set methods so data can be updated
		Character * getCharacter(int);
		MonsterStats getStats(int);
		Colour getColour(int);

		int getMonsterNumbers();

		void setPosition(int, Vector<int>);
		void setStats(int, MonsterStats);
		void push();

		Vector<int> getPosition(int);
		Vector<int> getSize(int);

		cstring getName(int);

	~MonsterFile();
};