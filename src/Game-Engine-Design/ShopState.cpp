
/* ------------------------------------------------

	@File		: ShopState.cpp
	@Date		: 08/11/2013
	@Purpose	:

		class implementation

 ------------------------------------------------ */

#include "ShopState.h"
#include "States.h"

// Constructor & Deconstructor
Store::Store(Factory * renderList) {
	player = renderList->getObject<Player>("Player");
	// set up label text
	string labelText[] =  {
		"Buy Health Pack $10 (H)", 
		"Buy Combat Pack $10 (C)",
		"Buy Stimulant $10 (K)", 
		"Exit (E)"
	};

	// setup label positions
	int labelPosition[] = { 
		300, 250, 200, 150
	};

	// add position and 
	for(unsigned int i = 0; i < 4; i++) {
		storeLabels[i] = renderList->newObject<Label>("shopText" + i);
		storeLabels[i]->setPosition(Vector<int>(20, labelPosition[i]));
		storeLabels[i]->SetText("Data/MavenPro-Regular.ttf", 35);
		storeLabels[i]->TextToTexture(labelText[i]);
	} 
}

Store::~Store() {
	// Nothing to delete
}

// Functions
void Store::BuyItem(ItemType item) {
	Item * temp;

	if(player->getStats().Cash >= 10) {
		// Create a item
		if(item == STIMULANT) temp = new StimulantPack();
		if(item == COMBAT) temp = new CombatPack();
		if(item == HEALTH) temp = new HealthPack();
		// take cost away
		player->getStats().Cash -= 10;
		// consume item & delete
		temp->onConsume(player);
		delete temp;
	}
}

void Store::onDraw(Renderer& renderer, StateManager& state) {
	renderer.clearScreen();
	renderer.backgroundColour(0.5, 0.0, 0.5, 0.0);
	renderer.drawLabelArray(storeLabels, 4);
	renderer.drawPlayerStats(player);
}

void Store::onEvent(StateManager& state, SDL_Event& event) {
	// Handle key events
	if(event.type == SDL_KEYDOWN) {
		switch(event.key.keysym.sym) {
			case SDLK_ESCAPE:
			case SDLK_e: state.switchState(g_Map); break;
			case SDLK_k: BuyItem(STIMULANT); break;
			case SDLK_c: BuyItem(COMBAT); break;
			case SDLK_h: BuyItem(HEALTH); break;

			default:  break;
		}
	}
}

void Store::onExit(StateManager&) {
	player->Save();
}

// Empty Functions
void Store::onUpdate(StateManager& state) {
	// not needed
}

void Store::onEnter(StateManager&) {
	// nothing to set
}