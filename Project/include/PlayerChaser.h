#ifndef PLAYERCHASER_H
#define PLAYERCHASER_H
#include "Player.h"
#include "Enemies.h"

class PlayerChaser: public Enemies
{
public:
    PlayerChaser();
    ~PlayerChaser();
    bool ChasePlayer(Player&);
};

#endif
