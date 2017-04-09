
#include "Factory.h"
#include "States.h"
#include "Game.h"

PlayerFile * State::playerFile = NULL;
MonsterFile * State::npcFile = NULL;
ItemFile * State::itemFile = NULL;
GameFile * State::file = NULL;

Game::Game()
    : window(NULL)
{
    factory = new Factory(this);
    states = new StateManager(this, factory);
    gameFile = new GameFile(*this, "Data/game.txt");

    srand((unsigned int)(time(NULL)));

    State::npcFile = new MonsterFile(*this, "Data/monsters.txt");
    State::playerFile = new PlayerFile(*this, "Data/player.txt");
    State::itemFile = new ItemFile(*this, "Data/items.txt");
    State::file = gameFile;
}

Game::~Game()
{
    delete State::npcFile;
    delete State::playerFile;
    delete State::itemFile;

    delete gameFile;
    delete factory;
    delete states;
}

SDL_Window * Game::setupRenderContext(SDL_GLContext& context)
{
    SDL_Window* window;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        exitError("Unable to initialize SDL");
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

    Vector<int> position = gameFile->getWindowPos();
    Vector<int> size = gameFile->getWindowSize();
    cstring title = gameFile->getWindowTitle();

    window = SDL_CreateWindow(title, position.getX(), position.getY(), size.getX(), size.getY(), 2 | 4);

    if (!window) 
    {
        exitError("Unable to create window");
    }

    context = SDL_GL_CreateContext(window);

    SDL_GL_SetSwapInterval(1);

    if (TTF_Init() == -1)
    { 
        exitError("TTF failed to initialise.");
    }

    return window;
}

void Game::initialise()
{
    SDL_GLContext renderContext;

    if (gameFile->debugEnabled())
    {
        SetConsoleTitle("Debug Console");
    }
    else
    {
        FreeConsole();
    }

    window = setupRenderContext(renderContext);
    window != NULL ? loop = true : exitError("Window failed to open");
}

void Game::run()
{
    while (loop)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                loop = false;
                break;
            }
            else
            {
                states->getCurrentState()->onEvent(*states, event);
            }
        }

        states->getCurrentState()->onUpdate(*states);
        states->getCurrentState()->onDraw(*renderer, *states);

        SDL_GL_SwapWindow(window);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::exit()
{
    loop = false;
}

void Game::exitError(const char* message)
{
    SDL_Quit();

    if (gameFile->debugEnabled()) 
    {
        cerr << message << " : " << SDL_GetError();
        cin.get();
    }

    ::exit(1);
}