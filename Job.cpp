#include <iostream>
using namespace std;
#include "Job.h"
#include "Person.h"
#include <cstring>

Job::Job()
{
}
Job::Job(char *title)
{
    title_cl = new char[strlen(title) + 1];
    strcpy(title_cl, title);
}
Job::Job(char *title, int salary)
{
    title_cl = new char[strlen(title) + 1];
    strcpy(title_cl, title);
    salary_cl = salary;
}
Job::Job(char *title, int salary, int dailyWorkHours)
{
    title_cl = new char[strlen(title) + 1];
    strcpy(title_cl, title);
    salary_cl = salary;
    dailyWorkHours_cl = dailyWorkHours;
}

void Job::GoToWork()
{
    dailyWorkHours_cl += 7;
}

char *Job::getJobTitle()
{
    return title_cl;
}
void Job::setJobTitle(char *jobTitle)
{
    title_cl = new char[strlen(jobTitle) + 1];
    strcpy(title_cl, jobTitle);
}

int Job::getJobSalary()
{
    return salary_cl;
}
int Job::getJobDaylyWorkHours()
{
    return salary_cl;
}

void Job::setJobSalary(int salary)
{
    salary_cl = salary;
}
void Job::setJobDaylyWorkHours(int workingHrs)
{
    dailyWorkHours_cl = workingHrs;
}

Job::~Job()
{
    delete[] title_cl;
}