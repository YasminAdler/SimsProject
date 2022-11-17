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
    Job* job_cl;
    int money_cl;

public:
    Person();
    // Person(char *firstName);
    // Person(char *firstName, char *lastName);
    // Person(char *firstName, char *lastName, Needs* need);
    // Person(char *firstName, char *lastName, Needs* need, Job* job);

    void setFirstName(char *FirstName);
    void setLastName(char *LastName);
    void setJob(Job job);

    /*
    needNumber:
        1 Blader
        2 Hunger
        3 Energy
        4 Fun
        5 Social
        6 Hygiene
    secondItem:
        for hunger Food
        for fun type:
            1 PlayGuitar
            2 PlayComputer
            3 PlayAnimal thirdItem Animal
        for social - thirdItem Person:
            1 Talk
            2 Text
            3 PhoneCall
    */
    void increseNeed(int needNumber, void *secondItem = nullptr, void *thirdItem = nullptr
    
    );

    char *getFirstName();
    char *getLastName();

    // Needs *getNeeds();

    ~Person();
};

#endif