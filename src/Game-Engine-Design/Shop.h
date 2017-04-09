
/* ------------------------------------------------

	@File		: Shop.h
	@Date		: 21/11/2013
	@Purpose	:

		A simple shop asset that can 
		be drawn on the map, very basic 
		but is its own type so it can be 
		devoloped over time.

 ------------------------------------------------ */

#pragma once

#include "Object.h"
#include "Label.h"
#include "Vector.h"

class Shop : public Object {
	private:

		Label * shopText;
		
	public:
	Shop();
	
		Label * getLabel();

	~Shop();
};