
#pragma once

#include "Main.h"

class Game;

typedef vector<string> FileData;

class FileReader 
{
private:
    FileData Comments;
    FileData Data;

    ofstream WriteFile;
    fstream ReadFile;
    string Filename;
public:
    FileReader(Game&, string&);
    ~FileReader();

    FileData& GrabComments();
    FileData& GrabData();

    void GrabFile();
    void PushFile();
};