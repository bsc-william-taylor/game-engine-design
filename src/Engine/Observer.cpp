
/* ------------------------------------------------

	@File		: Observer.cpp
	@Date		: 21/11/2013
	@Purpose	:

		Observer class implementation		

 ------------------------------------------------ */

#include "Observer.h"
#include "Object.h"

// Constructor's & Deconstructor
Observer::Observer(Object * object, Object * node) {
	this->object = object;
	this->object->accept(this);
	
	this->node = node;
	this->node->accept(this);
	
	triggered = false;
	active = true;
}

Observer::Observer(Object * object) {
	this->object = object;
	this->object->accept(this);

	node = NULL;
	triggered = false;
	active = true;
}

Observer::~Observer() {
	object->free(this);
	object = NULL;
}

// Functions
bool Observer::hasTriggered() {
	return triggered;
}

void Observer::off() {
	active = false;
}

void Observer::on() {
	active = true;
}

void Observer::reset(){ 
	triggered = false; 
}

void Observer::notify(){
	update();
}