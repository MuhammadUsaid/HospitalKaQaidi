#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(const char* title, int width, int height)
{
    this->width = width;
    this->height = height;
    window = nullptr;
    renderer = nullptr;
    playerTexture = nullptr;
}

/*** Get Running State ***/
bool Game::isRunning()
{
    return running;
}
/****Method To Initialize Everything and show error if something fails****/

void Game::Init(const char* title, int width, int height)
{
    running = false;
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) //Initializing SDL
    {
        cerr << "SDL Not Initialized! " << SDL_GetError() << endl;
        return;
    }
    if(IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG || IMG_Init(IMG_INIT_JPG) != IMG_INIT_JPG)
    {
        cerr << "Image Not Initialized! " << IMG_GetError() << endl;
        return;
    }
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, false);
    if(window == nullptr)
    {
        cerr << "Window Not Created! " << SDL_GetError() << endl;
        return;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer == nullptr)
    {
        cerr << "Renderer Not Created! " << SDL_GetError() << endl;
        return;
    }
    running = true;
    //Temporary Harkaten
    SDL_Surface* tempSurface = IMG_Load("Images/boy.png");
    playerTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
}

/**** Method To Handle Events ****/

void Game::HandleEvents()
{
    SDL_Event e;
    SDL_PollEvent(&e);
    switch(e.type)
    {
    case SDL_QUIT:
        running = false;
        break;
    case SDL_MOUSEBUTTONDOWN:
        break;
    default:
        break;
    }
}

void Game::Update()
{

}

/**** Method To Render All The Objects On Screen ****/

void Game::Render()
{
    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    SDL_RenderClear(renderer);
    SDL_Rect src = {0, 0, 50, 50};
    SDL_Rect dst = {width/2, height/2, 75, 75};
    SDL_RenderCopy(renderer, playerTexture, &src, &dst);
    SDL_RenderPresent(renderer);
}

void Game::Clean()
{
    SDL_DestroyWindow(window);
    window = nullptr;
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    SDL_Quit();
}

