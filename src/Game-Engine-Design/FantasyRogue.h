
#pragma once

#include "Main.h"
#include "Game.h"

class FantasyRogue : public Game 
{
public:
    FantasyRogue();
    ~FantasyRogue();

    void initialise();
    void start();
};