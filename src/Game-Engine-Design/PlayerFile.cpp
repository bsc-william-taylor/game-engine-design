
#include "PlayerFile.h"
#include "Game.h"

enum playerFile
{
    PLAYER_NAME,
    PLAYER_X,
    PLAYER_Y,
    PLAYER_W,
    PLAYER_H,
    START_X,
    START_Y,
    RED,
    GREEN,
    BLUE,
    PLAYER_START_HEALTH,
    PLAYER_START_STRENGTH,
    PLAYER_START_SPEED,
    PLAYER_STRENGTH,
    PLAYER_HEALTH,
    PLAYER_SPEED,
    PLAYER_CASH,
    PLAYER_DEAD,
};

PlayerFile::PlayerFile(Game& game, string filename)
{
    file = new FileReader(game, filename);
}

PlayerFile::~PlayerFile()
{
    delete file;
}

Vector<int> PlayerFile::getPosition()
{
    int x = atoi(file->grabData()[PLAYER_X].c_str());
    int y = atoi(file->grabData()[PLAYER_Y].c_str());

    return Vector<int>(x, y);
}

void PlayerFile::push()
{
    file->pushFile();
}

PlayerStats PlayerFile::getStats()
{
    PlayerStats stats;
    stats.StartHealth = atoi(file->grabData()[PLAYER_START_HEALTH].c_str());
    stats.StartStrength = atoi(file->grabData()[PLAYER_START_STRENGTH].c_str());
    stats.StartSpeed = atoi(file->grabData()[PLAYER_START_SPEED].c_str());
    stats.Strength = atoi(file->grabData()[PLAYER_STRENGTH].c_str());
    stats.Health = atoi(file->grabData()[PLAYER_HEALTH].c_str());
    stats.Speed = atoi(file->grabData()[PLAYER_SPEED].c_str());
    stats.Cash = atoi(file->grabData()[PLAYER_CASH].c_str());
    stats.Dead = atoi(file->grabData()[PLAYER_DEAD].c_str());
    return stats;
}

Colour PlayerFile::getColour()
{
    Colour colour;
    colour.r = (float)atof(file->grabData()[RED].c_str());
    colour.g = (float)atof(file->grabData()[GREEN].c_str());
    colour.b = (float)atof(file->grabData()[BLUE].c_str());
    return colour;
}

string PlayerFile::getName()
{
    return file->grabData()[PLAYER_NAME];
}

void PlayerFile::setPosition(Vector<int> position)
{
    file->grabData()[PLAYER_X] = to_string(position.getX());
    file->grabData()[PLAYER_Y] = to_string(position.getY());
}

void PlayerFile::setStats(PlayerStats stats)
{
    file->grabData()[PLAYER_START_HEALTH] = to_string(stats.StartHealth).append("   // Start Health");
    file->grabData()[PLAYER_START_STRENGTH] = to_string(stats.StartStrength).append("   // Start Strength");
    file->grabData()[PLAYER_START_SPEED] = to_string(stats.StartSpeed).append("   // Start Speed");
    file->grabData()[PLAYER_STRENGTH] = to_string(stats.Strength).append("   // Strength");
    file->grabData()[PLAYER_HEALTH] = to_string(stats.Health).append("   // Health");
    file->grabData()[PLAYER_SPEED] = to_string(stats.Speed).append("   // Speed");
    file->grabData()[PLAYER_CASH] = to_string(stats.Cash).append("   // Cash");
    file->grabData()[PLAYER_DEAD] = to_string(stats.Dead).append("   //Dead");
}

Vector<int> PlayerFile::getStart()
{
    int x = atoi(file->grabData()[START_X].c_str());
    int y = atoi(file->grabData()[START_Y].c_str());

    return Vector<int>(x, y);
}

Vector<int> PlayerFile::getSize()
{
    int w = atoi(file->grabData()[PLAYER_W].c_str());
    int h = atoi(file->grabData()[PLAYER_H].c_str());

    return Vector<int>(w, h);
}