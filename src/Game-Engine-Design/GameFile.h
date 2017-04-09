
#pragma once

#include "FileReader.h"
#include "Vector.h"

class Game;

class GameFile 
{
    FileReader * file;
public:
    GameFile(Game&, string);
    ~GameFile();

    Vector<int> getWindowSize();
    Vector<int> getWindowPos();

    const string& getPublisherName();
    const string& getCreatorName();
    const string& getStudioName();

    cstring getWindowTitle();

    bool DebugEnabled();
};