
/* ------------------------------------------------

	@File		: Credits.cpp
	@Date		: 08/11/2013
	@Purpose	:
		
		Class implementation

 ------------------------------------------------ */

#include "Credits.h"

// Constructor & Deconstructor
Credits::Credits(Factory * renderList) {
	// Init the timer
	timer = new Timer();

	// get objects as they have already been created by this point
	publisherName = renderList->getObject<Label>("publisherText");
	studioName = renderList->getObject<Label>("studioText");

	// and create a new object which represents my name
	myName = renderList->newObject<Label>("myName");
	myName->SetText("Data/MavenPro-Regular.ttf", 20);
	myName->TextToTexture(file->getCreatorName());
	myName->setPosition(Vector<int>(10, 10));
}

Credits::~Credits() {
	delete timer;
}

// Functions
void Credits::onDraw(Renderer& renderer, StateManager& states) {
	renderer.clearScreen();
	renderer.backgroundColour(0.0, 0.0, 0.5, 0.0);
	renderer.drawLabel(publisherName);
	renderer.drawLabel(studioName);
	renderer.drawLabel(myName);
}

void Credits::onUpdate(StateManager& states) {
	// after 30 seconds go to the main menu
	if(timer->Waitfor(30)){
		states.SwitchState(g_Menu);
	}
}

void Credits::onEvent(StateManager& states, SDL_Event& event) {
	if(event.type == SDL_KEYDOWN) {
		states.SwitchState(1);
	}
}

// Empty Functions
void Credits::onEnter(StateManager&) {
	// nothing needs to be set
}

void Credits::onExit(StateManager&) {
	// or reset
}