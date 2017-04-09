
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
    int x = atoi(file->grabData()[WND_W].c_str());
    int y = atoi(file->grabData()[WND_H].c_str());

    return Vector<int>(x, y);
}

Vector<int> GameFile::getWindowPos()
{
    int x = atoi(file->grabData()[WND_X].c_str());
    int y = atoi(file->grabData()[WND_Y].c_str());

    return Vector<int>(x, y);
}

const string& GameFile::getCreatorName()
{
    return file->grabData()[MY_NAME];
}

const string& GameFile::getPublisherName()
{
    return file->grabData()[PUBLISHER_NAME];
}

const string& GameFile::getStudioName()
{
    return file->grabData()[STUDIO_NAME];
}

cstring GameFile::getWindowTitle()
{
    return file->grabData()[TITLE].c_str();
}

bool GameFile::debugEnabled()
{
    return static_cast<bool>(atoi(file->grabData()[DEBUG].c_str()));
}