
#pragma once

#include "Main.h"

class Object;

class Observer
{
protected:
    Object * object;
    Object * node;

    bool triggered;
    bool active;
public:
    Observer(Object *, Object *);
    Observer(Object *);

    virtual ~Observer();
    virtual void update() = 0;

    bool hasTriggered();

    Object * getObject() { return object; }
    Object * getNode() { return node; }

    void notify();
    void reset();
    void off();
    void on();
};