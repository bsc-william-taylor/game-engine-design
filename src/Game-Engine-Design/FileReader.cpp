
#include "FileReader.h"
#include "Game.h"

FileReader::FileReader(Game& game, string& filename)
{
    readFile.open(filename.c_str());

    if (!readFile.is_open())
    {
        readFile.close();
        game.exitError("Error Loading Game Files Please RE-INSTALL");
    }

    filename = filename;
    grabFile();

    if (readFile.is_open()) 
    {
        readFile.close();
    }
}

FileReader::~FileReader()
{
    pushFile();
}

void FileReader::grabFile() 
{
    commentsData.clear();
    fileData.clear();

    while (!readFile.eof()) 
    {
        string data;

        while (!readFile.eof()) 
        {
            getline(readFile, data);
            if (data[0] == '#' || data.empty()) 
            {
                commentsData.push_back(data);
            }
            else 
            {
                commentsData.push_back("insert");
                break;
            }
        };

        fileData.push_back(data);
    }
}

void FileReader::pushFile() 
{
    writeFile.open(filename.c_str());

    for (auto i = 0, z = 0; i < commentsData.size(); i++) 
    {
        if (commentsData[i] != "insert") 
        {
            writeFile << commentsData[i] + "\n";
        }

        if (commentsData[i] == "insert") 
        {
            if (z < fileData.size()) 
            {
                writeFile << fileData[z] + "\n";
            }
            z++;
        }
    }

    if (writeFile.is_open()) 
    {
        writeFile.close();
    }
}

FileData& FileReader::grabComments() 
{
    return commentsData;
}

FileData& FileReader::grabData() 
{
    return fileData;
}