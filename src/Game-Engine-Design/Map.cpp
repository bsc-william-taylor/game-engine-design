
#include "Map.h"

Map::Map(Factory * renderList)
{
    playerCharacter = renderList->newCharacter<Player>("Player", State::playerFile);

    store = renderList->newObject<Shop>("store");
    store->setPosition(Vector<int>(50, 300));
    store->setSize(Vector<int>(50, 50));

    storeCollision = new Collision(playerCharacter, store);
    borderCollision = new Border(playerCharacter);

    initialiseEnemies();
    initialiseItems();
}

Map::~Map()
{
    for (auto i = 0; i < enemyCollisions.size(); i++)
    {
        delete enemyCollisions[i];
    }

    for (auto i = 0; i < enemies.size(); i++)
    {
        delete enemies[i];
    }
}

void Map::onDraw(Renderer& renderer, StateManager& state)
{
    renderer.clearScreen();
    renderer.backgroundColour(0.1f, 0.1f, 0.1f, 0.0);
    renderer.drawItemVector(items);
    renderer.drawCharacterVector(enemies);
    renderer.drawPlayer(playerCharacter);
    renderer.drawShop(store);
}

void Map::initialiseItems()
{
    for (int i = 0; i < itemFile->getItemNumbers(); i++)
    {
        Item * temp = itemFile->getItem(i);
        items.push_back(temp);
        itemCollisions.push_back(new Collision(playerCharacter, items[i]));
    }
}

void Map::initialiseEnemies()
{
    for (int i = 0; i < npcFile->getMonsterNumbers(); i++)
    {
        Character * temp = npcFile->getCharacter(i);
        enemies.push_back(temp);
        enemyCollisions.push_back(new Collision(playerCharacter, enemies[i]));
    }
}

void Map::onEvent(StateManager& state, SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_ESCAPE: state.switchState(1); break;
        case SDLK_DOWN:
        case 's':
        case 'S': static_cast<Player *>(playerCharacter)->moveY(-10); break;
        case SDLK_LEFT:
        case 'a':
        case 'A': static_cast<Player *>(playerCharacter)->moveX(-10); break;
        case SDLK_UP:
        case 'w':
        case 'W': static_cast<Player *>(playerCharacter)->moveY(10); break;
        case SDLK_RIGHT:
        case 'd':
        case 'D': static_cast<Player *>(playerCharacter)->moveX(10); break;
        default: break;
        }
    }
}

void Map::resetMap()
{
    playerCharacter->reset();

    for (auto i = 0; i < enemies.size(); i++)
    {
        enemies[i]->reset();
    }

    for (auto i = 0; i < items.size(); i++)
    {
        items[i]->reset();
    }
}

void Map::onEnter(StateManager& state)
{
    playerCharacter->load();
    monstersAlive = 0;

    for (unsigned int i = 0; i < enemies.size(); i++)
    {
        enemies[i]->load();
        if (!enemies[i]->isKilled())
        {
            monstersAlive++;
        }
    }

    for (auto i = 0; i < items.size(); i++)
    {
        items[i]->load();
    }

    if (monstersAlive == 0)
    {
        state.getState<GameOver>(GameOverScene)->setWinner(true);
        state.switchState(GameOverScene);
    }

    if (playerCharacter->isKilled())
    {
        state.getState<GameOver>(GameOverScene)->setWinner(false);
        state.switchState(GameOverScene);
    }
}

void Map::onExit(StateManager& state)
{
    playerCharacter->save();

    for (auto i = 0; i < enemies.size(); i++)
    {
        enemies[i]->save();
    }

    for (auto i = 0; i < items.size(); i++)
    {
        items[i]->save();
    }
}

void Map::onUpdate(StateManager& state) 
{
    for (auto i = 0; i < enemyCollisions.size(); i++) 
    {
        if (enemyCollisions[i]->hasTriggered()) 
        {
            enemyCollisions[i]->reset();
            Vector<int> Position = enemyCollisions[i]->getNode()->getPosition();
            playerCharacter->setPosition(Vector<int>(Position.getX(), Position.getY()));
            state.getState<Combat>(BattleScene)->setOpponent((NPC *)enemyCollisions[i]->getNode());
            state.switchState(BattleScene);
            break;
        }
    }

    for (auto i = 0; i < itemCollisions.size(); i++) 
    {
        if (itemCollisions[i]->hasTriggered()) 
        {
            itemCollisions[i]->reset();
            items[i]->onConsume((Player *)playerCharacter);
            break;
        }
    }

    if (storeCollision->hasTriggered()) 
    {
        storeCollision->reset();

        int y = store->getPosition().getY() - (int)(playerCharacter->getSize().getX() * 1.5);
        int x = store->getPosition().getX();

        playerCharacter->setPosition(Vector<int>(x, y));
        state.switchState(StoreScene);
    }
}