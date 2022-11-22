#ifndef _PERSON_
#define _PERSON_
#include "Needs.h"
#include "Job.h"

class Person
{
private:
    int ID;
    char *firstName_cl;
    char *lastName_cl;
    Needs needs_cl;
    Job *job_cl;
    int money_cl;

public:
    Person();
    void setFirstName(char *FirstName);
    void setLastName(char *LastName);
    void setJob(Job job);

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

    char *getFirstName();
    char *getLastName();

    void life();
    bool CheckIfDead();
    void printNeeds();

    ~Person();
};

#endif
