
/* ------------------------------------------------

	@File		: Item.cpp
	@Date		: 21/11/2013
	@Purpose	:

		Item class implementation

 ------------------------------------------------ */

#include "ItemFile.h"
#include "Item.h"
#include "Player.h"

// Constructor & Deconstructor
Item::Item(ItemFile * file) {
	this->file = file;
	used = false;
	SetColour(1.0, 0.0, 1.0);
}

Item::Item() {
	file = NULL;
	used = false;
}

Item::~Item() {
	// nothing to delete
}

// Functions
void Item::Load() {
	// load positions from the file
	Vector<int> position = file->getItemPosition(num);
	Vector<int> size = file->getItemSize(num);

	// get the state of the item
	used = file->getItemState(num);

	// randomise the position if position == 0
	if(!position.getX()) {
		position.set(rand() % 720 + 1, position.getY());
	}

	if(!position.getY()) {
		position.set(position.getX(), rand() % 480 + 1);
	}

	// set the position to the position loaded from the file
	setPosition(position);
	setSize(size);
}

void Item::SetColour(float r, float g, float b) {
	// set colour
	colour.r = r;
	colour.g = g;
	colour.b = b;
}

void Item::SetItemNumber(int i) {
	// get the current item number
	num = i;
}

bool Item::isUsed() { 
	// return if the item has been used
	return used; 
}

void Item::Reset() {
	// reset the items position
	file->setPosition(num, Vector<int>(0, 0));
	file->setState(num, false);
	file->push();

	turnOnObservers();
}

void Item::Save() {
	// save the current position & state
	file->setPosition(num, getPosition());
	file->setState(num, used);
	file->push();
}

Colour& Item::getColour() {
	return colour;
}