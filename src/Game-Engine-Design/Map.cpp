
/* ------------------------------------------------

	@File		: Map.cpp
	@Date		: 08/11/2013
	@Purpose	:
		
		Class implementation

 ------------------------------------------------ */

#include "Map.h"

// Constructor & Deconstructor
Map::Map(Factory * renderList) {
	// Create a player
	player = renderList->newCharacter<Player>("Player", State::playerFile);

	// Create the store
	store = renderList->newObject<Shop>("store");
	store->setPosition(Vector<int>(50, 300));
	store->setSize(Vector<int>(50, 50));

	// Setup observers
	StoreCollision  = new Collision(player, store);
	BorderCollision = new Border(player);

	// Initalise Enemys & Items
	InitialiseEnemys();
	InitialiseItems();
}

Map::~Map() {
	// Delete observers
	for(unsigned int i = 0; i < EnemyCollision.size(); i++) {
		delete EnemyCollision[i];
	}
	// Delete enemys
	for(unsigned int i = 0; i < Enemys.size(); i++) {
		delete Enemys[i];
	}
}

// Functions
void Map::onDraw(Renderer& renderer, StateManager& state) {
	renderer.clearScreen();
	renderer.backgroundColour(0.1f, 0.1f, 0.1f, 0.0);

	// draw items first then enemys & then the player
	renderer.drawItemVector(Items);
	renderer.drawCharacterVector(Enemys);
	renderer.drawPlayer(player);
	renderer.drawShop(store);
}

void Map::InitialiseItems() {
	// get the number of items from file
	for(int i = 0; i < itemFile->getItemNumbers(); i++) {
		// get each item
		Item * temp = itemFile->getItem(i);
		// push the item into the vector
		Items.push_back(temp);
		// setup the observer to monitor collisions
		ItemCollision.push_back(new Collision(player, Items[i]));
	}
}

void Map::InitialiseEnemys() {
	// get the number of monsters from file
	for(int i = 0; i < npcFile->getMonsterNumbers(); i++) {
		// Get the monster
		Character * temp = npcFile->getCharacter(i);
		// push it into the vector
		Enemys.push_back(temp);
		// setup the observer to monitor the collision between the 
		// monster and the player
		EnemyCollision.push_back(new Collision(player, Enemys[i]));
	}
}
		
void Map::onEvent(StateManager& state, SDL_Event& event) {
	// Move player if the right key is pressed
	if(event.type == SDL_KEYDOWN) {
		switch(event.key.keysym.sym) {
			case SDLK_ESCAPE: state.switchState(1); break;
			case SDLK_DOWN:
			case 's': 
			case 'S': static_cast<Player *>(player)->moveY(-10); break;
			case SDLK_LEFT:
			case 'a': 
			case 'A': static_cast<Player *>(player)->moveX(-10); break;
			case SDLK_UP:
			case 'w': 
			case 'W': static_cast<Player *>(player)->moveY(10); break;
			case SDLK_RIGHT:
			case 'd': 
			case 'D': static_cast<Player *>(player)->moveX(10); break;
			default: break;
		}
	}
}

// Should be called when we want to start a new game
void Map::ResetMap() {
	// reset player
	player->Reset();
	
	// & all enemys
	for(unsigned int i = 0; i < Enemys.size(); i++)	{
		Enemys[i]->Reset();
	}

	// & all items
	for(unsigned int i = 0; i < Items.size(); i++) {
		Items[i]->Reset();
	}
}

void Map::onEnter(StateManager& state) {
	// Load player
	player->Load();

	// load enemys & count how many are alive
	monstersAlive = 0; 
	for(unsigned int i = 0; i < Enemys.size(); i++)	{
		Enemys[i]->Load();
		if(!Enemys[i]->isKilled()) {
			monstersAlive++;
		}
	}
	// load items
	for(unsigned int i = 0; i < Items.size(); i++) {
		Items[i]->Load();
	}

	// if there are no enemys alive go to the gameover screen
	if(monstersAlive == 0) {
		state.getState<GameOver>(g_GameOver)->setWinner(true);
		state.switchState(g_GameOver);
	}

	// if there player isnt alive go to the gameover screen
	if(player->isKilled()) {
		state.getState<GameOver>(g_GameOver)->setWinner(false);
		state.switchState(g_GameOver);
	}
}

void Map::onExit(StateManager& state) {
	// save player pos & stats
	player->Save();

	// Save all enemys pos & stats
	for(unsigned int i = 0; i < Enemys.size(); i++)
		Enemys[i]->Save();
	
	// Same for the items
	for(unsigned int i = 0; i < Items.size(); i++)
		Items[i]->Save();
}

void Map::onUpdate(StateManager& state) {
	// Check to see if observers have been activated
	for(unsigned int i = 0; i < EnemyCollision.size(); i++) {
		// if so
		if(EnemyCollision[i]->hasTriggered()) {
			// Reset the observer
			EnemyCollision[i]->reset();
			// get enemy position
			Vector<int> Position = EnemyCollision[i]->getNode()->getPosition();

			// set player position to the enemy position
			player->setPosition(Vector<int>(Position.getX(), Position.getY()));

			// set the enemy variable for the Combat state then switch to that state
			state.getState<Combat>(g_Battle)->setOpponent((NPC *)EnemyCollision[i]->getNode());
			state.switchState(g_Battle);
			break;
		}
	}

	// check all item observers
	for(unsigned int i = 0; i < ItemCollision.size(); i++) {
		// if triggered
		if(ItemCollision[i]->hasTriggered()) {
			// reset the item & call the consume method
			ItemCollision[i]->reset();
			Items[i]->onConsume((Player *)player);
			break;
		}
	}
	
	// if the store observer has been trigered
	if(StoreCollision->hasTriggered()) {
		// reset 
		StoreCollision->reset();

		int y = store->getPosition().getY() - (int)(player->getSize().getX() * 1.5);
		int x = store->getPosition().getX();

		// & go to the store state
		player->setPosition(Vector<int>(x, y));
		state.switchState(g_Store);
	}
}