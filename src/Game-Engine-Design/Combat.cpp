
#include "Combat.h"

Combat::Combat(Factory * renderList)
{
    playerCharacter = renderList->getObject<Player>("Player");
    firsthit = false;
    finish = false;

    title = renderList->newObject<Label>("GameOverTitle");
    title->setText("Data/MavenPro-Regular.ttf", 30);
    title->setPosition(Vector<int>(290, 210));
}

Combat::~Combat()
{
}

void Combat::onEnter(StateManager& StateManager)
{
    monsterPos = opponent->getPosition();
    playerPos = playerCharacter->getPosition();

    opponent->setPosition(Vector<int>(500, 200));
    playerCharacter->setPosition(Vector<int>(200, 200));

    previousHealth = playerCharacter->getStats().health;
    playerWin = -1;
}

void Combat::onExit(StateManager& StateManager)
{
    opponent->setPosition(monsterPos);
    opponent->save();

    firsthit = false;
    finish = false;

    playerCharacter->setPosition(playerPos);
    playerCharacter->save();
}

void Combat::onEvent(StateManager& StateManager, SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_ESCAPE:
        case SDLK_e:
        {
            if (playerWin >= 0)
            {
                if (playerWin)
                {
                    StateManager.switchState(MapScene);
                }
                else
                {
                    StateManager.getState<GameOver>(GameOverScene)->setWinner(false);
                    StateManager.switchState(GameOverScene);
                }
            } break;
        }
        case SDLK_RETURN:
        case SDLK_SPACE:
            if (playerWin < 0)
            {
                firsthit = true;
                break;
            }
        default:
            break;
        }
    }
}

void Combat::onDraw(Renderer& renderer, StateManager& StateManager)
{
    renderer.clearScreen();
    renderer.backgroundColour(0.0, 0.0, 1.0, 0.0);
    renderer.drawFullNpc(opponent);
    renderer.drawPlayer(playerCharacter);

    if (playerWin)
    {
        title->textToTexture("Player Wins");
        renderer.drawLabel(title);
    }

    if (!playerWin)
    {
        title->textToTexture("Player Looses");
        renderer.drawLabel(title);
    }
}

void Combat::setOpponent(NPC* npc)
{
    this->opponent = npc;
}

void Combat::determineVictor(StateManager& StateManager)
{
    if (playerCharacter->getStats().health > 0 && opponent->getStats().health > 0)
    {
        if (playersTurn)
        {
            int damage = rand() % (playerCharacter->getStats().strength - 1) + 2;
            opponent->getStats().health -= damage;
        }
        else
        {
            int damage = rand() % (opponent->getStats().strength - 1) + 2;
            playerCharacter->getStats().health -= damage;
        }
    }

    if (playerCharacter->getStats().health <= 0)
    {
        playerWin = false;
        playerCharacter->Kill();
        finish = false;
    }

    if (opponent->getStats().health <= 0)
    {
        int temp = previousHealth - playerCharacter->getStats().health;
        playerCharacter->getStats().health += ceil((float)temp / 2);
        opponent->dropItem(playerCharacter);
        opponent->Kill();
        playerWin = true;
        finish = false;
    }

    playersTurn = !playersTurn;
}

void Combat::firstHit()
{
    if (playerCharacter->getStats().speed < opponent->getStats().speed)
    {
        int damage = rand() % (opponent->getStats().strength - 1) + 2;
        playerCharacter->getStats().health -= damage;
        playersTurn = true;
    }
    else if (playerCharacter->getStats().speed > opponent->getStats().speed)
    {
        int damage = rand() % (playerCharacter->getStats().strength - 1) + 2;
        opponent->getStats().health -= damage;
        playersTurn = false;
    }
    else
    {
        switch (rand() % 2)
        {
            case 0:
            {
                opponent->getStats().health -= rand() % (playerCharacter->getStats().strength - 1) + 2;
                playersTurn = true;
                break;
            }

            case 1: 
            {
                playerCharacter->getStats().health -= rand() % (opponent->getStats().strength - 1) + 2;
                playersTurn = false;
                break;
            }
        }
    }
}

void Combat::onUpdate(StateManager& StateManager)
{
    if (firsthit)
    {
        firsthit = false;
        finish = true;
        firstHit();
    }

    if (finish)
    {
        determineVictor(StateManager);
    }
}