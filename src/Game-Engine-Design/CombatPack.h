
/* ------------------------------------------------

	@File		: CombatPack.cpp
	@Date		: 21/11/2013
	@Purpose	:

		A class that inherits the item base 
		class and adds to the player strength if
		they hit the item. It is a small class
		as a more detailed implementation
		is expected to happen after the first
		slice requirement

 ------------------------------------------------ */

#pragma once

#include "ItemFile.h"
#include "Player.h"
#include "Item.h"

class CombatPack : public Item {
	public:
	CombatPack(ItemFile *);
	CombatPack();

		void onConsume(Player *);

	~CombatPack();
};