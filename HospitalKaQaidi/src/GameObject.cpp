#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject()
{

}
GameObject::GameObject(const char* path, int x, int y, int width, int height)
{
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
    currentTexture = TextureManager::LoadTexture(path);
    srcRect = {0, 0, 50, 50};
}
void GameObject::Update()
{
    x++;
    dstRect = {x, y, width, height};
}
void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, currentTexture, &srcRect, &dstRect);
}
