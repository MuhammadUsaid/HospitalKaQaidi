#pragma once
#include "List.h"
#include "Screen.h"

class GameScreen: public Screen
{
    List* enemiesList;
    List* objectList;
public:
    Pause();
    GameScreen();
    ~GameScreen();
    void Render(SDL_Renderer*);
};
