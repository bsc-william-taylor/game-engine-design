
#include "Label.h"

Label::Label()
{
    glGenTextures(1, &textureID);
    dontDelete = true;
    font = NULL;
}

Label::~Label()
{
    if (!dontDelete)
    {
        TTF_CloseFont(font);
    }

    glDeleteTextures(1, &textureID);
}

void Label::textToTexture(std::string str)
{
    if (font)
    {
        SDL_Surface *stringImage;
        SDL_Color colour = { 0, 0, 0 };

        stringImage = TTF_RenderText_Blended(font, str.c_str(), colour);

        GLuint colours = stringImage->format->BytesPerPixel;
        GLuint format, internalFormat;

        if (colours == 4)
        {
            if (stringImage->format->Rmask == 0x000000ff)
                format = GL_RGBA;
            else
                format = GL_BGRA_EXT;
        }
        else
        {
            if (stringImage->format->Rmask == 0x000000ff)
                format = GL_RGB;
            else
                format = GL_BGR_EXT;
        }

        internalFormat = (colours == 4) ? GL_RGBA : GL_RGB;

        size = Vector<int>(stringImage->w, stringImage->h);

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, stringImage->w, stringImage->h, 0, format, GL_UNSIGNED_BYTE, stringImage->pixels);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

        SDL_FreeSurface(stringImage);
    }
}

void Label::setText(string filename, int size)
{
    font = TTF_OpenFont(filename.c_str(), size);
    dontDelete = false;
}

void Label::setFont(TTF_Font * ttf_font)
{
    dontDelete = true;
    font = ttf_font;
}

TTF_Font * Label::getFont()
{
    return font;
}

GLuint Label::getID()
{
    return textureID;
}