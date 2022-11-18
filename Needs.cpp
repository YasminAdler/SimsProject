#include <iostream>
using namespace std;
#include "Needs.h"
#include "Person.h"
// class Person;

Needs::Needs()
{
}

bool Needs::CheckIfDead()
{
    if (bladder_cl.get_level() == 0 && hygiene_cl.get_level() == 0 && hunger_cl.get_level() == 0 && energy_cl.get_level() == 0 && fun_cl.get_level() == 0 && social_cl.get_level() == 0)
        return true;
    else
        return false;
}

void Needs::life()
{
    bladder_cl.minus1Bladder();
    hunger_cl.minus1Hunger();
    energy_cl.minus1Energy();
    fun_cl.minus1Fun();
    social_cl.minus1Social();
    hygiene_cl.minus1Hygiene();
}

void Needs::increseNeed(int needNumber, void *secondItem, void *thirdItem)
{

    switch (needNumber)
    {
    case 1:
        bladder_cl.UseToilet();
        break;
    case 2:
        hunger_cl.Eat(*(Food *)secondItem);
        break;
    case 3:
        energy_cl.Sleep();
        break;
    case 4:
        switch ((long long)secondItem)
        {
        case 1:
            fun_cl.PlayAnimal(*(Animal *)thirdItem);
            break;
        case 2:
            fun_cl.PlayComputer();
            break;
        case 3:
            fun_cl.PlayGuitar();
            break;
        }
        break;
    case 5:
        switch ((long long)secondItem)
        {
        case 1:
            social_cl.PhoneCall(*(Person *)thirdItem);
            break;
        case 2:
            social_cl.Talk(*(Person *)thirdItem);
            break;
        case 3:
            social_cl.Text(*(Person *)thirdItem);
            break;
        }
    case 6:
        hygiene_cl.Shower();
        break;
    }
}
void Needs::printNeeds()
{
    cout << "Blader\t" << bladder_cl.get_level() << "\n"
         << "Hunger\t" << hunger_cl.get_level() << "\n"
         << "Energy\t" << energy_cl.get_level() << "\n"
         << "Fun\t" << fun_cl.get_level() << "\n"
         << "Social" << social_cl.get_level() << "\n"
         << "Hygiene\t" << hygiene_cl.get_level() << "\n";
}
Bladder::Bladder()
{
}
void Bladder::UseToilet()
{
    level_cl += 5;
    if (level_cl >= 10)
    {
        level_cl = 10;
    }
}
int Bladder::get_level()
{
    return level_cl;
}

void Bladder::minus1Bladder()
{
    if (level_cl > 0)
        level_cl--;
    if (level_cl <= 3)
    {
        cout << "Really need to use the toilet :( \n";
    }
}

Energy::Energy()
{
}

int Energy::get_level()
{
    return level_cl;
}
void Energy::Sleep()
{
    level_cl += 5;
    if (level_cl >= 10)
    {
        level_cl = 10;
    }
}
void Energy::minus1Energy()
{
    if (level_cl > 0)
        level_cl--;
    if (level_cl <= 3)
    {
        cout << "Really need to sleep :( \n";
    }
}

Fun::Fun()
{
}
int Fun::get_level()
{
    return level_cl;
}
void Fun::PlayGuitar()
{
    level_cl += 5;
    if (level_cl >= 10)
    {
        level_cl = 10;
    }
}
void Fun::PlayComputer()
{
    level_cl += 5;
    if (level_cl >= 10)
    {
        level_cl = 10;
    }
}
void Fun::PlayAnimal(Animal animal)
{
    level_cl += 5;
    if (level_cl >= 10)
    {
        level_cl = 10;
    }
}
void Fun::minus1Fun()
{
    if (level_cl > 0)
        level_cl--;
    if (level_cl <= 3)
    {
        cout << "Really need to do something fun :( \n";
    }
}

Hunger::Hunger()
{
}
int Hunger::get_level()
{
    return level_cl;
}
void Hunger::Eat(Food food)
{
    level_cl += 5;
    if (level_cl >= 10)
    {
        level_cl = 10;
    }
}
void Hunger::minus1Hunger()
{
    if (level_cl > 0)
        level_cl--;
    if (level_cl <= 3)
    {
        cout << "Really need to eat :( \n";
    }
}

Hygiene::Hygiene()
{
}
int Hygiene::get_level()
{
    return level_cl;
}
void Hygiene::Shower()
{
    level_cl += 5;
    if (level_cl >= 10)
    {
        level_cl = 10;
    }
}
void Hygiene::minus1Hygiene()
{
    if (level_cl > 0)
        level_cl--;
    if (level_cl <= 3)
        cout << "Really need to do something fun :( \n";
}

Social::Social()
{
}
int Social::get_level()
{
    return level_cl;
}
void Social::minus1Social()
{
    if (level_cl > 0)
        level_cl--;
    if (level_cl <= 3)
        cout << "Really need to do something social :( \n";
}
void Social::Talk(Person person)
{
    cout << "Talking to "
         << person.getFirstName()
         << " "
         << person.getLastName()
         << "\n";
    increseSocial();
    person.increseNeed(5);
}
void Social::Text(Person person)
{
    cout << "Texting "
         << person.getFirstName()
         << " "
         << person.getLastName()
         << "\n";
    increseSocial();
    person.increseNeed(5);
}
void Social::PhoneCall(Person person)
{
    cout << "Calling "
         << person.getFirstName()
         << " "
         << person.getLastName()
         << "\n";
    increseSocial();
    person.increseNeed(5);
}
void Social::increseSocial()
{
    level_cl += 5;
    if (level_cl >= 10)
        level_cl = 10;
}

