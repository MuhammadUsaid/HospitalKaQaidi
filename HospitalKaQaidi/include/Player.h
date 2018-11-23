#pragma once
#include "GameObject.h"


class Player : public GameObject
{
    public:
        Player();
        void MoveUp();
        void MoveDown();
        void MoveRight();
        void MoveLeft();
        void StopMotion(char direction);
        void Update();
        //~Player();
    private:
        int speed;
        bool CompareRects(SDL_Rect, SDL_Rect);
        SDL_Rect moveUp[4];
        SDL_Rect moveDown[4];
        SDL_Rect moveRight[4];
        SDL_Rect moveLeft[4];
        SDL_Rect stop[4];
};
