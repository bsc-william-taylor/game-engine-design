
#include "CharacterSelection.h"
#include "States.h"

CharactorSelection::CharactorSelection(Factory * renderList) 
{
	title = renderList->newObject<Label>("title");
	title->setText("Data/MavenPro-Regular.ttf", 30);
	title->textToTexture("Character Selection");
	title->setPosition(Vector<int>(225, 400));
}

CharactorSelection::~CharactorSelection() 
{
}

void CharactorSelection::onEvent(StateManager& state, SDL_Event& event) 
{
	if(event.type == SDL_KEYDOWN) 
    {
		state.getState<Map>(MapScene)->resetMap();
		state.switchState(MapScene);
	}
}

void CharactorSelection::onDraw(Renderer& renderer, StateManager&) 
{
	renderer.clearScreen();
	renderer.backgroundColour(0.1f, 0.3f, 0.5f, 0.0f);
	renderer.drawLabel(title);
}

void CharactorSelection::onUpdate(StateManager& state) 
{
}

void CharactorSelection::onEnter(StateManager& state) 
{
}

void CharactorSelection::onExit(StateManager& state)
{
}
