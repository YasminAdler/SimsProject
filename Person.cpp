#include <iostream>
using namespace std;
#include "Person.h"
#include <cstring>

Person::Person()
{
}
void Person::setFirstName(char *FirstName)
{
    firstName_cl = new char[strlen(FirstName)] + 1;
    strcpy(firstName_cl, FirstName);
}
void Person::setLastName(char *LastName)
{
    lastName_cl = new char[strlen(LastName) + 1];

    strcpy(lastName_cl, LastName);
}
void Person::increaseBladder()
{
    needs_cl.increaseBladder();
}
void Person::increaseHunger(Food food)
{
    needs_cl.increaseHunger(food);
}
void Person::increaseEnergy()
{
    needs_cl.increaseEnergy();
}
void Person::increaseFunGuitar()
{
    needs_cl.increaseFunGuitar();
}
void Person::increaseFunComputer()
{
    needs_cl.increaseFunComputer();
}
void Person::increaseFunAnimal(Animal animal)
{
    needs_cl.increaseFunAnimal(animal);
}
void Person::increaseSocialTalk(Person &sim)
{
    needs_cl.increaseSocialTalk(sim);
}
void Person::increaseSocialText(Person &sim)
{
    needs_cl.increaseSocialText(sim);
}
void Person::increaseSocialPhone(Person &sim)
{
    needs_cl.increaseSocialPhone(sim);
}
void Person::increaseSocial()
{
    needs_cl.increaseSocial();
}
void Person::increaseHygiene()
{
    needs_cl.increaseHygiene();
}

char *Person::getFirstName()
{
    return firstName_cl;
}
char *Person::getLastName()
{
    return lastName_cl;
}
void Person::setJob(Job job)
{
    job_cl = &job;
    job_cl->setJobTitle(job.getJobTitle());
}
void Person::life()
{
    needs_cl.life();
}
bool Person::CheckIfDead()
{
    return needs_cl.CheckIfDead();
}
void Person::printNeeds()
{
    needs_cl.printNeeds();
}

Person::~Person()
{
    delete firstName_cl;
    delete lastName_cl;
}
