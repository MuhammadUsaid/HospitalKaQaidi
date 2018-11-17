#ifndef WEAPON_H
#define WEAPON_H
#include "Player.h"
#include "Enemies.h"

class Weapon: public GameObject
{
private:
    int power:
    int range:
public:
    Weapon();
    ~Weapon();
    void Render(SDL_Renderer*);
};

#endif
