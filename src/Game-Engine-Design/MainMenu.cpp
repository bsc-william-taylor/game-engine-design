

#include "MainMenu.h"
#include "Objects.h"
#include "States.h"

MainMenu::MainMenu(Factory * renderList)
{
    string labelText[] =
    {
        "Continue Game (C)", "New (N)", "Load (L)", "Quit (Q/ESC)", "Credits (R)",
    };

    int labelPosition[] =
    {
        300, 250, 200, 150, 100,
    };

    gameInProgress = false;

    for (unsigned int i = 0; i < 5; i++)
    {
        menuLabels[i] = renderList->newObject<Label>("menuText" + 1);
        menuLabels[i]->setPosition(Vector<int>(20, labelPosition[i]));
        menuLabels[i]->setText("Data/MavenPro-Regular.ttf", 35);
        menuLabels[i]->textToTexture(labelText[i]);
    }
}

MainMenu::~MainMenu()
{
}

void MainMenu::onEvent(StateManager& state, SDL_Event& sdlevent)
{
    if (sdlevent.type == SDL_KEYDOWN)
    {
        switch (sdlevent.key.keysym.sym)
        {
        case SDLK_ESCAPE:
        case SDLK_q: state.exitStates(); break;
        case SDLK_r: state.switchState(2); break;
        case SDLK_l: state.switchState(3); gameInProgress = true; break;
        case SDLK_n: state.switchState(5); gameInProgress = true; break;

        default:  break;
        }

        if (gameInProgress && sdlevent.key.keysym.sym == SDLK_c)
        {
            state.switchState(3);
        }
    }
}

void MainMenu::restart()
{
    gameInProgress = false;
}

void MainMenu::onDraw(Renderer& renderer, StateManager& StateManager)
{
    renderer.clearScreen();
    renderer.backgroundColour(0.0, 0.5, 0.0, 0.0);

    if (gameInProgress)
    {
        renderer.drawLabelArray(menuLabels, 5);
    }
    else
    {
        renderer.drawLabelArray(menuLabels, 1, 5);
    }
}

void MainMenu::onEnter(StateManager&)
{
}

void MainMenu::onExit(StateManager&)
{
}

void MainMenu::onUpdate(StateManager&)
{
}