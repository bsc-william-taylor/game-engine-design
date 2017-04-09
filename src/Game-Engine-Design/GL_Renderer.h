
/* ------------------------------------------------

	@File		: GL_Renderer.h
	@Date		: 08/11/2013
	@Purpose	:

		A class that implements the draw functions
		required and draws objects use the OpenGL
		API.

 ------------------------------------------------ */

#pragma once

#include "Renderer.h"
#include "Vector.h"
#include "Label.h"

class GL_Renderer : public Renderer {
	public:
	GL_Renderer();

		void backgroundColour(float, float, float, float);
		void drawCharacterVector(vector<Character*>&);
		void drawDharacterWithStats(Character *);
		void drawLabelArray(Label*[], int, int);
		void drawItemVector(vector<Item *>&);
		void drawLabelArray(Label*[], int);
		void drawFullNpc(NPC *);
		void drawCharacter(Character*);
		void drawPlayerStats(Player*);
		void drawPlayer(Character*);
		void drawLabel(Label*);
		void drawShop(Shop *);
		void drawItem(Item *);
		void clearScreen();

	~GL_Renderer();
};