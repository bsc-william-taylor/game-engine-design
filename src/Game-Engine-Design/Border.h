
/* ------------------------------------------------

	@File		: Border.h
	@Date		: 21/11/2013
	@Purpose	:

		The following is a simple observer
		that stops any object moving from
		the world map.

 ------------------------------------------------ */

#pragma once

#include "Observer.h"
#include "Object.h"

class Border : public Observer {
	public:
	Border(Object *);
	
		void update();

	~Border();
};
