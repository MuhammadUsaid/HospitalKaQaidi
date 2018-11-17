#include "Game.h"

using namespace std;

Game::Game(const char* title, int _width, int _height):
    width(_width), height(_height)
{
    running = Init(title);
}

bool Game::Init(const char* title)
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cerr << "SDL Not Initialized. Error: " << SDL_GetError() << endl;
        return false;
    }
    if(IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        cerr << "Image Not Initialized" << endl;
        return false;
    }
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if(!window)
    {
        cerr << "Windows Not Created" << endl;
        return false;
    }
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!render)
    {
        cerr << "Renderer Not Created" << endl;
        return false;
    }
    return true;
}

void Game::PollEvents(SDL_Event& e)
{
    switch(e.type)
    {
    case SDL_QUIT:
        running = false;
        break;
    case SDL_KEYDOWN:
        switch(e.key.keysym.sym)
        {
        case SDLK_ESCAPE:
            running = false;
            break;
        default:
            break;
        }
    default:
        break;
    }
}

void Game::Clear()
{
    SDL_RenderPresent(render);
    SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
    SDL_RenderClear(render);
}

Game::~Game()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render);
    window = nullptr;
    render = nullptr;
    SDL_Quit();
}
