
/* ------------------------------------------------

	@File		: Character.cpp
	@Date		: 21/11/2013
	@Purpose	:

		Character class implementation


 ------------------------------------------------ */
#include "Character.h"

// Constructor & Deconstructor
Character::Character(Character& character) {
	setPosition(character.getPosition());
	setSize(character.getSize());
	colour = character.getColour();
	num = character.num;

	text.SetText("Data/MavenPro-Regular.ttf", 13);
}

Character::Character() {
	text.SetText("Data/MavenPro-Regular.ttf", 13);

	colour.r = 0.0f;
	colour.g = 0.0f;
	colour.b = 0.0f;
}

Character::~Character() {
	// nothing to delete
}

// Functions
void Character::setNum(int number) {
	this->num = number; 
}

Label * Character::getLabel() {
	return &text;
}

Colour& Character::getColour() {
	return colour;
}