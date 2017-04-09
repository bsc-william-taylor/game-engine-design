
/* ------------------------------------------------

	@File		: Item.h
	@Date		: 21/11/2013
	@Purpose	:

		A base class which items must inherit
		& define what should happen the player
		consumes the item on contact

 ------------------------------------------------ */

#pragma once

#include "Object.h"

class ItemFile;
class Player;

class Item : public Object  {
	protected:

		ItemFile * file;
		Colour colour;
		bool used;
		int num;

	public:

	Item(ItemFile *);
	Item();

		virtual void onConsume(Player *) = 0;
		
		void SetColour(float, float, float);
		void SetItemNumber(int);
		void Reset();
		void Load();
		void Save();

		bool isUsed();

		Colour& getColour();

	~Item();
};