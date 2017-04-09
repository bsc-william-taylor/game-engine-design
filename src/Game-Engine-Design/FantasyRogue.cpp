
#include "FantasyRogue.h"
#include "RendererGL.h" 
#include "States.h"

FantasyRogue::FantasyRogue()
{
    renderer = new RendererGL();
}

FantasyRogue::~FantasyRogue()
{
    delete renderer;
}

void FantasyRogue::initialise()
{
    Game::initialise();

    states->addState<SplashScreen>();
    states->addState<MainMenu>();
    states->addState<Credits>();
    states->addState<Map>();
    states->addState<Store>();
    states->addState<CharactorSelection>();
    states->addState<Combat>();
    states->addState<GameOver>();
    states->startFrom(SplashScreenScene);
}

void FantasyRogue::start()
{
    Vector<int> size = gameFile->getWindowSize();

    gluOrtho2D(0, 720, 0, 480);
    glViewport(0, 0, size.getX(), size.getY());

    Game::run();
}