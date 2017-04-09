
#pragma once

#include "MonsterFile.h"
#include "PlayerFile.h"
#include "Object.h"
#include "Game.h"

class Factory 
{
    vector<Object*> renderObjects;
    vector<string> renderName;

    Game* game;
public:
    Factory(Game* game) :
        game(game)
    {
    }

    // Methods that allows to add new assets to the factory.
    template<class T>
    T * newObject(string name) {
        // get size before insertion so we can access the object
        int size = renderObjects.size();

        // push back new object & its name
        renderObjects.push_back(new T());
        renderName.push_back(name);

        // Cast it and return to user
        return static_cast<T *>(renderObjects[size]);
    }

    // Create a new character from a player file
    template<class T>
    T * newCharacter(string name, PlayerFile * file) {
        // get size before insertion so we can access the object
        int size = renderObjects.size();

        // push back new object & its name
        renderObjects.push_back(new T(file));
        renderName.push_back(name);

        // Cast it and return to user
        return static_cast<T *>(renderObjects[size]);
    }

    // Create a new character from a Monster file
    template<class T>
    T * newCharacter(string name, MonsterFile * file) {
        // get size before insertion so we can access the object
        int size = renderObjects.size();

        // push back new object & its name
        renderObjects.push_back(new T(file));
        renderName.push_back(name);

        // Cast it and return to user
        return static_cast<T *>(renderObjects[size]);
    }

    // Method used by states to aquire a pointer to assets
    template<class T>
    T * getObject(string name) {
        // Search through the vector for the name
        for (unsigned int i = 0; i < renderName.size(); i++) {
            // if found
            if (name == renderName[i]) {
                // return the related object in the renderObjects Vector
                return static_cast<T *>(renderObjects[i]);
            }
        }

        // You should never reach this code
        string message = "Couldnt get object : " + name;
        game->ExitError(message.c_str());
        return NULL;
    }

    ~Factory() {
        // Delete all objects
        for (unsigned int i = 0; i < renderObjects.size(); i++) {
            delete renderObjects[i];
        }
    }
};