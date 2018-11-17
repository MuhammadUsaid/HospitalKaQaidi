#pragma once
#include "LoadTexture.h"

class Character
{
    Point position;
    SDL_Rect charRect;
    char shownChar;
    LoadTexture* CharTexture;
public:
    Character();
    Character(char, LoadTexture*);
    void Render(SDL_Renderer*);
    void SetPosition(Point&);
    void SetChar(char);
    void SetTexture(LoadTexture*, char);
};
