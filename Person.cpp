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

char *Person::getFirstName()
{
    return firstName_cl;
}
char *Person::getLastName()
{
    return lastName_cl;
}
void Person::increseNeed(int needNumber, void *secondItem, void *thirdItem)
{
    needs_cl.increseNeed(needNumber, secondItem, thirdItem);
}
// Needs *Person::getNeeds()
// {
//    return &needs_cl;
// 
void Person::setJob(Job job)
{
    job_cl = new Job[sizeof(job)];
    job_cl = &job;
    job_cl->setJobTitle(job.getJobTitle());
}
Person::~Person()
{
    // delete needs_cl;
    delete[] firstName_cl;
    delete[] lastName_cl;
}