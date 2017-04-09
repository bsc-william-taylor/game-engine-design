
/* ------------------------------------------------

	@File		: Border.cpp
	@Date		: 21/11/2013
	@Purpose	:

		Class implementation

 ------------------------------------------------ */

#include "Border.h"
#include "Vector.h"

// Constructor & Deconstructor
Border::Border(Object * object)  : Observer(object) {
	this->object = object;
}

Border::~Border() {

}

// Update function
void Border::update() {
	if(active) {
		Vector<int> place = object->getPosition();
		Vector<int> size = object->getSize();

		if(place.getX()  <= 0) {
			object->setPosition(Vector<int>(0, place.getY()));
		}

		if(place.getY() <= 0) {
			object->setPosition(Vector<int>(place.getX(), 0));
		}

		if(place.getX() + size.getX() >= 720) {
			object->setPosition(Vector<int>(720 - size.getX(), place.getY()));
		}

		if(place.getY() + size.getY() >= 480) {
			object->setPosition(Vector<int>(place.getX(), 480 - size.getY()));
		}
	}
}