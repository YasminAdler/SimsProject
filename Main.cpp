#include <iostream>
#include <cstring>
using namespace std;
#include "Person.h"

// class PersonArray
// {
//     Person *arry;
//     int size;

// public:
//     PersonArray(int size);
//     PersonArray(Person *arry, int size);
//     void
// };
Person *contactSim(Person *personArray, int numberOfSims, int currentSimID)
{
    int choice;
    do
    {
        cout << "Who will " << (personArray + currentSimID)->getFirstName() << " socialize with?\n";
        for (int i = 0; i < numberOfSims; i++)
        {
            if (currentSimID == i)
                continue;
            cout << i << ". "
                 << personArray[i].getFirstName()
                 << " "
                 << personArray[i].getLastName()
                 << "\n";
        }
        cin >> choice;
        if (choice < 1 || choice > numberOfSims)
            cout << "Not a valid option\n";
    } while (choice < 1 || choice > numberOfSims);
    return personArray + choice;
}
void choiceSocial(Person *personArray, int numberOfSims)
{
    int count = 0;
    int choice;
    Person *currentSim = personArray,
           *contact;
    // Needs* currentSimNeeds;
    // want to do sompthing like this
    // for (; currentSim != nullptr; currentSim++)
    // current relies on knowing number of sims in PerArr
    for (int i = 0; i < numberOfSims; i++, currentSim++)
    {
        cout << currentSim->getFirstName();
        cout << count << "\n";
        count++;
        do
        {
            cout << "1. Restroom\n"
                 << "2. Eat\n"
                 << "3. Sleep\n"
                 << "4. Fun\n"
                 << "5. Social\n"
                 << "6. Bathe\n";
            cin >> choice;
            if (choice < 1 || choice > 6)
                cout << "Not a valid option\n";
        } while (choice < 1 || choice > 6);
        switch (choice)
        {
        case fun:
            do
            {
                cout << "What kind of fun?\n"
                     << "1. PlayGuitar\n"
                     << "2. PlayComputer\n"
                     << "3. PlayAnimal\n";
                cin >> choice;
                if (choice < 1 || choice > 3)
                    cout << "Not a valid option\n";
            } while (choice < 1 || choice > 3);
            switch (choice)
            {
            case playAnimal:
                currentSim->increseNeed(fun, (void *)playAnimal);
                break;
            default:
                currentSim->increseNeed(fun, (void *)choice);
                break;
            }
            break;
        case 5:
            // option Social output
            do
            {
                cout << "what kind of socializing?\n"
                     << "1. Phone\n"
                     << "2. Face to Face\n"
                     << "3. Messege\n";
                cin >> choice;
                if (choice < 1 || choice > 3)
                    cout << "Not a valid option\n";
            } while (choice < 0 || choice > 3);
            currentSim->increseNeed(5, (void *)choice, (void *)contactSim(personArray, numberOfSims, i));
            break;
        default:
            currentSim->increseNeed(choice);
            break;
        }
    }
    return;
}
void life()
{

}

int main()
{
    cout << "\n\n--------------------  Welcome to The Sims -------------------\n\n\n";
    cout << "-------------------------- Main Manu -----------------------\n\n";
    int choice = 1;
    // for testing - added:
    // 1 constroctor Person::Person(char*,char*)
    // 2 PerArr details
    // 3 choiseSocial function call
    // Person PerArr[]{{"nam", ""},
    //                 {"dd", "uu"},
    //                 {"Dextor", "Labratory"},
    //                 {"Frank", "Sanotra"}};
    // choiceSocial(PerArr, 4);
    // till here for testin
    // when finished testing uncomment below
    Person PerArr[8];
    int numberOfSims = 0;
    int JobChoise = 0;
    char buff[20] = {'\0'};
    Job jobs[5];
    jobs[0].setJobTitle((char *)"Farmer");
    jobs[0].setJobDaylyWorkHours(12);
    jobs[0].setJobSalary(100);
    jobs[1].setJobTitle((char *)"Firewomen");
    jobs[1].setJobDaylyWorkHours(8);
    jobs[1].setJobSalary(500);
    jobs[2].setJobTitle((char *)"Painter");
    jobs[2].setJobDaylyWorkHours(3);
    jobs[2].setJobSalary(50);
    jobs[3].setJobTitle((char *)"Programmer");
    jobs[3].setJobDaylyWorkHours(12);
    jobs[3].setJobSalary(1000);
    jobs[4].setJobTitle((char *)"Dogwalker");
    jobs[4].setJobDaylyWorkHours(2);
    jobs[4].setJobSalary(300);
    Job TempJob;
    int i = 0;

    while (choice != 0)
    {

        cout << "0. Exit        1. Add a person        2.Delete a person       3.Control a person\n\n";
        cout << ">>>";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "See you next time!";
            continue;
            break;
        case 1:

            // Adding the person's first and last name:
            buff[0] = {'\0'};
            cout << "Enter the person's first name: \n";
            cin >> buff;
            PerArr[i].setFirstName(buff);
            buff[0] = {'\0'};
            cout << "Enter the person's last name: \n";
            cin >> buff;
            PerArr[i].setLastName(buff);
            buff[0] = '\0';
            strcpy(buff, PerArr[i].getFirstName());
            cout << buff << " ";
            buff[0] = '\0';
            strcpy(buff, PerArr[i].getLastName());
            cout << buff << " was added \n\n";
            i++;
            // setting that person's job:

            cout << "choose a job:\n";
            for (int j = 0; j <= 4; j++)
            {
                buff[0] = '\0';
                strcpy(buff, jobs[j].getJobTitle());
                cout << j << '.' << buff << "\n";
            }
            cin >> JobChoise;
            TempJob = jobs[JobChoise];
            PerArr[i].setJob(TempJob);
            buff[0] = '\0';

            strcpy(buff, TempJob.getJobTitle());
            cout << "Chosen: " << buff << "\n";

            i++;

            break;
        case 2:
            if (i == 0)
            {
                cout << "There are no sims";
            }
            // PerArr[i].~Person();
            

            break;
        case 3:
            // option 3 output
            choiceSocial(PerArr, numberOfSims);
            life();
        default:
            break;
        }
    }
    return 0;
}
