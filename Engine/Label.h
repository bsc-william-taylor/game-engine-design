
/* ------------------------------------------------

	@File		: Label.h
	@Date		: 21/11/2013
	@Purpose	:

		A simple label class that loads
		and renders text on to the screen
		it is used by mutilple classes.

 ------------------------------------------------ */

#pragma once

#include "Main.h"
#include "Object.h"

class Label : public Object {
	private:

		TTF_Font * font;
		string textFile;
		GLuint TexID;

		bool dontDelete;

	public:

	Label();

		void TextToTexture(string);
		void SetText(string, int);
		void SetFont(TTF_Font *);

		TTF_Font * getFont();
		GLuint getID();

	~Label();
};