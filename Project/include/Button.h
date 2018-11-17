#pragma once
#include "LoadTexture.h"
#include "Point.h"

class Button
{
    Point position;
    SDL_Rect buttonRect[3];
    LoadTexture* buttonTexture;
public:
    Button(Loadtexture*, string, int, int);
    void Render(SDL_Renderer*);
    void SetPosition(Point&);
    void SetText(const char*);
    Word word;
};
