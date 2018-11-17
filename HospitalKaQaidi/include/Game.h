#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Game
{
private:
    int width, height;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* playerTexture;
    bool running;
public:
    Game(const char* title, int width, int height);
    //~Game();
    void Init(const char* title, int width, int height);
    void HandleEvents();
    void Update();
    void Render();
    void Clean();
    bool isRunning();
};
