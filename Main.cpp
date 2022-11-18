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
void printSim(Person Sim)
{
    static int i = 0;
    cout << Sim.getFirstName()
         << " "
         << Sim.getLastName();
    cout << i;
    i++;
}
Person *contactSim(Person *personArray, int numberOfSims, int currentSimNum)
{
    int choice;
    Person &currentSim = *personArray;
    do
    {
        cout << "Who will " << currentSim.getFirstName() << " socialize with?\n";
        for (int i = 0; i < numberOfSims; i++)
        {
            currentSim = *(personArray + currentSimNum);
            if (currentSimNum == i)
                continue;
            cout << i << ". ";
            printSim(currentSim);
            cout << "\n";
        }
        cin >> choice;
        if (currentSimNum == choice || choice < 1 || choice > numberOfSims)
            cout << "Not a valid option\n";
    } while (choice < 1 || choice > numberOfSims);
    return personArray + choice;
}
void choiceSocial(Person *personArray, int numberOfSims)
{
    int count = 0;
    long long choice;
    Person &currentSim = *personArray,
           *contact;
    // Needs* currentSimNeeds;
    // want to do sompthing like this
    // for (; currentSim != nullptr; currentSim++)
    // current relies on knowing number of sims in PerArr
    for (int i = 0; i < numberOfSims; i++)
    {
        currentSim = *(personArray + i);
        cout << currentSim.getFirstName();
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
                currentSim.increseNeed(fun, (void *)playAnimal);
                break;
            default:
                currentSim.increseNeed(fun, (void *)choice);
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
            currentSim.increseNeed(5, (void *)choice, (void *)contactSim(personArray, numberOfSims, i));
            break;
        default:
            currentSim.increseNeed(choice);
            break;
        }
    }
    return;
}
void life(Person *simArray, int simArraySize)
{
    Person t{};
    Person &currentSim{t};
    for (int i = 0; i < simArraySize; i++)
    {
        currentSim = *(simArray + i);
        currentSim.life();

        if (currentSim.CheckIfDead())
        {
            printSim(currentSim);
            cout << " is dead!\n";
        }
        else
        {
            printSim(currentSim);
            cout << "\n";
            currentSim.printNeeds();
        }
    }
    cout << __LINE__ << "here\n";
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

    // Person PerArr[]{{"nam", "n"},
    //                 {"dd", "uu"},
    //                 {"Dextor", "Labratory"},
    //                 {"Frank", "Sanotra"}};
    // for (int i = 0; i < 10; i++)
    // {
    //     life(PerArr, 4);
    //     cout<<__LINE__<<"here\n";
    // }
    // return 0;

    // choiceSocial(PerArr, 4);
    // till here for testin
    // when finished testing uncomment below
    Person PerArr[8];
    // till here
    int numberOfSims = 0;
    int JobChoise = 0;
    char buff[20] = {'\0'};
    Job jobs[5];
    int delSIm = 0;
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
    int simCounter = 0;

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
            PerArr[simCounter].setFirstName(buff);
            buff[0] = {'\0'};
            cout << "Enter the person's last name: \n";
            cin >> buff;
            PerArr[simCounter].setLastName(buff);
            buff[0] = '\0';
            strcpy(buff, PerArr[simCounter].getFirstName());
            cout << buff << " ";
            buff[0] = '\0';
            strcpy(buff, PerArr[simCounter].getLastName());
            cout << buff << " was added \n\n";

            // simCounter++ was here but it encreases the counter by 2 for every new sim so I deleted it

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
            PerArr[simCounter].setJob(TempJob);
            buff[0] = '\0';

            strcpy(buff, TempJob.getJobTitle());
            cout << "Chosen: " << buff << "\n";

            simCounter++;

            break;
        case 2:
            //----------------//Deleting a sim: -----------------

            // option 1: there are no sims
            if (simCounter == 0)
            {
                cout << "There are no sims yet\n";
                break;
            }
            // option 2: the wanted sim is the last in the array
            cout << "Which sim would you like to delete?\n";
            for (int c = 0; c < simCounter; c++)
            {
                buff[0] = '\0';
                strcpy(buff, PerArr[c].getFirstName());
                cout << c + 1 << "." << buff;
                buff[0] = '\0';
                strcpy(buff, PerArr[c].getLastName());
                cout << " " << buff << "\n";
            }
            cin >> delSIm;
            // cout << "Sim counter:" << simCounter<< "\n";
            if (delSIm == simCounter)
            {
                PerArr[simCounter].~Person();
                simCounter--;
                break;
            }

            // option 3: the sim is not the last one in the array
            for (int c = delSIm - 1; c <= simCounter - 1; c++)
            {
                PerArr[c] = PerArr[c + 1];
            }
            PerArr[simCounter - 1].~Person();
            simCounter--;
            break;

        case 3:
            // option 3 output
            choiceSocial(PerArr, numberOfSims);
            life(PerArr, simCounter);
        default:
            break;
        }
    }
    return 0;
}
