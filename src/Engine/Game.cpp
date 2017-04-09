
/* ------------------------------------------------

	@File		: Game.h
	@Date		: 08/11/2013
	@Purpose	:

		Here lies the implementation for
		the game class and comments have
		been made.

 ------------------------------------------------ */

#include "Factory.h"
#include "States.h"
#include "Game.h"

// File is meant for states
PlayerFile * State::playerFile = NULL;
MonsterFile * State::npcFile = NULL;
ItemFile * State::itemFile = NULL;
GameFile * State::file = NULL;

// Constructor & Deconstructor
Game::Game() : Window(NULL) {
	// Create Objects
	factory		= new Factory(this);
	states		= new StateManager(this, factory);
	gameFile	= new GameFile(*this, "Data/game.txt");

	srand((unsigned int)(time(NULL)));
	
	State::npcFile		= new MonsterFile(*this, "Data/monsters.txt");
	State::playerFile	= new PlayerFile(*this, "Data/player.txt");
	State::itemFile		= new ItemFile(*this, "Data/items.txt");
	State::file			= gameFile;
}

Game::~Game() {
	// Memory CleanUp
	delete gameFile;
	delete factory;
	delete states;
}

// Sets up the windows render context.
SDL_Window * Game::SetupRC(SDL_GLContext &context) {
	SDL_Window * Window;
   
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        ExitError("Unable to initialize SDL"); 
	}

	// Enables double buffering and Anti Aliasing
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); 
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

	Vector<int> position =  gameFile->getWindowPos();
	Vector<int> size = gameFile->getWindowSize();
 
	cstring Title = gameFile->getWindowTitle();

	// Creates the window
	Window = SDL_CreateWindow(Title, position.getX(), position.getY(), size.getX(), size.getY(), 2 | 4);

	if(!Window) {
        ExitError("Unable to create window");
	}
 
    context = SDL_GL_CreateContext(Window); 
	// Set the swap time to equal the resfresh rate
    SDL_GL_SetSwapInterval(1);

	// Initialise TTF (used for text)
	if(TTF_Init() == -1)
		ExitError("TTF failed to initialise.");

	return Window;
}

void Game::Initialise() {
	SDL_GLContext RenderContext; 

	if(gameFile->DebugEnabled()) {
		SetConsoleTitle("Debug Console");
	} else {
		FreeConsole();
	}

	// Create Window
	Window = SetupRC(RenderContext);
	Window != NULL ? loop = true : ExitError("Window failed to open");
}

void Game::Run() {
	while(loop) {
		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				loop = false;
				break;
			} else {
				states->getCurrentState()->onEvent(*states, event);
			}
		}
		states->getCurrentState()->onUpdate(*states);
		states->getCurrentState()->onDraw(*renderer, *states);

		SDL_GL_SwapWindow(Window); 
	}

    SDL_DestroyWindow(Window);
    SDL_Quit();
}

void Game::Exit() {
	loop = false;
}
	
void Game::ExitError(const char * message) {
	SDL_Quit();

	// if in debug mode
	if(gameFile->DebugEnabled()) {
		// output error onto screen
		cerr << message << " : " << SDL_GetError();
		cin.get();
	}

    exit(1);
}