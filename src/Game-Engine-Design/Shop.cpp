
/* ------------------------------------------------

	@File		: Shop.cp
	@Date		: 21/11/2013
	@Purpose	:

		Class implementation

 ------------------------------------------------ */

#include "Shop.h"


// Constructor & Deconstructor
Shop::Shop() {
	position = Vector<int>(0, 0);
	size = Vector<int>(10, 10);

	shopText = new Label();
	shopText->SetText("Data/MavenPro-Regular.ttf", 15);
	shopText->TextToTexture("Store");
	shopText->setPosition(Vector<int>(position.getX(), position.getY()));
}

Shop::~Shop() {
	delete shopText;
}

// Functions
Label * Shop::getLabel() { 
	return shopText;
}