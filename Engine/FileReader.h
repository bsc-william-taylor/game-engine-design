
/* ------------------------------------------------

	@File		: FileReader.h
	@Date		: 23/11/2013
	@Purpose	:

		A class that simply reads data from
		a file into a vector. Each element
		in the vector represents a line in the
		file

 ------------------------------------------------ */

#pragma once

#include "Main.h"

class Game;

// Custom type for storing file data
typedef vector<string> FileData;

class FileReader {
	private:

		// Comments & Data stored in different vectors
		FileData Comments;
		FileData Data;

		// various streams
		ofstream WriteFile;
		fstream ReadFile;

		// A filename so the file can be opened later
		string Filename;

	public:

	FileReader(Game&, string&);

		// get methods for the vectors
		FileData& GrabComments();
		FileData& GrabData();

		// Grab & push commands for the file
		void GrabFile();
		void PushFile();

	~FileReader();
};