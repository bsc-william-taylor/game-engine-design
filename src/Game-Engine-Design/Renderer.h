
/* ------------------------------------------------

	@File		: Renderer.h
	@Date		: 21/11/2013
	@Purpose	:

		A abstract renderer class to implment
		the renderer design pattern. Virtual 
		methods represent items that need 
		to be drawn

 ------------------------------------------------ */

#pragma once

#include "Objects.h"

class Renderer {
	public:
	Renderer() {
		// Not Needed
	}

		// The following functions need to be provided if you want to have a new renderer
		virtual void backgroundColour(float, float, float, float) = 0;
		virtual void drawCharacterVector(vector<Character*>&) = 0;
		virtual void drawLabelArray(Label*[], int, int) = 0;
		virtual void drawItemVector(vector<Item*>&) = 0;
		virtual void drawLabelArray(Label*[], int) = 0;
		virtual void drawCharacter(Character*) = 0;
		virtual void drawPlayerStats(Player*) = 0;
		virtual void drawPlayer(Character*) = 0;
		virtual void drawFullNpc(NPC *) = 0;
		virtual void drawLabel(Label*) = 0;
		virtual void drawItem(Item *) = 0;
		virtual void drawShop(Shop *) = 0;
		virtual void clearScreen() = 0;

	virtual ~Renderer() {
		// Not Needed
	}
};