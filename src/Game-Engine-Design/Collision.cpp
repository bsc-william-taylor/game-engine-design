
/* ------------------------------------------------

	@File		: Collision.cpp
	@Date		: 21/11/2013
	@Purpose	:

		Collision implementation


 ------------------------------------------------ */

#include "Collision.h"

// Constructor & Deconstructor
Collision::Collision(Object* object, Object * node) : Observer(object, node) {
	triggered = false;
	active = true;
}

Collision::~Collision() {

}

// Update Function
void Collision::update() {
	if(active) {
		Vector<int> pos = object->getPosition();
		Vector<int> size = object->getSize();
	
		Vector<int> nodeSize = node->getSize();
		Vector<int> nodePos = node->getPosition();

		if(pos.getX() <= nodePos.getX() + nodeSize.getX() && pos.getX() + size.getX() > nodePos.getX() ) {
			if(pos.getY() <= nodePos.getY() + nodeSize.getY() && pos.getY() + size.getY() >= nodePos.getY()) {
				triggered = true;
			}
		}
	}
}
