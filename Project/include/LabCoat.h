#ifndef LABCOAT_H
#define LABCOAT_H
#include "GameObject.h"

class LabCoat: public GameObject
{
public:
    LabCoat();
    ~LabCoat());
    void Render(SDL_Renderer*);
};

#endif
