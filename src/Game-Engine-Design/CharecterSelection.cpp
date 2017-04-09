
/* ------------------------------------------------

	@File		: CharacterSelection.h
	@Date		: 08/11/2013
	@Purpose	:
		
		class implementation

 ------------------------------------------------ */

#include "CharecterSelection.h"
#include "States.h"

// Constructor & Deconstructor
CharactorSelection::CharactorSelection(Factory * renderList) {
	// create new text object
	title = renderList->newObject<Label>("title");
	title->SetText("Data/MavenPro-Regular.ttf", 30);
	title->TextToTexture("Character Selection");
	title->setPosition(Vector<int>(225, 400));
}

CharactorSelection::~CharactorSelection() {
	// nothing to delete the factory does that for us
}

// Functions
void CharactorSelection::onEvent(StateManager& state, SDL_Event& event) {
	// if a key is pressed for to the map state
	if(event.type == SDL_KEYDOWN) {
		state.getState<Map>(g_Map)->ResetMap();
		state.switchState(g_Map);
	}
}

void CharactorSelection::onDraw(Renderer& renderer, StateManager&) {
	renderer.clearScreen();
	renderer.backgroundColour(0.1f, 0.3f, 0.5f, 0.0f);
	renderer.drawLabel(title);
}

// Empty Functions
void CharactorSelection::onUpdate(StateManager& state) {
	// Nothing to update
}

void CharactorSelection::onEnter(StateManager& state) {
	// nothing to set
}

void CharactorSelection::onExit(StateManager& state) {
	// nothing to reset
}