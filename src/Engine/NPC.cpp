
/* ------------------------------------------------

	@File		: NPC.cpp
	@Date		: 21/11/2013
	@Purpose	:

		This is a class the construct enemys
		for the player to batter it has its
		own stats and has its own various 
		functions.

 ------------------------------------------------ */

#include "MonsterFile.h"
#include "Objects.h"
#include "Player.h"
#include "NPC.h"

// Constructor & Deconstructor
NPC::NPC(Character * charector) : Character(*charector) {
	this->file = NULL;
}

NPC::NPC(MonsterFile * file) : Character() {
	this->file = file;
}

NPC::~NPC() {
	// Nothing to delete
}

// Functions
void NPC::DropItem(Player * player) {
	// add cash to the player
	player->getStats().Cash += getStats().Cash;
	
	// get drop item chances
	int chances = stats.DropChance;
	int base = rand() % 100;

	// if the monster should drop an item.
	if(rand() % 100 < chances) {
		// see which item it should drop
		if(base > 80 && base < 80) {
			// create the item & consume
			CombatPack itemDrop;
			itemDrop.onConsume(player);
		} else if(base < 60){
			// create the item & consume
			HealthPack itemDrop;
			itemDrop.onConsume(player);
		} else {
			// create the item & consume
			StimulantPack itemDrop;
			itemDrop.onConsume(player);
		}
	}
}

void NPC::Reset() {
	// reset the monster position and stats to the default stats
	stats = file->getStats(num);
	stats.Health = file->getStats(num).StartHealth;
	stats.Dead = 0;

	// push changes to the file
	file->setStats(num, stats);
	file->push();

	// turn on observers
	turnOnObservers();
}

bool NPC::isKilled() {
	return stats.Dead;
}

void NPC::Load() {
	// Load name
	text.TextToTexture(file->getName(num));

	// & positions
	int x = file->getPosition(num).getX();
	int y = file->getPosition(num).getY();
	int w = file->getSize(num).getX();
	int h = file->getSize(num).getY();

	colour = file->getColour(num);
	stats = file->getStats(num);

	// if the NPC is already dead
	if(stats.Dead) {
		// make sure the game is set up that way
		Kill();
	}

	// set current position to that read from the file
	setPosition(Vector<int>(x, y));
	setSize(Vector<int>(w, h));
}

void NPC::Save() {
	// save position & stats
	file->setPosition(num, getPosition());
	file->setStats(num, stats);
	file->push();
}

void NPC::Kill() {
	stats.Dead = true;
	turnOffObservers();
}