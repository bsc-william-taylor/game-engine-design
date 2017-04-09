
#include "Object.h"

Object::Object()
{
    position.set(NULL, NULL);
    size.set(NULL, NULL);
}

Object::~Object()
{
    for (auto& observer : observers)
    {
        delete observer;
    }

    observers.clear();
}

void Object::free(Observer * observer)
{
    for (auto i = 0; i < observers.size(); i++)
    {
        if (observers[i] == observer)
        {
            observers.erase(observers.begin() + i);
            observers.resize(observers.size() - 1);
        }
    }
}

void Object::notify()
{
    for (auto i = 0; i < observers.size(); i++) {
        observers[i]->notify();
    }
}

void Object::accept(Observer * observer)
{
    observers.push_back(observer);
}

void Object::turnOffObservers()
{
    for (auto i = 0; i < observers.size(); i++)
    {
        observers[i]->off();
    }
}

void Object::turnOnObservers()
{
    for (auto i = 0; i < observers.size(); i++)
    {
        observers[i]->on();
    }
}

Vector<int> Object::getPosition()
{
    return position;
}

Vector<int> Object::getSize()
{
    return size;
}

void Object::setPosition(Vector<int>& vec)
{
    position.set(vec.getX(), vec.getY());
}

void Object::setSize(Vector<int>& vec)
{
    size.set(vec.getX(), vec.getY());
}