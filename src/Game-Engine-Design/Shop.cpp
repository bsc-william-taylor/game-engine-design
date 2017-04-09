
#include "Shop.h"

Shop::Shop() 
{
    position = Vector<int>(0, 0);
    size = Vector<int>(10, 10);

    shopText = new Label();
    shopText->setText("Data/MavenPro-Regular.ttf", 15);
    shopText->textToTexture("Store");
    shopText->setPosition(Vector<int>(position.getX(), position.getY()));
}

Shop::~Shop() 
{
    delete shopText;
}

Label * Shop::getLabel() 
{
    return shopText;
}