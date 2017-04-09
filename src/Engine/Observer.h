
/* ------------------------------------------------

	@File		: Observer.h
	@Date		: 21/11/2013
	@Purpose	:

		A abstract class that is to be inherited
		by custom observers so they can be 
		attached and notified by objects when
		new events occur.

 ------------------------------------------------ */

#pragma once

#include "Main.h"

class Object;

class Observer {
	protected:

		Object * object;
		Object * node;

		bool triggered;
		bool active;

	public:

	// Observers can observe 1 || 2 objects.
	Observer(Object *, Object *);
	Observer(Object *);

		virtual void update() = 0;
		
		// To see if the event has been triggered
		bool hasTriggered();

		Object * getObject(){ return object; }
		Object * getNode(){ return node; }

		void notify();
		void reset();
		void off();
		void on();

	virtual ~Observer();
};