
#pragma once

#include "Observer.h"
#include "Objects.h"

class Collision : public Observer 
{
public:
    Collision(Object *, Object *);
    ~Collision();

    void update();    
};