#ifndef _ANIMAL_
#define _ANIMAL
#include "Food.h"

class Animal
{
private:
    char *name_cl;
    char *kind_cl;

public:
    Animal();
    Animal(char *name);
    Animal(char *name, char *kind);
    void Eat(Food food);

    ~Animal();
};

#endif