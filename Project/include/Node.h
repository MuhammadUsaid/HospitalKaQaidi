#pragma once
#include "GameObject.h"

struct Node
{
    GameObject* value;
    Node* next;
    Node* prev;
public:
    Node();
    ~Node();
};
