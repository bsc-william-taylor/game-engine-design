
#pragma once

#include "Observer.h"
#include "Object.h"

class Border : public Observer 
{
public:
    Border(Object *);
    ~Border();

    void update();
};
