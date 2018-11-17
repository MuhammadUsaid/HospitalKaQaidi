#pragma once
#include "Screen.h"
class Game
{
    Screen* currentScreen;
    SDL_Renderer* renderer;
    bool running;
public:
    Game();
    Game(const char*, int , int);
    ~Game();
    void Init(int width, int height);
    void HandleEvents();
    void Update();
    void Clean();
    void Render();
    bool IsRunning();
};
