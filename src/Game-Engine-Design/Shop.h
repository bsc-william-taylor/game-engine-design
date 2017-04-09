
#pragma once

#include "Object.h"
#include "Label.h"
#include "Vector.h"

class Shop : public Object 
{
    Label* shopText;
public:
    Shop();
    ~Shop();

    Label * getLabel();   
};