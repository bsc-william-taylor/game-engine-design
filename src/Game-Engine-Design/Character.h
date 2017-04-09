
#pragma once

#include "Object.h"
#include "Vector.h"
#include "Label.h"

class Character : public Object 
{
protected:
    Colour colour;
    Label text;
    int num;
public:
    Character(Character&);
    Character();

    virtual ~Character();
    virtual bool isKilled() = 0;
    virtual void reset() = 0;
    virtual void load() = 0;
    virtual void save() = 0;
    virtual void Kill() = 0;

    Colour& getColour();
    Label* getLabel();

    void setNum(int);
};