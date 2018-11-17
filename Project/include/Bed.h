#ifndef BED_H
#define BED_H
#include "GameObject.h"

class Bed: public GameObject
{
private:
    bool isEmpty;
public:
    Bed();
    ~Bed();
    void Render(SDL_Renderer*);
};

#endif
