
#include "ItemFile.h"
#include "Item.h"
#include "Player.h"

Item::Item(ItemFile * file)
{
    this->file = file;
    used = false;
    setColour(1.0, 0.0, 1.0);
}

Item::Item()
{
    file = NULL;
    used = false;
}

Item::~Item()
{
}

void Item::load()
{
    Vector<int> position = file->getItemPosition(num);
    Vector<int> size = file->getItemSize(num);

    used = file->getItemState(num);

    if (!position.getX())
    {
        position.set(rand() % 720 + 1, position.getY());
    }

    if (!position.getY())
    {
        position.set(position.getX(), rand() % 480 + 1);
    }

    setPosition(position);
    setSize(size);
}

void Item::setColour(float r, float g, float b)
{
    colour.r = r;
    colour.g = g;
    colour.b = b;
}

void Item::setItemNumber(int i)
{
    num = i;
}

bool Item::isUsed()
{
    return used;
}

void Item::reset()
{
    file->setPosition(num, Vector<int>(0, 0));
    file->setState(num, false);
    file->push();

    turnOnObservers();
}

void Item::save()
{
    file->setPosition(num, getPosition());
    file->setState(num, used);
    file->push();
}

Colour& Item::getColour()
{
    return colour;
}