
/* ------------------------------------------------

	@File		: GameOver.cpp
	@Date		: 08/11/2013
	@Purpose	:
		
		Class implementation

 ------------------------------------------------ */

#include "GameOver.h"
#include "States.h"

// Constructor & Deconstructor
GameOver::GameOver(Factory * renderList) {
	Result = new Label();
	Result->SetText("Data/MavenPro-Regular.ttf", 30);
	Result->setPosition(Vector<int>(290, 210));
	
	Title = new Label();
	Title->SetText("Data/MavenPro-Regular.ttf", 45);
	Title->setPosition(Vector<int>(250, 350));
	Title->TextToTexture("Game Over");
}

GameOver::~GameOver() {
	delete Title;
}

// Functions
void GameOver::onEvent(StateManager& state, SDL_Event& event) {
	if(event.type == SDL_KEYDOWN) {
		switch(event.key.keysym.sym) {
			case SDLK_ESCAPE:
			case SDLK_RETURN: {
				state.SwitchState(g_Menu);
				break;
			}
			default: break;
		}
	}
}

void GameOver::onEnter(StateManager& states) {
	if(playerWin) {
		Result->TextToTexture("You Win !!!");
	} else {
		Result->TextToTexture("You Lose !!!");
	}
}

void GameOver::onDraw(Renderer& renderer, StateManager& states) {
	renderer.clearScreen();
	renderer.backgroundColour(0.5, 0.5, 0.5, 0.0);
	renderer.drawLabel(Title);
	renderer.drawLabel(Result);
}

void GameOver::setWinner(bool b) { 
	playerWin = b; 
} 

// Empth Functions
void GameOver::onUpdate(StateManager&) {
	// nothing to update
}

void GameOver::onExit(StateManager&) {
	// nothing needs to be reset
}