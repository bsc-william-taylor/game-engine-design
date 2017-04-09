
#pragma once

#include "Main.h"

class Game;

typedef vector<string> FileData;

class FileReader 
{
private:
    FileData commentsData;
    FileData fileData;

    ofstream writeFile;
    fstream readFile;
    string filename;
public:
    FileReader(Game&, string&);
    ~FileReader();

    FileData& grabComments();
    FileData& grabData();

    void grabFile();
    void pushFile();
};