#ifndef BASECHARACTER_H
#define BASECHARACTER_H
#include "Weapon.h"
#include "Point.h"
#include "GameObject.h"

class BaseCharacter: public GameObject
{
private:
    int speed;
    int vision;
    int health;
    bool alive;
    Weapon* weapons;
public:
    BaseCharacter();
    ~BaseCharacter();
    Point GetPosition();
    void Speak();
    void Throw();
    void Blink();
    void LoseHealth();
    void Fall();
    void Die();
};



#endif // BASECHARACTER_H
