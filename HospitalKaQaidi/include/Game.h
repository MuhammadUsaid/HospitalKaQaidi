#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Game
{
private:
    SDL_Window* window;
    SDL_Texture* playerTexture;
    SDL_Texture* cupboard;
    SDL_Texture* chair;
    SDL_Texture* bed;
    bool running;
    void GenerateObjects();
public:
    Game(const char* title, int width, int height);
    ~Game();
    static int width, height;
    static SDL_Renderer* renderer;
    void Init(const char* title, int width, int height);
    void HandleEvents();
    void Update();
    void Render();
    void Clean();
    bool isRunning();
};
