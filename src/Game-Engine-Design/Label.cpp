
/* ------------------------------------------------

	@File		: Label.cpp
	@Date		: 21/11/2013
	@Purpose	:

		Class implementation

 ------------------------------------------------ */

#include "Label.h"

// Constructor & Deconstructor
Label::Label() {
	// Generate one texture
	glGenTextures(1, &TexID);
	dontDelete = true;
	font = NULL;
}

Label::~Label() {
	if(!dontDelete) {
		TTF_CloseFont(font);
	}

	glDeleteTextures(1, &TexID);
}

// Functions
void Label::TextToTexture(std::string str) {
	// if the font has been created
	if(font) {
		SDL_Surface *stringImage;
		SDL_Color colour = { 0, 0, 0 };
	
		stringImage = TTF_RenderText_Blended(font, str.c_str(), colour);

		GLuint colours = stringImage->format->BytesPerPixel;
		GLuint format, internalFormat;
	
		if(colours == 4) {   
			if(stringImage->format->Rmask == 0x000000ff) {
				format = GL_RGBA;
			}
			else {
				format = GL_BGRA_EXT;
			}
		}
		else {           
			if (stringImage->format->Rmask == 0x000000ff) {
				format = GL_RGB;
			}
			else {
				format = GL_BGR_EXT;
			}
		}

		internalFormat = (colours == 4) ? GL_RGBA : GL_RGB;

		// Bind gl texture
		glBindTexture(GL_TEXTURE_2D, TexID); 

		// set settings for the texture
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		// get the size of the image
		size = Vector<int>(stringImage->w, stringImage->h );

		// load the data into opengl
		glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, stringImage->w, stringImage->h, 0, format, GL_UNSIGNED_BYTE, stringImage->pixels);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

		// free the surface SDL created
		SDL_FreeSurface(stringImage);
	}
}

void Label::SetText(string filename, int size) {
	// load the font
	font = TTF_OpenFont(filename.c_str(), size);
	dontDelete = false;
}

void Label::SetFont(TTF_Font * ttf_font) { 
	// set the font variable and tell the class 
	// not to delete it.
	dontDelete = true; 
	font = ttf_font; 
}

TTF_Font * Label::getFont(){ 
	return font; 
}

GLuint Label::getID() {
	return TexID;
}