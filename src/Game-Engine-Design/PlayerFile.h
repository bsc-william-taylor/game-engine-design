
#pragma once

#include "FileReader.h"
#include "Objects.h"
#include "Vector.h"

class Character;
class Game;

class PlayerFile
{
    FileReader* file;
public:
    PlayerFile(Game&, string);
    ~PlayerFile();

    PlayerStats getStats();
    Colour getColour();
    string getName();

    Vector<int> getPosition();
    Vector<int> getStart();
    Vector<int> getSize();

    void setPosition(Vector<int>);
    void setStats(PlayerStats);
    void push();
};