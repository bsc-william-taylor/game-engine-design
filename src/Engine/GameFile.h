
/* ------------------------------------------------

	@File		: GameFile.h
	@Date		: 21/11/2013
	@Purpose	:

		A class that opens the game file
		and gets all relevant data. Game
		settings can then be read by
		various get methods.

 ------------------------------------------------ */

#pragma once

#include "FileReader.h"
#include "Vector.h"

class Game;

class GameFile {
	private:

		// Use file reader to read all data
		FileReader * file;

	public:

	GameFile(Game&, string);
		
		// Various get methods to get data
		Vector<int> getWindowSize();
		Vector<int> getWindowPos();
		
		const string& getPublisherName();
		const string& getCreatorName();
		const string& getStudioName();

		cstring getWindowTitle();

		bool DebugEnabled();	

	~GameFile();
};