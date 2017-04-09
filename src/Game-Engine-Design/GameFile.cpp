
#include "GameFile.h"

enum GameFileEnum
{
    PUBLISHER_NAME,
    STUDIO_NAME,
    MY_NAME,
    TITLE,
    DEBUG,
    WND_X,
    WND_Y,
    WND_W,
    WND_H,
};

GameFile::GameFile(Game& game, string filename)
{
    file = new FileReader(game, filename);
}

GameFile::~GameFile()
{
    delete file;
}

Vector<int> GameFile::getWindowSize()
{
    int x = atoi(file->GrabData()[WND_W].c_str());
    int y = atoi(file->GrabData()[WND_H].c_str());

    return Vector<int>(x, y);
}

Vector<int> GameFile::getWindowPos()
{
    int x = atoi(file->GrabData()[WND_X].c_str());
    int y = atoi(file->GrabData()[WND_Y].c_str());

    return Vector<int>(x, y);
}

const string& GameFile::getCreatorName()
{
    return file->GrabData()[MY_NAME];
}

const string& GameFile::getPublisherName()
{
    return file->GrabData()[PUBLISHER_NAME];
}

const string& GameFile::getStudioName()
{
    return file->GrabData()[STUDIO_NAME];
}

cstring GameFile::getWindowTitle()
{
    return file->GrabData()[TITLE].c_str();
}

bool GameFile::DebugEnabled()
{
    return static_cast<bool>(atoi(file->GrabData()[DEBUG].c_str()));
}