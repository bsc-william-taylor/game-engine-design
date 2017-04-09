
#pragma once

#include "Observer.h"
#include "Vector.h"
#include "Main.h"

struct Colour 
{
    float r, g, b;
};

class Object
{
protected:
    vector<Observer *> observers;
    Vector<int> position;
    Vector<int> size;
public:
    Object();
    virtual ~Object();

    void setPosition(Vector<int>&);
    void setSize(Vector<int>&);
    void accept(Observer *);
    void free(Observer *);
    void notify();

    Vector<int> getPosition();
    Vector<int> getSize();

    void turnOffObservers();
    void turnOnObservers();
};
