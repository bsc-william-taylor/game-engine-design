
/* ------------------------------------------------

	@File		: Object.h
	@Date		: 21/11/2013
	@Purpose	:

		A abstract class that is to be 
		implemented by objects so that
		observers can be bound to objects
		and so objects can be stored in the 
		factory class

 ------------------------------------------------ */

#pragma once

#include "Observer.h"
#include "Vector.h"
#include "Main.h"

// Custom data type for colour
struct Colour {
	float r;
	float g;
	float b;
};

class Object {
	private:

		// Vector contains all observers
		vector<Observer *> observers;

	protected:

		// Every object should have a position
		Vector<int> position;
		Vector<int> size;

	public:

	Object();

		void setPosition(Vector<int>&);
		void setSize(Vector<int>&);
		void accept(Observer *);
		void free(Observer *);
		void notify();

		Vector<int> getPosition();
		Vector<int> getSize();

		// Activate/Deavtivate Observers
		void turnOffObservers();
		void turnOnObservers();

	virtual ~Object();
};
