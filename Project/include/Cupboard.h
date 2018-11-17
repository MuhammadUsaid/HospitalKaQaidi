#ifndef CUPBOARD_H
#define CUPBOARD_H
#include "Door.h"

class Cupboard: public Door
{
public:
    Cupboard;
    ~Cupboard();
    void Open();
    void Close();
};

#endif
