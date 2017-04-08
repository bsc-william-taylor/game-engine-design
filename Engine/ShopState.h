
/* ------------------------------------------------

	@File		: ShopState.h
	@Date		: 08/11/2013
	@Purpose	:

		A simple shop state where the player
		can purchase items if the have the 
		right amount of cash

 ------------------------------------------------ */

#pragma once

#include "StateManager.h"
#include "State.h"

enum ItemType {
	STIMULANT = 2,
	COMBAT = 1,
	HEALTH = 0,
};

class Store : public State{
	private:

		Label * storeLabels[4];
		Player * player;

		void BuyItem(ItemType);

	public:

	Store(Factory *);

		void onEvent(StateManager&, SDL_Event&);
		void onDraw(Renderer&, StateManager&);
		void onUpdate(StateManager&);
		void onEnter(StateManager&);
		void onExit(StateManager&);

	~Store();
};