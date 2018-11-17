#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H
#include "Player.h"
#include "Enemies.h"
#include "GameObject.h"

class ObjectFactory
{
public:
    ObjectFactory();
    ~ObjectFactory();
    GameObject* GetObject(int);
};

#endif
