
/* ------------------------------------------------

	@File		: FileReader.cpp
	@Date		: 23/11/2013
	@Purpose	:

		FileReader class implementation

 ------------------------------------------------ */

#include "FileReader.h"
#include "Game.h"

// Constructor & Deconstructor
FileReader::FileReader(Game& game, string& filename) {
	ReadFile.open(filename.c_str());
	
	// if the file cant be opened shutdown the game
	if(!ReadFile.is_open()) {
		ReadFile.close();
		game.ExitError("Error Loading Game Files Please RE-INSTALL");
	}

	// Save the filename
	Filename = filename;
	// Grab Data
	GrabFile();

	if(ReadFile.is_open()) {
		ReadFile.close();
	}
}

FileReader::~FileReader() {
	// Push any left changes
	PushFile();
}

// Functions
void FileReader::GrabFile() {
	// Clear vectors 
	Comments.clear();
	Data.clear();

	/* Read all data from the file. Store comments
	   in one vector & details in another.		*/
	while(!ReadFile.eof()) {
		string data;
		while(!ReadFile.eof()) {
			getline(ReadFile, data);

			// Comments are marked as a #
			if(data[0] == '#' || data.empty()) {
				Comments.push_back(data);
			} else {
				Comments.push_back("insert");
				break;
			}
		};
		Data.push_back(data);
	}
}

void FileReader::PushFile() {
	// Truncate File
	WriteFile.open(Filename.c_str());

	// Merge vectors to create the original file
	unsigned int z = 0;
	for(unsigned int i = 0; i < Comments.size(); i++) {
		if(Comments[i] != "insert") {
			WriteFile << Comments[i] + "\n"; 
		}

		if(Comments[i] == "insert") {
			if(z < Data.size()) {
				WriteFile << Data[z] + "\n"; 
			}
			z++;
		} 
	}

	// Close the file
	if(WriteFile.is_open()) {
		WriteFile.close();
	}
}

FileData& FileReader::GrabComments() {
	// return a reference to the vector
	return Comments;
}

FileData& FileReader::GrabData() {
	// return a reference to the vector
	return Data;
}