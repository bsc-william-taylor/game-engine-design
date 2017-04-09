
/* ------------------------------------------------

	@File		: ItemFile.h
	@Date		: 21/11/2013
	@Purpose	:

		A class that opens the item file
		and gets all relevant data. The engine
		then reads this and constructs the items
		listed in the file.

 ------------------------------------------------ */

#pragma once

#include "FileReader.h"
#include "Objects.h"
#include "Vector.h"

class Item;
class Game;

class ItemFile {
	private:

		FileReader * file;

	public:

	ItemFile(Game&, string);

		Vector<int> getItemPosition(int);
		Vector<int> getItemSize(int);

		cstring getItemName(int);
		Item * getItem(int);
		bool getItemState(int);
		int getItemNumbers();

		void setPosition(int, Vector<int>);
		void setState(int, bool);
		void push();

	~ItemFile();
};