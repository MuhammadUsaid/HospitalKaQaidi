#pragma once
#include "Screen.h"
#include <SDL.h>
class MenuScreen: public Screen
{
    Button newGame;
    Button loadGame;
    Button quit;
    SDL_Texture* backGround;
public:
    void Load();
    MenuScreen();
    ~MenuScreen();
    void Render(SDL_Renderer*);
};
