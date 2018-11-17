#pragma once

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<stdio.h>

using namespace std;

class LoadTexture
{
private:
    SDL_Texture* texture;
    int width;
    int height;

public:
    LoadTexture();
    ~LoadTexture();
    bool LoadFromFile(string, SDL_Renderer*, bool flagColorKey = true, Uint8 redColorKey = 0, Uint8 greenColorKey = 0xFF, Uint8 blueColorKey = 0xFF);        ///takes arguments to ColorKey
    void RenderTexture(int x, int y, SDL_Renderer* gRenderer, SDL_Rect* clip = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE, double angle = 0.0, SDL_Point* center = NULL, float scale = 1);
    void Free();
    //Set blending
    void setBlendMode( SDL_BlendMode blending );
    //Set alpha modulation
    void setAlpha( Uint8 alpha );
    int GetWidth();
    int GetHeight();
};
