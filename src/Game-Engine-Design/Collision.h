
/* ------------------------------------------------

	@File		: Collision.h
	@Date		: 21/11/2013
	@Purpose	:

		Collision observer to tell the user
		if a object collides with another
		object in the level.

 ------------------------------------------------ */

#pragma once

#include "Observer.h"
#include "Objects.h"

class Collision : public Observer {
	public:
	Collision(Object *, Object *);

		void update();

	~Collision();
};	