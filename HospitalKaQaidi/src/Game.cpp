#include "Game.h"
#include <iostream>
#include "TextureManager.h"
#include <stdlib.h>
#include "GameObject.h"
#include "Player.h"

using namespace std;

SDL_Renderer* Game::renderer = nullptr;
int Game::width = 0;
int Game::height = 0;
int x, y;
SDL_Rect src[3], dst[3];
GameObject* player;
Player* one;

Game::Game(const char* title, int w, int h)
{
    width = w;
    height = h;
    Init(title, width, height);
    playerTexture = TextureManager::LoadTexture("Images/boy.png");
    x = y = 0;
    player = new GameObject("Images/boy.png", 0, 25, 100, 100);
    one = new Player();
    chair = TextureManager::LoadTexture("Images/chair.png");
    bed = TextureManager::LoadTexture("Images/bed.png");
    cupboard = TextureManager::LoadTexture("Images/cupboard.png");
    GenerateObjects();
}
void Game::GenerateObjects()
{
    src[0] = {30,0, 210, 225};
    dst[0] = {rand() % (width - 200), (rand() % (height - 200)) + 100, 80, 80};
    src[1] = {0, 0, 600, 340};
    dst[1] = {rand() % (width - 100), 0, 100, 100};
    src[2] = {0, 0, 650, 1300};
    dst[2] = {width - 100, rand() % (height - 100), 100, 100};
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
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
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
    case SDL_KEYDOWN:
        switch(e.key.keysym.sym)
        {
        case SDLK_ESCAPE:
            running = false;
            break;
        case SDLK_UP:
            one->MoveUp();
            break;
        case SDLK_DOWN:
            one->MoveDown();
            break;
        case SDLK_RIGHT:
            one->MoveRight();
            break;
        case SDLK_LEFT:
            one->MoveLeft();
            break;
        }
        break;
    case SDL_KEYUP:
        switch(e.key.keysym.sym)
        {
        case SDLK_UP:
            //one->StopMotion('u');
            break;
        }
    default:
        break;
    }
}

void Game::Update()
{
    player->Update();
    one->Update();
}

/**** Method To Render All The Objects On Screen ****/

void Game::Render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(Game::renderer, chair, &src[0], &dst[0]);
    SDL_RenderCopy(Game::renderer, bed, &src[1], &dst[1]);
    SDL_RenderCopy(Game::renderer, cupboard, &src[2], &dst[2]);
    player->Render();
    one->Render();
    SDL_RenderPresent(renderer);
}

void Game::Clean()
{
    SDL_DestroyWindow(window);
    window = nullptr;
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    SDL_Quit();
    delete player;
}

Game::~Game()
{
    Clean();
}
