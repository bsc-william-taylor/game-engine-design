

#pragma once

#include "StateManager.h"
#include "Collision.h"
#include "Objects.h"
#include "Border.h"
#include "Vector.h"
#include "States.h"

class Map : public State
{
    vector<Collision *> enemyCollisions;
    vector<Collision *> itemCollisions;
    vector<Character *> enemies;
    vector<Item *> items;

    Character* playerCharacter;
    Collision* storeCollision;
    Border* borderCollision;
    Shop* store;

    int monstersAlive;
public:
    Map(Factory *);
    ~Map();

    void onEvent(StateManager&, SDL_Event&);
    void onDraw(Renderer&, StateManager&);
    void onUpdate(StateManager&);
    void onEnter(StateManager&);
    void onExit(StateManager&);

    void initialiseEnemies();
    void initialiseItems();
    void resetMap();
};