#ifndef _JOB_
#define _JOB_

class Job
{
private:
    char *title_cl;
    int salary_cl;
    int dailyWorkHours_cl;

public:
    Job();
    Job(char *title);
    Job(char *title, int salary);
    Job(char *title, int salary, int dailyWorkHours);
    void GoToWork();

    char *getJobTitle();
    int getJobSalary();
    int getJobDaylyWorkHours();
    void setJobSalary(int salary);
    void setJobDaylyWorkHours(int workingHrs);

    void setJobTitle(char *jobTitle);

    ~Job();
};

#endif