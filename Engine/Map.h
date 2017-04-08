
/* ------------------------------------------------

	@File		: Map.h
	@Date		: 08/11/2013
	@Purpose	:

		This class is the main level state &
		thats why there are a lot of data
		members, it acts as the map that the
		user can walk around and interact
		with
		
 ------------------------------------------------ */

#pragma once

#include "StateManager.h"
#include "Collision.h"
#include "Objects.h"
#include "Border.h"
#include "Vector.h"
#include "States.h"

class Map : public State {
	private:

		// Observers
		vector<Collision *> EnemyCollision;
		vector<Collision *> ItemCollision;
		Collision * StoreCollision;
		Border * BorderCollision;

		// NPC's & Items
		vector<Character *> Enemys;
		vector<Item *> Items;
		Character * player;
		Shop * store;

		int monstersAlive;

	public:

	Map(Factory *);
		
		void onEvent(StateManager&, SDL_Event&);
		void onDraw(Renderer&, StateManager&);
		void onUpdate(StateManager&);
		void onEnter(StateManager&);
		void onExit(StateManager&);

		void InitialiseEnemys();
		void InitialiseItems();
		void ResetMap();

	~Map();

};