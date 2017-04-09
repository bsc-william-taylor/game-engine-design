
#include "Credits.h"

Credits::Credits(Factory * renderList)
{
    publisherName = renderList->getObject<Label>("publisherText");
    studioName = renderList->getObject<Label>("studioText");

    myName = renderList->newObject<Label>("myName");
    myName->setText("Data/MavenPro-Regular.ttf", 20);
    myName->textToTexture(file->getCreatorName());
    myName->setPosition(Vector<int>(10, 10));
}

Credits::~Credits()
{
}

void Credits::onDraw(Renderer& renderer, StateManager& states)
{
    renderer.clearScreen();
    renderer.backgroundColour(0.0, 0.0, 0.5, 0.0);
    renderer.drawLabel(publisherName);
    renderer.drawLabel(studioName);
    renderer.drawLabel(myName);
}

void Credits::onUpdate(StateManager& states)
{
    if (timer.waitFor(30))
    {
        states.switchState(MenuScene);
    }
}

void Credits::onEvent(StateManager& states, SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN)
    {
        states.switchState(1);
    }
}

void Credits::onEnter(StateManager&)
{
}

void Credits::onExit(StateManager&)
{
}