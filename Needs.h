#ifndef _NEEDS_
#define _NEEDS_

#include "Food.h"
#include "Animal.h"

class Person;

class Bladder
{
private:
    int level_cl = 10;

public:
    Bladder();
    void UseToilet();
    void minus1Bladder();
    int get_level();
};

class Energy
{
private:
    int level_cl = 10;

public:
    Energy();
    void Sleep();
    void minus1Energy();
    int get_level();
};

class Hunger
{
private:
    int level_cl = 10;

public:
    Hunger();
    void Eat(Food food);
    void minus1Hunger();
    int get_level();
};

class Fun
{
private:
    int level_cl = 10;

public:
    Fun();
    void PlayGuitar();
    void PlayComputer();
    void PlayAnimal(Animal animal);
    int getLevel();
    void minus1Fun();
    int get_level();
};

class Hygiene
{
private:
    int level_cl = 10;

public:
    Hygiene();
    void Shower();
    void minus1Hygiene();
    int get_level();
};

class Social
{
private:
    int level_cl = 10;

public:
    Social();
    void minus1Social();
    void Talk(Person &person);
    void Text(Person &person);
    void PhoneCall(Person &person);
    int get_level();
    void increseSocial();
};

/*
Daily living is taxing,
so reprisenting this is fuction named "life" which removes 1 (-1) from all stats(Needs).
*/
class Needs
{
private:
    Bladder bladder_cl;
    Hunger hunger_cl;
    Energy energy_cl;
    Fun fun_cl;
    Social social_cl;
    Hygiene hygiene_cl;

public:
    Needs();
    void life();
    bool CheckIfDead();
    void increaseBladder();
    void increaseHunger(Food food);
    void increaseEnergy();
    void increaseFunGuitar();
    void increaseFunComputer();
    void increaseFunAnimal(Animal animal);
    void increaseSocialTalk(Person &sim);
    void increaseSocialText(Person &sim);
    void increaseSocialPhone(Person &sim);
    void increaseSocial();
    void increaseHygiene();
    void printNeeds();
};

#endif