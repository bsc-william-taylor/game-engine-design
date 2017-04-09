
#include "ShopState.h"
#include "States.h"

Store::Store(Factory * renderList)
{
    playerCharacter = renderList->getObject<Player>("Player");
    string labelText[] =
    {
        "Buy Health Pack $10 (H)",
        "Buy Combat Pack $10 (C)",
        "Buy Stimulant $10 (K)",
        "Exit (E)"
    };

    int labelPosition[] =
    {
        300, 250, 200, 150
    };

    for (auto i = 0; i < 4; i++)
    {
        storeLabels[i] = renderList->newObject<Label>("shopText" + i);
        storeLabels[i]->setPosition(Vector<int>(20, labelPosition[i]));
        storeLabels[i]->setText("Data/MavenPro-Regular.ttf", 35);
        storeLabels[i]->textToTexture(labelText[i]);
    }
}

Store::~Store()
{
}

void Store::buyItem(ItemType item)
{
    Item * temp;

    if (playerCharacter->getStats().cash >= 10)
    {
        if (item == STIMULANT) 
            temp = new StimulantPack();
        if (item == COMBAT) 
            temp = new CombatPack();
        if (item == HEALTH) 
            temp = new HealthPack();

        playerCharacter->getStats().cash -= 10;
        temp->onConsume(playerCharacter);
        delete temp;
    }
}

void Store::onDraw(Renderer& renderer, StateManager& state)
{
    renderer.clearScreen();
    renderer.backgroundColour(0.5, 0.0, 0.5, 0.0);
    renderer.drawLabelArray(storeLabels, 4);
    renderer.drawPlayerStats(playerCharacter);
}

void Store::onEvent(StateManager& state, SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_ESCAPE:
        case SDLK_e: state.switchState(MapScene); break;
        case SDLK_k: buyItem(STIMULANT); break;
        case SDLK_c: buyItem(COMBAT); break;
        case SDLK_h: buyItem(HEALTH); break;

        default:  break;
        }
    }
}

void Store::onExit(StateManager&)
{
    playerCharacter->save();
}

void Store::onUpdate(StateManager& state)
{
}

void Store::onEnter(StateManager&)
{
}