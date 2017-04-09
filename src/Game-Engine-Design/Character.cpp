
#include "Character.h"

Character::Character(Character& character) 
{
    setPosition(character.getPosition());
    setSize(character.getSize());
    colour = character.getColour();
    num = character.num;

    text.setText("Data/MavenPro-Regular.ttf", 13);
}

Character::Character() 
{
    text.setText("Data/MavenPro-Regular.ttf", 13);

    colour.r = 0.0f;
    colour.g = 0.0f;
    colour.b = 0.0f;
}

Character::~Character() 
{
}

void Character::setNum(int number) 
{
    this->num = number;
}

Label * Character::getLabel() 
{
    return &text;
}

Colour& Character::getColour() 
{
    return colour;
}