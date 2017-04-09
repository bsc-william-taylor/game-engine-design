
#pragma once

#include "FileReader.h"
#include "Object.h"
#include "Vector.h"
#include "NPC.h"

class Character;
class Game;

class MonsterFile
{
    FileReader * file;
public:
    MonsterFile(Game&, string);
    ~MonsterFile();

    Character * getCharacter(int);
    MonsterStats getStats(int);
    Colour getColour(int);

    int getMonsterNumbers();

    void setPosition(int, Vector<int>);
    void setStats(int, MonsterStats);
    void push();

    Vector<int> getPosition(int);
    Vector<int> getSize(int);

    cstring getName(int);
};