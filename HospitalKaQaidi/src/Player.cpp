#include "Player.h"
#include "TextureManager.h"

Player::Player()
{
    x = Game::width/2;
    y = Game::height  - 50;
    width = 50;
    height = 50;
    speed = 4;
    currentTexture = TextureManager::LoadTexture("Images/boy.png");
    srcRect = {150, 0, 50, 50};
    dstRect = {x, y, width, height};
    moveUp[0] = {0, 200, width, height};
    moveUp[1] = {50, 200, width, height};
    moveUp[2] = {100, 200, width, height};
    moveUp[3] = {150, 200, width, height};
    moveDown[0] = {0, 150, width, height};
    moveDown[1] = {50, 150, width, height};
    moveDown[2] = {100, 150, width, height};
    moveDown[3] = {150, 150, width, height};
    moveRight[0] = {0, 50, width, height};
    moveRight[1] = {50, 50, width, height};
    moveRight[2] = {100, 50, width, height};
    moveRight[3] = {150, 50, width, height};
    moveLeft[0] = {0, 100, width, height};
    moveLeft[1] = {50, 100, width, height};
    moveLeft[2] = {100, 100, width, height};
    moveLeft[3] = {150, 100, width, height};
    stop[0] = {150, 0, width,height};
    stop[1] = {0, 0, width,height};
    stop[2] = {50, 0, width,height};
    stop[3] = {100, 0, width,height};
}

bool Player::CompareRects(SDL_Rect a, SDL_Rect b)
{
    if (a.w == b.w && a.h == b.h && a.x == b.x && a.y == b.y)
    {
        return true;
    }
    return false;
}
void Player::Update()
{
    dstRect = {x, y, width, height};
}
void Player::MoveUp()
{
    y -= speed;
    for(int i = 0; i < 3; i++)
    {
        if ( CompareRects(moveUp[i], srcRect) )
        {
            srcRect = moveUp[i+1];
            return;
        }
    }
    srcRect = moveUp[0];
}

void Player::MoveDown()
{
    y += speed;
    for(int i = 0; i < 3; i++)
    {
        if ( CompareRects(moveDown[i], srcRect) )
        {
            srcRect = moveDown[i+1];
            return;
        }
    }
    srcRect = moveDown[0];
}
void Player::MoveRight()
{
    x += speed;
    for(int i = 0; i < 3; i++)
    {
        if ( CompareRects(moveRight[i], srcRect) )
        {
            srcRect = moveRight[i+1];
            return;
        }
    }
    srcRect = moveRight[0];
}
void Player::MoveLeft()
{
    x -= speed;
    for(int i = 0; i < 3; i++)
    {
        if ( CompareRects(moveLeft[i], srcRect) )
        {
            srcRect = moveLeft[i+1];
            return;
        }
    }
    srcRect = moveLeft[0];
}
void Player::StopMotion(char dir)
{
    switch(dir)
    {
    case 'u':
        srcRect = stop[0];
        break;
    case 'd':
        srcRect = stop[1];
        break;
    case 'r':
        srcRect = stop[2];
        break;
    case 'l':
        srcRect = stop[3];
        break;
    default:
        break;
    }
}
