
/* ------------------------------------------------

	@File		: Player.cpp
	@Date		: 21/11/2013
	@Purpose	:

		This is the players class, and it has 
		its own stats, and a some functions
		for moving the player around the map.

 ------------------------------------------------ */

#include "PlayerFile.h"
#include "Player.h"

// Constructor & Deconstructor
Player::Player(PlayerFile * file) : Character() {
	this->playerfile = file;
	Load();
}

Player::~Player() {
	// nothing to delete
}

// Functions
void Player::Reset() {
	// Reset stats by getting the starting stats
	int x = playerfile->getStart().getX();
	int y = playerfile->getStart().getY();

	playerStats = playerfile->getStats();

	// and set the to the current stats
	playerStats.Strength = playerStats.StartStrength;
	playerStats.Health = playerStats.StartHealth;
	playerStats.Speed = playerStats.StartSpeed;
	playerStats.Cash = 0;
	playerStats.Dead = 0;

	playerfile->setPosition(Vector<int>(x, y));
	playerfile->setStats(playerStats);
	playerfile->push();

	turnOnObservers();
}

void Player::Load() {
	// load the players name as a label
	text.TextToTexture(playerfile->getName());

	// set position
	int x = playerfile->getPosition().getX();
	int y = playerfile->getPosition().getY();
	int w = playerfile->getSize().getX();
	int h = playerfile->getSize().getY();

	// & get stats
	playerStats = playerfile->getStats();
	colour = playerfile->getColour();

	setPosition(Vector<int>(x, y));
	setSize(Vector<int>(w, h));
}

void Player::Save() {
	Vector<int> position = getPosition();

	// save current position
	playerfile->setPosition(position);
	playerfile->setStats(playerStats);

	// push changes to the file
	playerfile->push();
}

void Player::Kill() {
	// change the stats to show that the player is dead
	playerStats.Dead = true;
	// & turn off observers
	turnOffObservers();
}

void Player::moveX(int x) {
	position.set(position.getX() + x, position.getY());
	// notify observers is the player is moving
	if(!playerStats.Dead) {
		notify();
	}
}

void Player::moveY(int y) {
	position.set(position.getX(), position.getY() + y);
	// notify observers is the player is moving
	if(!playerStats.Dead) {
		notify();
	}
}