#pragma once
#include "Screen.h"

class PauseScreen: public Screen
{
    Button resume;
    Button save;
    Button quit;
public:
    void Resume();
    void Save();
    PauseScreen();
    ~PauseScreen();
    void Render(SDL_Renderer*);
};
