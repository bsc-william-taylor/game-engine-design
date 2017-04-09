
/* ------------------------------------------------

	@File		: HealthPack.cpp
	@Date		: 21/11/2013
	@Purpose	:

		Class implementation

 ------------------------------------------------ */

#include "HealthPack.h"

// Constructor & Deconstructor
HealthPack::HealthPack(ItemFile * file) : Item(file){
	// Nothing to create Item constructor does it
	// for us
}

HealthPack::HealthPack() {
	// Nothing to create Item constructor does it
	// for us
}

HealthPack::~HealthPack() {
	// Nothing to delete
}

// Functions
void HealthPack::onConsume(Player * player) {
	PlayerStats& stats = player->getStats();
	
	if(stats.Health < stats.StartHealth) {
		stats.Health = stats.StartHealth;
	} else {
		stats.Health++;
	}

	turnOffObservers();
	used = true;
}