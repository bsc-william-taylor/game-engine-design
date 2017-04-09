
#pragma once

#include "FileReader.h"
#include "Objects.h"
#include "Vector.h"

class Item;
class Game;

class ItemFile 
{
private:
    FileReader * file;
public:
    ItemFile(Game&, string);
    ~ItemFile();

    Vector<int> getItemPosition(int);
    Vector<int> getItemSize(int);

    cstring getItemName(int);
    Item * getItem(int);
    bool getItemState(int);
    int getItemNumbers();

    void setPosition(int, Vector<int>);
    void setState(int, bool);
    void push();
};