#ifndef GUARD_H
#define GUARD_H
#include "Player.h"
#include "Enemies.h"
#include "PlayerChaser.h"
#include "Door.h"

class Guard: public PlayerChaser
{
public:
    Guard();
    ~Guard();
    void BreakDoor(Door&);
    void Hit(Player&);
};

#endif
