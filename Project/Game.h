#pragma once
#include <iostream>
#include <SDL2/SDL.h>

class Game
{
private:
    bool running;
    SDL_Window* window = nullptr;
public:
    Game(const char* title, int _width, int _height);
    bool Init(const char* title);
    bool IsRunning(){ return running; }
    void PollEvents(SDL_Event &e);
    int width, height;
    SDL_Renderer* render = nullptr;
    void Clear();
    ~Game();
};
