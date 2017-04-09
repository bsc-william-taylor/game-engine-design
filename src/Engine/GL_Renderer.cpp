
/* ------------------------------------------------

	@File		: GL_Renderer.cpp
	@Date		: 08/11/2013
	@Purpose	:

		GL_Renderer class implementation

 ------------------------------------------------ */

#include "GL_Renderer.h"

// Constructor & Deconstructor
GL_Renderer::GL_Renderer() {
	glEnable(GL_TEXTURE_2D);
}

GL_Renderer::~GL_Renderer() {
	glDisable(GL_TEXTURE_2D);
}

// Functions
void GL_Renderer::drawCharacterVector(vector<Character*>& npc) {
	for(unsigned int i = 0; i < npc.size(); i++) {
		if(!npc[i]->isKilled()) {
			drawCharacter(npc[i]);
		}
	}
}

void GL_Renderer::drawItem(Item * object) {
	// Get object positions
	int x = object->getPosition().getX();
	int y = object->getPosition().getY();
	int w = object->getSize().getX();
	int h = object->getSize().getY();

	// Draw Object
	glBegin(GL_QUADS);

		glColor3f(object->getColour().r, object->getColour().g, object->getColour().b);

		glTexCoord2d(0,1);	glVertex2i(x, y); 
		glTexCoord2d(1,1);	glVertex2i(x + w, y); 
		glTexCoord2d(1,0);	glVertex2i(x + w, y + h); 
		glTexCoord2d(0,0);	glVertex2i(x, y + h); 

	glEnd();
}

void GL_Renderer::drawItemVector(vector<Item *>& items) {
	// Go through the vector and draw each element
	for(unsigned int i = 0; i < items.size(); i++) {
		// only if it hasnt been used
		if(!items[i]->isUsed()) {
			drawItem(items[i]);
		}
	}
}

void GL_Renderer::drawCharacter(Character * npc){
	// Get object positions
	int x = npc->getPosition().getX();
	int y = npc->getPosition().getY();
	int w = npc->getSize().getY();
	int h = npc->getSize().getX();

	// Draw object
	glBegin(GL_QUADS);

		glColor3f(npc->getColour().r, npc->getColour().g, npc->getColour().b);

		glVertex2i(x, y); 
		glVertex2i(x + w, y); 
		glVertex2i(x + w, y + h); 
		glVertex2i(x, y + h); 

	glEnd();

	// The draw label
	npc->getLabel()->setPosition(Vector<int>(x, y));
	drawLabel(npc->getLabel());
}

void GL_Renderer::drawLabelArray(Label* label[], int start, int size) {
	// draw a section of the array
	for(int i = start; i < size; i++) {
		// draw label
		drawLabel(label[i]);
	}
}

void GL_Renderer::drawPlayer(Character * c_player) {
	// Draw Character first
	drawCharacter(c_player);
	string strStats;
	Label stats;
	Player * player = (Player *)c_player;

	strStats.append(" Health : " + std::to_string(player->getStats().Health));
	strStats.append(" Strength : " + std::to_string(player->getStats().Strength));
	strStats.append(" Speed : " + std::to_string(player->getStats().Speed));
	strStats.append(" Cash : " + std::to_string(player->getStats().Cash));

	stats.SetFont(player->getLabel()->getFont());
	stats.TextToTexture(strStats);
	stats.setPosition(Vector<int>(10, 10));
	stats.setSize(Vector<int>(250, 10));

	drawLabel(&stats);
}

void GL_Renderer::drawShop(Shop * shop) {
	// Get positions
	int x = shop->getPosition().getX();
	int y = shop->getPosition().getY();
	int h = shop->getSize().getY();
	int w = shop->getSize().getX();

	// Draw object
	glBegin(GL_QUADS);

		glColor3f(0.5f, 0.5f, 0.0f);

		glVertex2i(x, y); 
		glVertex2i(x + w, y); 
		glVertex2i(x + w, y + h); 
		glVertex2i(x, y + h); 

	glEnd();

	// Draw label
	shop->getLabel()->setPosition(Vector<int>(x, y));
	drawLabel(shop->getLabel());
}

void GL_Renderer::drawLabel(Label * object) {
	// get positions
	int x = object->getPosition().getX();
	int y = object->getPosition().getY();
	int w = object->getSize().getX();
	int h = object->getSize().getY();

	// Bind texture
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBindTexture(GL_TEXTURE_2D, object->getID()); 
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Draw Object
	glBegin(GL_QUADS);

		glTexCoord2d(0,1);	glVertex2i(x, y); 
		glTexCoord2d(1,1);	glVertex2i(x + w, y); 
		glTexCoord2d(1,0);	glVertex2i(x + w, y + h); 
		glTexCoord2d(0,0);	glVertex2i(x, y + h); 

	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
}

void GL_Renderer::backgroundColour(float r, float g, float b, float a) {
	// set background colour
	glClearColor(r, g, b, a);
}

void GL_Renderer::clearScreen() {
	// Clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GL_Renderer::drawFullNpc(NPC * npc) {
	drawCharacter(npc);

	string strStats;
	Label stats;

	strStats.append(" Health : " + std::to_string(npc->getStats().Health));
	strStats.append(" Strength : " + std::to_string(npc->getStats().Strength));
	strStats.append(" Speed : " + std::to_string(npc->getStats().Speed));

	stats.SetFont(npc->getLabel()->getFont());
	stats.TextToTexture(strStats);
	stats.setPosition(Vector<int>(400, 10));
	stats.setSize(Vector<int>(250, 10));

	drawLabel(&stats);
}

void GL_Renderer::drawPlayerStats(Player * player) {
	string strStats;
	Label stats;

	strStats.append(" Health : " + std::to_string(player->getStats().Health));
	strStats.append(" Strength : " + std::to_string(player->getStats().Strength));
	strStats.append(" Speed : " + std::to_string(player->getStats().Speed));
	strStats.append(" Cash : " + std::to_string(player->getStats().Cash));

	stats.SetFont(player->getLabel()->getFont());
	stats.TextToTexture(strStats);
	stats.setPosition(Vector<int>(10, 10));
	stats.setSize(Vector<int>(250, 10));

	drawLabel(&stats);
}

void GL_Renderer::drawLabelArray(Label * label[], int number)  {
	// Go through the vector
	for(int i = 0; i < number; i++) {
		// draw each element
		drawLabel(label[i]);
	}
}