
/* ------------------------------------------------

	@File		: Object.cpp
	@Date		: 21/11/2013
	@Purpose	:

		Implementation for the Object class

 ------------------------------------------------ */

#include "Object.h"

// Constructor & Deconstructor
Object::Object() {
	// Default positions
	position.set(NULL, NULL);
	size.set(NULL, NULL);
}

Object::~Object(){
	// erase any left observers when object is destroyed
	observers.erase(observers.begin(), observers.end());
}


// Functions
void Object::free(Observer * observer) {
	// find the observer
	for(unsigned int i = 0; i < observers.size(); i++) {
		if(observers[i] == observer) {
			// Erase observer from vector & resize
			observers.erase(observers.begin() + i);
			observers.resize(observers.size() - 1);
		}
	}
}

void Object::notify() {
	// turn notify all bound observers
	for(unsigned int i = 0; i < observers.size(); i++) {
		observers[i]->notify();
	}
}

void Object::accept(Observer * observer) {
	// add observer to vector
	observers.push_back(observer);
}

void Object::turnOffObservers() {
	// turn off all observers
	for(unsigned int i = 0; i < observers.size(); i++) {
		observers[i]->off();
	}
}

void Object::turnOnObservers() {
	// turn on all observers
	for(unsigned int i = 0; i < observers.size(); i++) {
		observers[i]->on();
	}
}

Vector<int> Object::getPosition() {
	return position;
}

Vector<int> Object::getSize() {
	return size;
}

void Object::setPosition(Vector<int>& vec) {
	position.set(vec.getX(), vec.getY());
}

void Object::setSize(Vector<int>& vec) {
	size.set(vec.getX(), vec.getY());
}