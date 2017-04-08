
/* ------------------------------------------------

	@File		: Character.h
	@Date		: 21/11/2013
	@Purpose	:

		This is a class that NPC's and Player
		must inherit as it contains all the features
		that is shared between a NPC & a player.

 ------------------------------------------------ */

#pragma once

#include "Object.h"
#include "Vector.h"
#include "Label.h"

class Character : public Object {
	protected:

		Colour colour;
		Label text;
		int num;

	public:

	Character(Character&);
	Character();
	
			virtual bool isKilled() = 0;
			virtual void Reset() = 0;
			virtual void Load() = 0;
			virtual void Save() = 0;
			virtual void Kill() = 0;

			Colour& getColour();
			Label* getLabel();

			void setNum(int);

	virtual ~Character();
};