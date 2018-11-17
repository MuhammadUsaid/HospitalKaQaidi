#pragma once
#include "Screen.h"

class SplashScreen: public Screen
{
    SDL_Texture* backGround;
public:
    SplashScreen();
    ~SplashScreen();
    void Render();
    void Render(SDL_Renderer*);
}
