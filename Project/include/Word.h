#pragma once
#include "LoadTexture.h"
#include "Point.h"

class Word
{
    Point position;
    char* renderWord;
    LoadTexture* textTexture;
    Character* characters;
public:
    Word(string, Loadtexture*)
    void Render(SDL_Renderer*);
    void SetText(char*);
    void SetPosition(Point&);
    int GetTextlength();
};
