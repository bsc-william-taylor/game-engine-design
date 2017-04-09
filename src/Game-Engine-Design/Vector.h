
#pragma once

#include "Main.h"

template<class Type>
class Vector
{
private:
    Type x;
    Type y;

public:
    Vector(Vector& vector)
    {
        x = vector.x;
        y = vector.y;
    }

    Vector(Type x, Type y)
    {
        this->x = x;
        this->y = y;
    }

    Vector()
    {
        x = 0;
        y = 0;
    }

    ~Vector() {}

    void set(Type x, Type y) 
    {
        this->x = x;
        this->y = y;
    }

    Vector& operator+=(Vector& vector) 
    {
        x += vector.getX();
        y += vector.getY();
        return *this;
    }

    Vector& operator-=(Vector& vector) 
    {
        x -= vector.getX();
        y -= vector.getY();
        return *this;
    }

    Vector& operator=(Vector& vector) 
    {
        x = vector.getX();
        y = vector.getY();
        return *this;
    }

    Type getX()
    {
        return x;
    }

    Type getY()
    {
        return y;
    }
};