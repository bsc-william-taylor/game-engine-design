
/* ------------------------------------------------

	@File		: SplashScreen.cpp
	@Date		: 08/11/2013
	@Purpose	:

		Class implementation

 ------------------------------------------------ */

#include "SplashScreen.h"

// Constructor & Deconstructor
SplashScreen::SplashScreen(Factory * renderList) {
	// add a new object to the factory & set up the label
	studioName = renderList->newObject<Label>("studioText");
	studioName->SetText("Data/MavenPro-Regular.ttf", 30);
	studioName->TextToTexture(file->getStudioName());
	studioName->setPosition(Vector<int>(235, 250));

	// add a new object to the factory & set up the label
	publisherName = renderList->newObject<Label>("publisherText");
	publisherName->SetFont(studioName->getFont());
	publisherName->TextToTexture(file->getPublisherName());
	publisherName->setPosition(Vector<int>(210, 200));

	// Create a time object
	timer = new Timer();
}

SplashScreen::~SplashScreen() {
	// delete timer object
	delete timer;
}

// Functions
void SplashScreen::onDraw(Renderer& renderer, StateManager& state) {
	// Clearscreen draw labels and set the background colour
	renderer.clearScreen();
	renderer.backgroundColour(0.5, 0.0, 0.0, 0.0);
	renderer.drawLabel(publisherName);
	renderer.drawLabel(studioName);
}

void SplashScreen::onUpdate(StateManager& state) {
	// if 3 seconds has passed go to the next state
	if(timer->waitFor(3)){
		state.nextState();
	}
}

void SplashScreen::onEvent(StateManager& state, SDL_Event& event) {
	// if a key is pressed go to the next state
	if(event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
		state.nextState();
	}
}

// Empty Functions
void SplashScreen::onEnter(StateManager&) {
	// not needed	
}

void SplashScreen::onExit(StateManager&) {
	// not needed	
}