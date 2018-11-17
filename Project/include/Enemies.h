#ifndef ENEMIES_H
#define ENEMIES_H
#include "Player.h"
#include "BaseCharacter.h"

class Enemies: public BaseCharacter
{
private:
    int range;
    Player* player;
public:
    Enemies();
    ~Enemies();
    bool DetectPlayer(Player&);
};



#endif
