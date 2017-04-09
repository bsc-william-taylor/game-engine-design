
/* ------------------------------------------------

	@File		: HealthPack.h
	@Date		: 21/11/2013
	@Purpose	:

		A class that inherits the item base 
		class and heals the player is they
		hit the item. It is a small class
		as a more detailed implementation
		is expected to happen after the first
		slice requirement

 ------------------------------------------------ */

#pragma once

#include "ItemFile.h"
#include "Item.h"

class HealthPack : public Item {
	public:

	HealthPack(ItemFile *);
	HealthPack();

		void onConsume(Player *);

	~HealthPack();
};