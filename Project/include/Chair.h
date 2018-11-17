#ifndef CHAIR_H
#define CHAIR_H
#include "GameObject.h"

class Chair: public GameObject
{
public:
    Chair();
    ~Chair();
    void Render(SDL_Renderer*);
};

#endif
