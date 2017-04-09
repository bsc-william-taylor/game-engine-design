
#include "RendererGL.h"

RendererGL::RendererGL()
{
    glEnable(GL_TEXTURE_2D);
}

RendererGL::~RendererGL()
{
    glDisable(GL_TEXTURE_2D);
}

void RendererGL::drawCharacterVector(vector<Character*>& npc)
{
    for (auto i = 0; i < npc.size(); i++)
    {
        if (!npc[i]->isKilled())
        {
            drawCharacter(npc[i]);
        }
    }
}

void RendererGL::drawItem(Item * object)
{
    int x = object->getPosition().getX();
    int y = object->getPosition().getY();
    int w = object->getSize().getX();
    int h = object->getSize().getY();

    glBegin(GL_QUADS);
    glColor3f(object->getColour().r, object->getColour().g, object->getColour().b);
    glTexCoord2d(0, 1);	glVertex2i(x, y);
    glTexCoord2d(1, 1);	glVertex2i(x + w, y);
    glTexCoord2d(1, 0);	glVertex2i(x + w, y + h);
    glTexCoord2d(0, 0);	glVertex2i(x, y + h);
    glEnd();
}

void RendererGL::drawItemVector(vector<Item *>& items)
{
    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (!items[i]->isUsed())
        {
            drawItem(items[i]);
        }
    }
}

void RendererGL::drawCharacter(Character * npc)
{
    int x = npc->getPosition().getX();
    int y = npc->getPosition().getY();
    int w = npc->getSize().getY();
    int h = npc->getSize().getX();

    glBegin(GL_QUADS);
    glColor3f(npc->getColour().r, npc->getColour().g, npc->getColour().b);
    glVertex2i(x, y);
    glVertex2i(x + w, y);
    glVertex2i(x + w, y + h);
    glVertex2i(x, y + h);
    glEnd();

    npc->getLabel()->setPosition(Vector<int>(x, y));
    drawLabel(npc->getLabel());
}

void RendererGL::drawLabelArray(Label* label[], int start, int size)
{
    for (int i = start; i < size; i++)
    {
        drawLabel(label[i]);
    }
}

void RendererGL::drawPlayer(Character * c_player)
{
    drawCharacter(c_player);
    string strStats;
    Label stats;
    Player * playerCharacter = (Player *)c_player;

    strStats.append(" Health : " + std::to_string(playerCharacter->getStats().health));
    strStats.append(" Strength : " + std::to_string(playerCharacter->getStats().strength));
    strStats.append(" Speed : " + std::to_string(playerCharacter->getStats().speed));
    strStats.append(" Cash : " + std::to_string(playerCharacter->getStats().cash));

    stats.setFont(playerCharacter->getLabel()->getFont());
    stats.textToTexture(strStats);
    stats.setPosition(Vector<int>(10, 10));
    stats.setSize(Vector<int>(250, 10));

    drawLabel(&stats);
}

void RendererGL::drawShop(Shop * shop)
{
    int x = shop->getPosition().getX();
    int y = shop->getPosition().getY();
    int h = shop->getSize().getY();
    int w = shop->getSize().getX();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.0f);
    glVertex2i(x, y);
    glVertex2i(x + w, y);
    glVertex2i(x + w, y + h);
    glVertex2i(x, y + h);

    glEnd();

    shop->getLabel()->setPosition(Vector<int>(x, y));
    drawLabel(shop->getLabel());
}

void RendererGL::drawLabel(Label * object)
{
    int x = object->getPosition().getX();
    int y = object->getPosition().getY();
    int w = object->getSize().getX();
    int h = object->getSize().getY();

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBindTexture(GL_TEXTURE_2D, object->getID());
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_QUADS);
    glTexCoord2d(0, 1);	glVertex2i(x, y);
    glTexCoord2d(1, 1);	glVertex2i(x + w, y);
    glTexCoord2d(1, 0);	glVertex2i(x + w, y + h);
    glTexCoord2d(0, 0);	glVertex2i(x, y + h);

    glEnd();
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
}

void RendererGL::backgroundColour(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
}

void RendererGL::clearScreen()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RendererGL::drawFullNpc(NPC * npc)
{
    drawCharacter(npc);

    string strStats;
    Label stats;

    strStats.append(" Health : " + std::to_string(npc->getStats().health));
    strStats.append(" Strength : " + std::to_string(npc->getStats().strength));
    strStats.append(" Speed : " + std::to_string(npc->getStats().speed));

    stats.setFont(npc->getLabel()->getFont());
    stats.textToTexture(strStats);
    stats.setPosition(Vector<int>(400, 10));
    stats.setSize(Vector<int>(250, 10));

    drawLabel(&stats);
}

void RendererGL::drawPlayerStats(Player* playerCharacter)
{
    string strStats;
    Label stats;

    strStats.append(" Health : " + std::to_string(playerCharacter->getStats().health));
    strStats.append(" Strength : " + std::to_string(playerCharacter->getStats().strength));
    strStats.append(" Speed : " + std::to_string(playerCharacter->getStats().speed));
    strStats.append(" Cash : " + std::to_string(playerCharacter->getStats().cash));

    stats.setFont(playerCharacter->getLabel()->getFont());
    stats.textToTexture(strStats);
    stats.setPosition(Vector<int>(10, 10));
    stats.setSize(Vector<int>(250, 10));

    drawLabel(&stats);
}

void RendererGL::drawLabelArray(Label* label[], int number)
{
    for (int i = 0; i < number; i++)
    {
        drawLabel(label[i]);
    }
}