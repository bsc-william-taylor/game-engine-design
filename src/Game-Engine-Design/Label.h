
#pragma once

#include "Main.h"
#include "Object.h"

class Label : public Object
{
private:
    TTF_Font * font;
    string textFile;
    GLuint textureID;
    bool dontDelete;
public:
    Label();
    ~Label();

    void textToTexture(string);
    void setText(string, int);
    void setFont(TTF_Font *);

    TTF_Font * getFont();
    GLuint getID();
};