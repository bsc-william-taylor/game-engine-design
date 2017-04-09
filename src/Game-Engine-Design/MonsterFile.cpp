
/* ------------------------------------------------

	@File		: MonsterFile.h
	@Date		: 21/11/2013
	@Purpose	:

		MonsterFile class implementation

 ------------------------------------------------ */

#include "MonsterFile.h"
#include "NPC.h"

#pragma region Constants
enum Monster : unsigned int {
	NUMBERS,
	NAME,  POS_X,
	POS_Y, POS_W,
	POS_H, RED,
	GREEN, BLUE,
	START_HEALTH,
	DROP_CHANCE,
	STRENGTH,
	HEALTH,
	SPEED, 
	CASH,
	DEAD,
	NUM_OF_DETAIL = 15
};
#pragma endregion

// Constructor & Deconstructor
MonsterFile::MonsterFile(Game& game, string filename) {
	file = new FileReader(game, filename);
}

MonsterFile::~MonsterFile() {
	delete file;
}
		
// Functions
MonsterStats MonsterFile::getStats(int num) {
	MonsterStats stats;

	stats.StartHealth = atoi(file->GrabData()[num + START_HEALTH].c_str());
	stats.DropChance = atoi(file->GrabData()[num + DROP_CHANCE].c_str());
	stats.Strength = atoi(file->GrabData()[num + STRENGTH].c_str());
	stats.Health = atoi(file->GrabData()[num + HEALTH].c_str());
	stats.Speed = atoi(file->GrabData()[num + SPEED].c_str());
	stats.Cash = atoi(file->GrabData()[num + CASH].c_str());
	stats.Dead = atoi(file->GrabData()[num + DEAD].c_str());

	return stats;
}

Colour MonsterFile::getColour(int num) {
	Colour colour;

	colour.r = (float)atof(file->GrabData()[num + RED].c_str());
	colour.g = (float)atof(file->GrabData()[num + GREEN].c_str());
	colour.b = (float)atof(file->GrabData()[num + BLUE].c_str());

	return colour;
}

void MonsterFile::push() {
	// Push all changes to the file
	file->PushFile();
}

void MonsterFile::setPosition(int num, Vector<int> position) {
	// Update the position variable
   file->GrabData()[num + POS_X] = to_string(position.getX());
   file->GrabData()[num + POS_Y] = to_string(position.getY());
}

void MonsterFile::setStats(int num, MonsterStats stats) {
	// Write new stats to the file
	file->GrabData()[num + START_HEALTH] = to_string(stats.StartHealth).append(" // Start Health");
	file->GrabData()[num + DROP_CHANCE] = to_string(stats.DropChance).append(" // Drop Chance");
	file->GrabData()[num + STRENGTH] = to_string(stats.Strength).append(" // Strength");
	file->GrabData()[num + HEALTH] = to_string(stats.Health).append(" // Health");
	file->GrabData()[num + SPEED] = to_string(stats.Speed).append(" // Speed");
	file->GrabData()[num + CASH] = to_string(stats.Cash).append(" // Cash");
	file->GrabData()[num + DEAD] = to_string(stats.Dead).append(" // Dead");
}

Character * MonsterFile::getCharacter(int num) {
	Character * character = new NPC(this);
	character->setNum(num * NUM_OF_DETAIL);
	return character;
}

cstring MonsterFile::getName(int num) {
	return file->GrabData()[num + NAME].c_str();
}

Vector<int> MonsterFile::getPosition(int num) {
	int x = atoi(file->GrabData()[num + POS_X].c_str());
	int y = atoi(file->GrabData()[num + POS_Y].c_str());

	return Vector<int>(x, y);
}

Vector<int> MonsterFile::getSize(int num) {
	int w = atoi(file->GrabData()[num + POS_W].c_str());
	int h = atoi(file->GrabData()[num + POS_H].c_str());

	return Vector<int>(w, h);
}

int MonsterFile::getMonsterNumbers(){
	return atoi(file->GrabData()[NUMBERS].c_str());
}