/* ------------------------------------------------

	@File		: Vector.h
	@Date		: 21/11/2013
	@Purpose	:

		Basic Vector template class for managing
		graphic positions, for now this is a 
		basic implementation.

 ------------------------------------------------ */

#pragma once

// Common header file
#include "Main.h"

template<class Type>
class Vector {
	private:

		Type x;
		Type y;

	public:

	// Copy constructor
	Vector(Vector& vector) {
		 x = vector.x;
		 y = vector.y;
	}

	Vector(Type x, Type y) {
		 this->x = x;
		 this->y = y;
	}

	Vector() {
		x = 0;
		y = 0;
	}

		// Basic get method
		Type getX(){ return x; }
		Type getY(){ return y; }

		// Basic set method
		void set(Type x, Type y) {
			this->x = x;
			this->y = y;
		}

		// Override Operators to allow basic math operations
		Vector& operator+=(Vector& vector) {
			x += vector.getX();
			y += vector.getY();
			return *this;
		}

		Vector& operator-=(Vector& vector) {
			x -= vector.getX();
			y -= vector.getY();
			return *this;
		}

		Vector& operator=(Vector& vector) {
			x = vector.getX();
			y = vector.getY();
			return *this;
		}

	~Vector() {
		// Not Needed
	}
};