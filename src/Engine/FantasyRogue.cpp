
/* ------------------------------------------------

	@File		: FantasyRogue.h
	@Date		: 08/11/2013
	@Purpose	:

		FantasyRogue class implementation

 ------------------------------------------------ */

#include "FantasyRogue.h"
#include "GL_Renderer.h"
#include "States.h"

// Constructor & Deconstructor
FantasyRogue::FantasyRogue() {
	// Specify what renderer i wish
	renderer = new GL_Renderer();
}

FantasyRogue::~FantasyRogue() { 
	// Game class deletes objects anyway
	// so only delete the renderer
	delete renderer;
}

// Functions
void FantasyRogue::Initialise() {
	// Initialise all variables
	Game::Initialise();

	// add new states
	states->addState<SplashScreen>();
	states->addState<MainMenu>();
	states->addState<Credits>();
	states->addState<Map>();
	states->addState<Store>();
	states->addState<CharactorSelection>();
	states->addState<Combat>();
	states->addState<GameOver>();

	// set starting point
	states->StartFrom(g_SplashScreen);
}

void FantasyRogue::Start() {
	// Get window size
	Vector<int> size = gameFile->getWindowSize();
	
	// Set drawing region & viewport
	gluOrtho2D(0, 720, 0, 480);
	glViewport(0, 0, size.getX(), size.getY());

	// start the program
	Game::Run();
}