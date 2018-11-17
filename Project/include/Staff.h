#ifndef STAFF_H
#define STAFF_H
#include "Player.h"
#include "Enemies.h"
#include "PlayerChaser.h"
#include "Key.h"

class Staff: public PlayerChaser
{
private:
    Key* key;
public:
    Staff();
    ~Staff();
    void RingAlarm(): void;
};

#endif
