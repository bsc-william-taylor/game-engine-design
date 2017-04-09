
#include "ItemFile.h"

enum Items
{
    ITEM_NUM,
    ITEM_NAME,
    ITEM_X,
    ITEM_Y,
    ITEM_W,
    ITEM_H,
    CONSUMED,
    ITEM_DETAILS = 6
};

ItemFile::ItemFile(Game& game, string filename)
{
    file = new FileReader(game, filename);
}

ItemFile::~ItemFile()
{
    delete file;
}

void ItemFile::setPosition(int num, Vector<int> position)
{
    file->grabData()[num + ITEM_X] = to_string(position.getX());
    file->grabData()[num + ITEM_Y] = to_string(position.getY());
}

Item * ItemFile::getItem(int num)
{
    int location = num * ITEM_DETAILS;
    Item * temp;

    string name = getItemName(location);

    if (name == "Health" || name == "health")
    {
        temp = new HealthPack(this);
        temp->SetColour(1.0, 0.0, 0.0);
    }

    if (name == "Combat" || name == "combat")
    {
        temp = new CombatPack(this);
        temp->SetColour(0.0, 0.0, 1.0);
    }

    if (name == "Stimulant" || name == "stimulant")
    {
        temp = new StimulantPack(this);
        temp->SetColour(0.0, 1.0, 0.0);
    }

    temp->SetItemNumber(location);
    return temp;
}

Vector<int> ItemFile::getItemPosition(int num)
{
    int x = atoi(file->grabData()[num + ITEM_X].c_str());
    int y = atoi(file->grabData()[num + ITEM_Y].c_str());

    return Vector<int>(x, y);
}

void ItemFile::push()
{
    file->pushFile();
}

void ItemFile::setState(int num, bool state)
{
    file->grabData()[num + CONSUMED] = to_string(state);
}

Vector<int> ItemFile::getItemSize(int num)
{
    int w = atoi(file->grabData()[num + ITEM_W].c_str());
    int h = atoi(file->grabData()[num + ITEM_H].c_str());

    return Vector<int>(w, h);
}

bool ItemFile::getItemState(int num)
{
    return atoi(file->grabData()[num + CONSUMED].c_str());
}

cstring ItemFile::getItemName(int num)
{
    return file->grabData()[num + ITEM_NAME].c_str();
}

int ItemFile::getItemNumbers()
{
    return atoi(file->grabData()[ITEM_NUM].c_str());
}