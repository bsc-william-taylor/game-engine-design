
/* ------------------------------------------------

	@File		: StimulantPack.cpp
	@Date		: 21/11/2013
	@Purpose	:

		Class implementation

 ------------------------------------------------ */

#include "StimulantPack.h"

// Constructor & Deconstructor
StimulantPack::StimulantPack(ItemFile * file) : Item(file) {
	// set a default colour
	SetColour(0.0, 0.0, 1.0);
}

StimulantPack::StimulantPack() {
	// set a default colour
	SetColour(0.0, 0.0, 1.0);
}

StimulantPack::~StimulantPack() {
	// ntohing to delete
}

// Functions
void StimulantPack::onConsume(Player * player) {
	// on consume increment the players speed
	PlayerStats& stats = player->getStats();
	stats.Speed++;
	turnOffObservers();
	used = true;
}