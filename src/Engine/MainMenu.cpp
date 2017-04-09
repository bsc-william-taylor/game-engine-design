
/* ------------------------------------------------

	@File		: MainMenu.cpp
	@Date		: 08/11/2013
	@Purpose	:
		
		class implementation

 ------------------------------------------------ */

#include "MainMenu.h"
#include "Objects.h"
#include "States.h"

// Constructor & Deconstructor
MainMenu::MainMenu(Factory * renderList) {
	string labelText[] =  {
		"Continue Game (C)", "New (N)", "Load (L)", "Quit (Q/ESC)", "Credits (R)", 
	};

	int labelPosition[] = { 
		300, 250, 200, 150, 100, 
	};

	gameInProgress = false;

	for(unsigned int i = 0; i < 5; i++) {
		menuLabels[i] = renderList->newObject<Label>("menuText" + 1);
		menuLabels[i]->setPosition(Vector<int>(20, labelPosition[i]));
		menuLabels[i]->SetText("Data/MavenPro-Regular.ttf", 35);
		menuLabels[i]->TextToTexture(labelText[i]);
	} 
}

MainMenu::~MainMenu() {
	// nothing to delete
}

// Functions
void MainMenu::onEvent(StateManager& state, SDL_Event& sdlevent) {
	if(sdlevent.type == SDL_KEYDOWN) {
		switch(sdlevent.key.keysym.sym) {
			case SDLK_ESCAPE:
			case SDLK_q: state.ExitStates(); break;
			case SDLK_r: state.SwitchState(2); break;
			case SDLK_l: state.SwitchState(3); gameInProgress = true; break;
			case SDLK_n: state.SwitchState(5); gameInProgress = true; break;

			default:  break;
		}

		if(gameInProgress && sdlevent.key.keysym.sym == SDLK_c){
			state.SwitchState(3); 
		}
	}
}

void MainMenu::restart() {
	gameInProgress = false;
}

void MainMenu::onDraw(Renderer& renderer, StateManager& StateManager) {
	renderer.clearScreen();
	renderer.backgroundColour(0.0, 0.5, 0.0, 0.0);
	
	if(gameInProgress) {
		renderer.drawLabelArray(menuLabels, 5);
	} else {
		renderer.drawLabelArray(menuLabels, 1, 5);
	} 
}

// Empty Functions
void MainMenu::onEnter(StateManager&) {
	// Nothing to set
}

void MainMenu::onExit(StateManager&) {
	// Nothing to set
}

void MainMenu::onUpdate(StateManager&) {
	// not needed;
}