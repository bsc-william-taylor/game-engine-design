
/* ------------------------------------------------

	@File		: PlayerFile.cpp
	@Date		: 21/11/2013
	@Purpose	:

		PlayerFile class implementation

 ------------------------------------------------ */

#include "PlayerFile.h"
#include "Game.h"

#pragma region Constants
enum playerFile {
	PLAYER_NAME, 
	PLAYER_X, 
	PLAYER_Y, 
	PLAYER_W, 
	PLAYER_H, 
	START_X, 
	START_Y, 
	RED,
	GREEN,
	BLUE,
	PLAYER_START_HEALTH,
	PLAYER_START_STRENGTH,
	PLAYER_START_SPEED,
	PLAYER_STRENGTH, 
	PLAYER_HEALTH, 
	PLAYER_SPEED,
	PLAYER_CASH,
	PLAYER_DEAD, 
};
#pragma endregion


PlayerFile::PlayerFile(Game& game, string filename) {
	file = new FileReader(game, filename);
}

Vector<int> PlayerFile::getPosition() {
	int x = atoi(file->GrabData()[PLAYER_X].c_str());
	int y = atoi(file->GrabData()[PLAYER_Y].c_str());

	return Vector<int>(x, y);
}

void PlayerFile::push() {
	file->PushFile();
}

PlayerStats PlayerFile::getStats() {
	PlayerStats stats;

	stats.StartHealth = atoi(file->GrabData()[PLAYER_START_HEALTH].c_str());
	stats.StartStrength = atoi(file->GrabData()[PLAYER_START_STRENGTH].c_str());
	stats.StartSpeed = atoi(file->GrabData()[PLAYER_START_SPEED].c_str());
	stats.Strength = atoi(file->GrabData()[PLAYER_STRENGTH].c_str());
	stats.Health = atoi(file->GrabData()[PLAYER_HEALTH].c_str());
	stats.Speed = atoi(file->GrabData()[PLAYER_SPEED].c_str());
	stats.Cash = atoi(file->GrabData()[PLAYER_CASH].c_str());
	stats.Dead = atoi(file->GrabData()[PLAYER_DEAD].c_str());

	return stats;
}

Colour PlayerFile::getColour() {
	Colour colour;

	colour.r = (float)atof(file->GrabData()[RED].c_str());
	colour.g = (float)atof(file->GrabData()[GREEN].c_str());
	colour.b = (float)atof(file->GrabData()[BLUE].c_str());

	return colour;
}

string PlayerFile::getName() {
	return file->GrabData()[PLAYER_NAME];
}

void PlayerFile::setPosition(Vector<int> position) {
	file->GrabData()[PLAYER_X] = to_string(position.getX());
	file->GrabData()[PLAYER_Y] = to_string(position.getY());
}

void PlayerFile::setStats(PlayerStats stats) {
	file->GrabData()[PLAYER_START_HEALTH] = to_string(stats.StartHealth).append("   // Start Health");
	file->GrabData()[PLAYER_START_STRENGTH] = to_string(stats.StartStrength).append("   // Start Strength");
	file->GrabData()[PLAYER_START_SPEED] = to_string(stats.StartSpeed).append("   // Start Speed");
	file->GrabData()[PLAYER_STRENGTH] = to_string(stats.Strength).append("   // Strength");
	file->GrabData()[PLAYER_HEALTH] = to_string(stats.Health).append("   // Health");
	file->GrabData()[PLAYER_SPEED] = to_string(stats.Speed).append("   // Speed");
	file->GrabData()[PLAYER_CASH] = to_string(stats.Cash).append("   // Cash");
	file->GrabData()[PLAYER_DEAD] = to_string(stats.Dead).append("   //Dead");
}

Vector<int> PlayerFile::getStart() {
	int x = atoi(file->GrabData()[START_X].c_str());
	int y = atoi(file->GrabData()[START_Y].c_str());

	return Vector<int>(x, y);
}

Vector<int> PlayerFile::getSize() {
	int w = atoi(file->GrabData()[PLAYER_W].c_str());
	int h = atoi(file->GrabData()[PLAYER_H].c_str());

	return Vector<int>(w, h);
}

PlayerFile::~PlayerFile() {
	delete file;
}