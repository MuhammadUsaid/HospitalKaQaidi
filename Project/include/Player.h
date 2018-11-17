#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"
#include "BaseCharacter.h"

class Player: public BaseCharacter
{
private:
    GameObject* inventory;
    Player instance;
public:
    Player();
    ~Player();
    Player* GetInstance();
    void Die();
    void WearLabcoat();
    void AddInventory(GameObject);
    void CloseDoor();
    void PickUpChair();
    void ThrowChair();
    bool CheckFurniture();
    void Hide(GameObject&);
    void DisplayInventory();
    void RemoveFromInventory():
};

#endif // PLAYER_H
