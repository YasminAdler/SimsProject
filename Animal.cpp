#include <iostream>
#include <cstring>
using namespace std;
#include "Animal.h"

Animal::Animal()
{
}
Animal::Animal(char *name)
{
    name_cl = new char[strlen(name) + 1];
    strcpy(name_cl, name);
}
Animal::Animal(char *name, char *kind)
{
    name_cl = new char[strlen(name) + 1];
    kind_cl = new char[strlen(kind) + 1];
    strcpy(name_cl, name);
    strcpy(kind_cl, kind);
}
void Eat(Food food)
{
}

Animal::~Animal()
{
    delete[] name_cl;
    delete[] kind_cl;
}
