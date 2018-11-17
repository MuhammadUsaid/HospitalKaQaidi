#ifndef DOOR_H
#define DOOR_H
#include "GameObject.h"

class Door: public GameObject
{
private:
    bool lock();
    bool close();
    Key* key;
public:
    Door();
    ~Door();
    bool isLocked();
    void Render(SDL_Renderer*);
};

#endif
