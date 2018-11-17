#pragma once
#include "Node.h"
#include "GameObject.h"

class List
{
private:
    int length;
    Node* head;
    Node* tail;
public:
    List();
    List(GameObject*)
    ~List();
    void Append(GameObject*);
    void Insert(GameObject* , int);
    GameObject* Remove(int);
    void Render(SDL_Renderer*);
};
