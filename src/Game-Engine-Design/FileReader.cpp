
#include "FileReader.h"
#include "Game.h"

FileReader::FileReader(Game& game, string& filename)
{
    ReadFile.open(filename.c_str());

    if (!ReadFile.is_open())
    {
        ReadFile.close();
        game.ExitError("Error Loading Game Files Please RE-INSTALL");
    }

    Filename = filename;
    GrabFile();

    if (ReadFile.is_open()) 
    {
        ReadFile.close();
    }
}

FileReader::~FileReader()
{
    PushFile();
}

void FileReader::GrabFile() 
{
    Comments.clear();
    Data.clear();

    while (!ReadFile.eof()) 
    {
        string data;

        while (!ReadFile.eof()) 
        {
            getline(ReadFile, data);
            if (data[0] == '#' || data.empty()) 
            {
                Comments.push_back(data);
            }
            else 
            {
                Comments.push_back("insert");
                break;
            }
        };

        Data.push_back(data);
    }
}

void FileReader::PushFile() 
{
    WriteFile.open(Filename.c_str());

    for (auto i = 0, z = 0; i < Comments.size(); i++) 
    {
        if (Comments[i] != "insert") 
        {
            WriteFile << Comments[i] + "\n";
        }

        if (Comments[i] == "insert") 
        {
            if (z < Data.size()) 
            {
                WriteFile << Data[z] + "\n";
            }
            z++;
        }
    }

    if (WriteFile.is_open()) 
    {
        WriteFile.close();
    }
}

FileData& FileReader::GrabComments() 
{
    return Comments;
}

FileData& FileReader::GrabData() 
{
    return Data;
}