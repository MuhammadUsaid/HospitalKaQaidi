#ifndef KEY_H
#define KEY_H
#include "GameObject.h"

class Key: public GameObject
{
public:
    Key();
    ~Key
    void Render(SDL_Renderer*);
};

#endif
