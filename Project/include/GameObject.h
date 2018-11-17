#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Player.h"
#include "Enemies.h"
#include <SDL.h>

class GameObject
{
protected:
    Point position;
    SDL_Texture* sprite;
    int width;
    int height;
public:
    GameObject();
    ~GameObject();
    virtual void Render(SDL_Renderer*);
    bool CollisionDetection();
    void Move(char); //user input
};

#endif
