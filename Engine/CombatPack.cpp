
/* ------------------------------------------------

	@File		: CombatPack.cpp
	@Date		: 21/11/2013
	@Purpose	:

		Class implementation

 ------------------------------------------------ */

#include "CombatPack.h"
 
// Constructor & Deconstructor
CombatPack::CombatPack(ItemFile * file) : Item(file) {
	// set default colour
	SetColour(0.0, 1.0, 0.0);
}

CombatPack::CombatPack() {
	// set default colour
	SetColour(0.0, 1.0, 0.0);
}

CombatPack::~CombatPack() {
	// nothing to delete
}

// Functions
void CombatPack::onConsume(Player * player) {
	// On consume increase the players strength by 2
	PlayerStats& stats = player->getStats();
	stats.Strength += 2;
	turnOffObservers();
	used = true;
}