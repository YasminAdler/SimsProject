#include <iostream>
using namespace std;
#include "Needs.h"
#include "Person.h"
// class Person;

Needs::Needs() : bladder_cl{},
                 hunger_cl{},
                 energy_cl{},
                 fun_cl{},
                 social_cl{},
                 hygiene_cl{}
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

void Needs::increaseBladder()
{
    bladder_cl.UseToilet();
}
void Needs::increaseHunger(Food food)
{
    hunger_cl.Eat(food);
}
void Needs::increaseEnergy()
{
    energy_cl.Sleep();
}
void Needs::increaseFunGuitar()
{
    fun_cl.PlayGuitar();
}
void Needs::increaseFunComputer()
{
    fun_cl.PlayComputer();
}
void Needs::increaseFunAnimal(Animal animal)
{
    fun_cl.PlayAnimal(animal);
}
void Needs::increaseSocialTalk(Person &sim)
{
    social_cl.Talk(sim);
}
void Needs::increaseSocialText(Person &sim)
{
    social_cl.Text(sim);
}
void Needs::increaseSocialPhone(Person &sim)
{
    social_cl.PhoneCall(sim);
}
void Needs::increaseSocial()
{
    social_cl.increseSocial();
}
void Needs::increaseHygiene()
{
    hygiene_cl.Shower();
}

void Needs::printNeeds()
{
    cout << "Blader\t" << bladder_cl.get_level() << "\n"
         << "Hunger\t" << hunger_cl.get_level() << "\n"
         << "Energy\t" << energy_cl.get_level() << "\n"
         << "Fun\t" << fun_cl.get_level() << "\n"
         << "Social\t" << social_cl.get_level() << "\n"
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
        cout << "Really need to shower :( \n";
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
        cout << "Really need to socialize :( \n";
}
void Social::Talk(Person& person)
{
    cout << "Talking to "
         << person.getFirstName()
         << " "
         << person.getLastName()
         << "\n";
    increseSocial();
    person.increaseSocial();
}
void Social::Text(Person& person)
{
    cout << "Texting "
         << person.getFirstName()
         << " "
         << person.getLastName()
         << "\n";
    increseSocial();
    person.increaseSocial();
}
void Social::PhoneCall(Person &person)
{
    cout << "Calling "
         << person.getFirstName()
         << " "
         << person.getLastName()
         << "\n";
    increseSocial();
    person.increaseSocial();
}
void Social::increseSocial()
{
    level_cl += 5;
    if (level_cl >= 10)
        level_cl = 10;
}
