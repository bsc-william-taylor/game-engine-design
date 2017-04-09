
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

    ~Factory()
    {
        for (auto i = 0; i < renderObjects.size(); i++)
        {
            delete renderObjects[i];
        }
    }

    template<class T>
    T* newObject(string name) 
    {
        int size = renderObjects.size();
        renderObjects.push_back(new T());
        renderName.push_back(name);
        return static_cast<T *>(renderObjects[size]);
    }

    template<class T>
    T* newCharacter(string name, PlayerFile * file) 
    {
        int size = renderObjects.size();
        renderObjects.push_back(new T(file));
        renderName.push_back(name);
        return static_cast<T *>(renderObjects[size]);
    }

    template<class T>
    T* newCharacter(string name, MonsterFile * file) 
    {
        int size = renderObjects.size();
        renderObjects.push_back(new T(file));
        renderName.push_back(name);
        return static_cast<T *>(renderObjects[size]);
    }

    template<class T>
    T* getObject(string name) 
    {
        for (auto i = 0; i < renderName.size(); i++) 
        {
            if (name == renderName[i]) 
            {
                return static_cast<T *>(renderObjects[i]);
            }
        }

        string message = "Couldnt get object : " + name;
        game->exitError(message.c_str());
        return NULL;
    }
};