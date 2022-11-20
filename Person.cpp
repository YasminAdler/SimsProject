#include <iostream>
using namespace std;
#include "Person.h"
#include <cstring>

Person::Person()
{
}

// Person::Person(char *firstName)
// {
//     firstName_cl = new char(strlen(firstName) + 1);
//     strcpy(firstName_cl, firstName);
// }

// Person::Person(char *firstName, char *lastName)
// {
//     firstName_cl = new char(strlen(firstName) + 1);
//     strcpy(firstName_cl, firstName);
//     lastName_cl = new char(strlen(lastName) + 1);
//     strcpy(lastName_cl, lastName);
// }

// Person::Person(char *firstName, char *lastName, Needs* need)
// {
//     firstName_cl = new char(strlen(firstName) + 1);
//     strcpy(firstName_cl, firstName);

//     lastName_cl = new char(strlen(lastName) + 1);
//     strcpy(lastName_cl, lastName);
//     needs_cl = need;
// }

// Person::Person(char *firstName, char *lastName, Needs* need, Job* job) {
//         firstName_cl = new char(strlen(firstName) + 1);
//     strcpy(firstName_cl, firstName);

//     lastName_cl = new char(strlen(lastName) + 1);
//     strcpy(lastName_cl, lastName);
//     needs_cl = need;
//     job_cl = job;
// }

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
void Person::increaseSocialTalk(Person sim)
{
    needs_cl.increaseSocialTalk(sim);
}
void Person::increaseSocialText(Person sim)
{
    needs_cl.increaseSocialText(sim);
}
void Person::increaseSocialPhone(Person sim)
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
/*
Depritiated
void Person::increseNeed(int needNumber, void *secondItem, void *thirdItem)
{
    needs_cl.increseNeed(needNumber, secondItem, thirdItem);
}
*/
// Needs *Person::getNeeds()
// {
//    return &needs_cl;
//

void Person::setJob(Job job)
{
    // job_cl = new Job[sizeof(job)];
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

// Person::Person(const Person &t)
// {
//     firstName_cl = new char[sizeof(t.firstName_cl) + 1];
//     strcpy(firstName_cl, t.firstName_cl);

//     lastName_cl = new char[sizeof(t.lastName_cl) + 1];
//     strcpy(lastName_cl, t.lastName_cl);
//     cout << "Copy Constructor\n";

//     //didn't add the job copy constructor yet!!
// }

Person::~Person()
{
    delete[] firstName_cl;
    delete[] lastName_cl;
    // delete[] job_cl;
    
}
