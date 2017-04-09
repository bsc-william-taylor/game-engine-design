
/* ------------------------------------------------

	@File		: Combat.cpp
	@Date		: 08/11/2013
	@Purpose	:
		
		Class implementation

 ------------------------------------------------ */

#include "Combat.h"

// Constructor & Deconstructor
Combat::Combat(Factory * renderList) {
	player = renderList->getObject<Player>("Player");
	firsthit = false;
	finish = false;

	Title = renderList->newObject<Label>("GameOverTitle");
	Title->SetText("Data/MavenPro-Regular.ttf", 30);
	Title->setPosition(Vector<int>(290, 210));
}

Combat::~Combat() {
	// Nothing to delete
}

// Functions
void Combat::onEnter(StateManager& StateManager) {
	// get current positions & save them for later use
	monsterPos = opponent->getPosition();
	playerPos = player->getPosition();

	// set new position
	opponent->setPosition(Vector<int>(500, 200));
	player->setPosition(Vector<int>(200, 200));

	// set it so no winner has been selected
	previousHealth = player->getStats().Health;
	playerWin = -1;
}

void Combat::onExit(StateManager& StateManager) {
	// set positions to the existing location
	opponent->setPosition(monsterPos);
	opponent->Save();

	// reset values
	firsthit = false;
	finish = false;

	// set back to previous position
	player->setPosition(playerPos);
	player->Save();
}

void Combat::onEvent(StateManager& StateManager, SDL_Event& event) {
	if(event.type == SDL_KEYDOWN) {
		switch(event.key.keysym.sym) {
			case SDLK_ESCAPE:
			case SDLK_e: {
				if(playerWin >= 0) {
					if(playerWin) {
						StateManager.SwitchState(g_Map); 
					} else {
						StateManager.getState<GameOver>(g_GameOver)->setWinner(false);
						StateManager.SwitchState(g_GameOver); 
					}
				} break;
			}
			case SDLK_RETURN:
			case SDLK_SPACE: 
				// press space to resolve combat
				if(playerWin < 0) {
					firsthit = true;
					break;
				}
			default: break;
		}
	}
}

void Combat::onDraw(Renderer& renderer, StateManager& StateManager) {
	renderer.clearScreen();
	renderer.backgroundColour(0.0, 0.0, 1.0, 0.0);
	renderer.drawFullNpc(opponent);
	renderer.drawPlayer(player);

	// render the win text if the player wins
	if(playerWin == 1) {
		Title->TextToTexture("Player Wins");
		renderer.drawLabel(Title);
	} 
	// else render the player looses text
	if(!playerWin) {
		Title->TextToTexture("Player Looses");
		renderer.drawLabel(Title);
	}
}

void Combat::setOpponent(NPC * npc) {
	this->opponent = npc;
}

void Combat::determineVictor(StateManager& StateManager) {
	// if both the monsters & players health is more than 0
	if(player->getStats().Health > 0 && opponent->getStats().Health > 0) {
		// take turns in removing strength from health
		if(playersTurn) {
			int damage = rand() % (player->getStats().Strength - 1) + 2;
			opponent->getStats().Health -= damage;
		} else {
			int damage = rand() % (opponent->getStats().Strength - 1) + 2;
			player->getStats().Health -= damage;
		}
	}

	// if the player health is below 0
	if(player->getStats().Health <= 0) {
		// set it so the player has lossed
		playerWin = false;
		// kill the player
		player->Kill();
		finish = false;
	}

	// if the monsters health is below 0
	if(opponent->getStats().Health <= 0) {
		int temp = previousHealth - player->getStats().Health;
		player->getStats().Health += RoundUp((float)temp/2); 
		opponent->DropItem(player);
		opponent->Kill();
		playerWin = true;
		finish = false;
	}

	playersTurn = !playersTurn;
}

void Combat::firstHit() {
	// make sure that the faster character hits first
	if(player->getStats().Speed < opponent->getStats().Speed) {
		int damage = rand() % (opponent->getStats().Strength - 1) + 2;
		player->getStats().Health -= damage;
		playersTurn = true;
	} else if(player->getStats().Speed > opponent->getStats().Speed) {
		int damage = rand() % (player->getStats().Strength - 1) + 2;
		opponent->getStats().Health -= damage;
		playersTurn = false;
	} else {
		// if the speed is the same pick one at random
		switch (rand() % 2) {
			case 0: {
				opponent->getStats().Health -= rand() % (player->getStats().Strength - 1) + 2; 
				playersTurn = true; 
				break;
			}

			case 1: {
				player->getStats().Health -= rand() % (opponent->getStats().Strength - 1) + 2; 
				playersTurn = false; 
				break;
			}
		}
	}
}

void Combat::onUpdate(StateManager& StateManager) {
	if(firsthit) {
		firsthit = false;
		finish = true;
		firstHit();
	} 
	
	// after first hit just determine the victor
	if(finish) {
		determineVictor(StateManager);
	}
}