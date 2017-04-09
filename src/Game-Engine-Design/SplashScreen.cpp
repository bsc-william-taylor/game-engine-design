
#include "SplashScreen.h"

SplashScreen::SplashScreen(Factory * renderList)
{
    studioName = renderList->newObject<Label>("studioText");
    studioName->setText("Data/MavenPro-Regular.ttf", 30);
    studioName->textToTexture(file->getStudioName());
    studioName->setPosition(Vector<int>(235, 250));

    publisherName = renderList->newObject<Label>("publisherText");
    publisherName->setFont(studioName->getFont());
    publisherName->textToTexture(file->getPublisherName());
    publisherName->setPosition(Vector<int>(210, 200));
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::onDraw(Renderer& renderer, StateManager& state)
{
    renderer.clearScreen();
    renderer.backgroundColour(0.5, 0.0, 0.0, 0.0);
    renderer.drawLabel(publisherName);
    renderer.drawLabel(studioName);
}

void SplashScreen::onUpdate(StateManager& state)
{
    if (timer.waitFor(3))
    {
        state.nextState();
    }
}

void SplashScreen::onEvent(StateManager& state, SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
    {
        state.nextState();
    }
}

void SplashScreen::onEnter(StateManager&)
{
}

void SplashScreen::onExit(StateManager&)
{
}