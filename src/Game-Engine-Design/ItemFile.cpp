
/* ------------------------------------------------

	@File		: ItemFile.h
	@Date		: 21/11/2013
	@Purpose	:

		ItemFile class implementation

 ------------------------------------------------ */

#include "ItemFile.h"

#pragma region Constants
enum Items {
	ITEM_NUM,
	ITEM_NAME,
	ITEM_X,
	ITEM_Y,	
	ITEM_W, 
	ITEM_H,
	CONSUMED,
	ITEM_DETAILS = 6
};
#pragma endregion

// Constructor & Deconstructor
ItemFile::ItemFile(Game& game, string filename) {
	file = new FileReader(game, filename);
}

ItemFile::~ItemFile() {
	delete file;
}

//Functions
void ItemFile::setPosition(int num, Vector<int> position) {
	file->GrabData()[num + ITEM_X] = to_string(position.getX());
	file->GrabData()[num + ITEM_Y] = to_string(position.getY());
}
		
Item * ItemFile::getItem(int num) {
	int location = num * ITEM_DETAILS;
	Item * temp;

	string name = getItemName(location);
	
	if(name == "Health" || name == "health") {
		temp = new HealthPack(this);
		temp->SetColour(1.0, 0.0, 0.0);
	} 
	
	if(name == "Combat" || name == "combat") {
		temp = new CombatPack(this);
		temp->SetColour(0.0, 0.0, 1.0);
	} 

	if(name == "Stimulant" || name == "stimulant") {
		temp = new StimulantPack(this);
		temp->SetColour(0.0, 1.0, 0.0);
	}

	temp->SetItemNumber(location);
	return temp;
}

Vector<int> ItemFile::getItemPosition(int num) {
	int x = atoi(file->GrabData()[num + ITEM_X].c_str());
	int y = atoi(file->GrabData()[num + ITEM_Y].c_str());

	return Vector<int>(x, y);
}

void ItemFile::push() {
	file->PushFile();
}

void ItemFile::setState(int num, bool state) {
	file->GrabData()[num + CONSUMED] = to_string(state);
}

Vector<int> ItemFile::getItemSize(int num) {
	int w = atoi(file->GrabData()[num + ITEM_W].c_str());
	int h = atoi(file->GrabData()[num + ITEM_H].c_str());

	return Vector<int>(w, h);
}

bool ItemFile::getItemState(int num) {
	return atoi(file->GrabData()[num + CONSUMED].c_str());
}

cstring ItemFile::getItemName(int num) {
	return file->GrabData()[num + ITEM_NAME].c_str();
}

int ItemFile::getItemNumbers() {
	return atoi(file->GrabData()[ITEM_NUM].c_str());
}