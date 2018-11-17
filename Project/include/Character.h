#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LoadTexture.h"
#include"Point.h"

class Character
{
private:
    Point position; //Position of the Character
    int character_value = 0; //ascii value of the Character
    int width; //width of character
    int height; //height of character
    SDL_Rect spriteClips; //clip specific to the Character
    LoadTexture* spriteSheetTexture; //font image
public:
    Character();
    Character(LoadTexture* image, float x, float y, int ascii);
    ~Character();
    void Render(SDL_Renderer* gRenderer, bool debug);
    void operator = (const Character& cpy); //operator overloading for assignment operatot
};

