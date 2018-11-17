#pragma once
#include "Screen.h"
class QuitScreen: public Screen
{
    Word gameOver;
    Button tryAgain;
    Button quit;
    SDL_Texture* backGround;
public:
    QuitScreen();
    ~QuitScreen();
    void Render(SDL_Renderer*);
};
