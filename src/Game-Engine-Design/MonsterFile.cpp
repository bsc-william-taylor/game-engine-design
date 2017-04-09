
#include "MonsterFile.h"
#include "NPC.h"

enum MonsterEnum
{
    NUMBERS,
    NAME, POS_X,
    POS_Y, POS_W,
    POS_H, RED,
    GREEN, BLUE,
    START_HEALTH,
    DROP_CHANCE,
    STRENGTH,
    HEALTH,
    SPEED,
    CASH,
    DEAD,
    NUM_OF_DETAIL = 15
};

MonsterFile::MonsterFile(Game& game, string filename)
{
    file = new FileReader(game, filename);
}

MonsterFile::~MonsterFile()
{
    delete file;
}

MonsterStats MonsterFile::getStats(int num)
{
    MonsterStats stats;
    stats.StartHealth = atoi(file->grabData()[num + START_HEALTH].c_str());
    stats.DropChance = atoi(file->grabData()[num + DROP_CHANCE].c_str());
    stats.Strength = atoi(file->grabData()[num + STRENGTH].c_str());
    stats.Health = atoi(file->grabData()[num + HEALTH].c_str());
    stats.Speed = atoi(file->grabData()[num + SPEED].c_str());
    stats.Cash = atoi(file->grabData()[num + CASH].c_str());
    stats.Dead = atoi(file->grabData()[num + DEAD].c_str());
    return stats;
}

Colour MonsterFile::getColour(int num)
{
    Colour colour;
    colour.r = (float)atof(file->grabData()[num + RED].c_str());
    colour.g = (float)atof(file->grabData()[num + GREEN].c_str());
    colour.b = (float)atof(file->grabData()[num + BLUE].c_str());
    return colour;
}

void MonsterFile::push()
{
    file->pushFile();
}

void MonsterFile::setPosition(int num, Vector<int> position)
{
    file->grabData()[num + POS_X] = to_string(position.getX());
    file->grabData()[num + POS_Y] = to_string(position.getY());
}

void MonsterFile::setStats(int num, MonsterStats stats)
{
    file->grabData()[num + START_HEALTH] = to_string(stats.StartHealth).append(" // Start Health");
    file->grabData()[num + DROP_CHANCE] = to_string(stats.DropChance).append(" // Drop Chance");
    file->grabData()[num + STRENGTH] = to_string(stats.Strength).append(" // Strength");
    file->grabData()[num + HEALTH] = to_string(stats.Health).append(" // Health");
    file->grabData()[num + SPEED] = to_string(stats.Speed).append(" // Speed");
    file->grabData()[num + CASH] = to_string(stats.Cash).append(" // Cash");
    file->grabData()[num + DEAD] = to_string(stats.Dead).append(" // Dead");
}

Character * MonsterFile::getCharacter(int num)
{
    Character * character = new NPC(this);
    character->setNum(num * NUM_OF_DETAIL);
    return character;
}

cstring MonsterFile::getName(int num)
{
    return file->grabData()[num + NAME].c_str();
}

Vector<int> MonsterFile::getPosition(int num)
{
    int x = atoi(file->grabData()[num + POS_X].c_str());
    int y = atoi(file->grabData()[num + POS_Y].c_str());

    return Vector<int>(x, y);
}

Vector<int> MonsterFile::getSize(int num)
{
    int w = atoi(file->grabData()[num + POS_W].c_str());
    int h = atoi(file->grabData()[num + POS_H].c_str());

    return Vector<int>(w, h);
}

int MonsterFile::getMonsterNumbers()
{
    return atoi(file->grabData()[NUMBERS].c_str());
}