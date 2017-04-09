
#include "GameOver.h"
#include "States.h"

GameOver::GameOver(Factory * renderList)
{
    result = new Label();
    result->setText("Data/MavenPro-Regular.ttf", 30);
    result->setPosition(Vector<int>(290, 210));

    title = new Label();
    title->setText("Data/MavenPro-Regular.ttf", 45);
    title->setPosition(Vector<int>(250, 350));
    title->textToTexture("Game Over");
}

GameOver::~GameOver()
{
    delete result;
    delete title;
}

void GameOver::onEvent(StateManager& state, SDL_Event& event) 
{
    if (event.type == SDL_KEYDOWN) 
    {
        switch (event.key.keysym.sym) 
        {
            case SDLK_ESCAPE:
            case SDLK_RETURN: 
            {
                state.switchState(MenuScene);
                break;
            }

            default: 
                break;
        }
    }
}

void GameOver::onEnter(StateManager& states)
{
    result->textToTexture(playerWin ? "You Win !!!" : "You Lose !!!");
}

void GameOver::onDraw(Renderer& renderer, StateManager& states) 
{
    renderer.clearScreen();
    renderer.backgroundColour(0.5, 0.5, 0.5, 0.0);
    renderer.drawLabel(title);
    renderer.drawLabel(result);
}

void GameOver::setWinner(bool b) 
{
    playerWin = b;
}

void GameOver::onUpdate(StateManager&) 
{
}

void GameOver::onExit(StateManager&) 
{
}