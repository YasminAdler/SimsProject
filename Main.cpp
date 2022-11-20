/*Problems:
    1 deleting a sim crashes program
    2 Writing chars instead of numbers makes it go crazy or exits depending on where it was done
    3 Attemptig to control sim crashes program



*/
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
void printSimName(Person Sim)
{
    // cout << __LINE__ << __func__ << " here\n";
    cout << Sim.getFirstName()
         << " "
         << Sim.getLastName();
}
Person *contactSim(Person *personArray, int numberOfSims, int currentSimNum)
{
    int choice;
    do
    {
        cout << "Who will " << *(personArray + currentSimNum)->getFirstName() << " socialize with?\n";
        for (int i = 0; i < numberOfSims; i++)
        {
            if (currentSimNum == i)
                continue;
            cout << i << ". ";
            printSimName(*(personArray + i));
            cout << "\n";
        }
        cin >> choice;
        if (currentSimNum == choice || choice < 1 || choice > numberOfSims)
            cout << "Not a valid option\n";
    } while (choice < 1 || choice > numberOfSims);
    return personArray + choice;
}
void choiceSimFunctions(Person *personArray, int numberOfSims)
{
    int count = 0;
    long long choice;
    // Person *contact;
    // Needs* currentSimNeeds;
    // want to do sompthing like this
    // for (; currentSim != nullptr; currentSim++)
    // current relies on knowing number of sims in PerArr
    for (int i = 0; i < numberOfSims; i++)
    {
        cout << "whta would you like ";
        printSimName(*(personArray + i));
        cout << " to do?" << endl;
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
        case bladder:
            (personArray + i)->increaseBladder();
            break;
        case hunger:
            (personArray + i)->increaseHunger(nullptr);
            break;
        case energy:
            (personArray + i)->increaseEnergy();
            break;
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
            case playGuitar:
                (personArray + i)->increaseFunGuitar();
                break;
            case playComputer:
                (personArray + i)->increaseFunComputer();
                break;
            case playAnimal:
                (personArray + i)->increaseFunAnimal(nullptr);
                break;
            default:
                cout << "you shouldn't get this messege line: " << __LINE__ << endl;
                break;
            }
            break;
        case social:
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
            } while (choice < 1 || choice > 3);
            switch (choice)
            {
            case talk:
                (personArray + i)->increaseSocialTalk(*contactSim(personArray, numberOfSims, i));
                break;
            case text:
                (personArray + i)->increaseSocialText(*contactSim(personArray, numberOfSims, i));
                break;
            case phoneCall:
                (personArray + i)->increaseSocialTalk(*contactSim(personArray, numberOfSims, i));
                break;
            default:
                cout << "you shouldn't get this messege line: " << __LINE__ << endl;
                break;
            }
        default:
            cout << "you shouldn't get this messege line: " << __LINE__ << endl;
            break;
        }
    }
    return;
}
void life(Person *simArray, int simArraySize)
{
    // change to pointers, cant figure out refrences
    for (int i = 0; i < simArraySize; i++)
    {
        cout << __LINE__ << __func__ << " here\n";
        (*(simArray + i)).life();

        if ((*(simArray + i)).CheckIfDead())
        {
            printSimName(*(simArray + i));
            cout << " is dead!\n";
        }
        else
        {
            // cout << __LINE__ << __func__ << " here\n";
            printSimName((*(simArray + i)));
            cout << "\n";
            // cout << __LINE__ << __func__ << " here\n";

            (*(simArray + i)).printNeeds();
            // cout << __LINE__ << __func__ << " here\n";
        }
    }
    // cout << __LINE__ << __func__ << "  here\n";
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
    // Person PerArr[]{{(char *)"nam", (char *)"n"},
    //                 {(char *)"dd", (char *)"uu"},
    //                 {(char *)"Dextor", (char *)"Labratory"},
    //                 {(char *)"Frank", (char *)"Sanotra"}};
    // for (int i = 0; i < 10; i++)
    // {
    //     life(PerArr, 4);
    //     // cout << __LINE__ << __func__ << " line here\n";
    // }
    // return 0;

    // choiceSimFunctions(PerArr, 4);
    // till here for testin
    // when finished testing uncomment below
    Person PerArr[8];
    // till here
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

        cout << "0. Exit        1. Add a sim        2.Delete a sim       3.Control a sim\n\n";
        cout << ">>>";
        cin >> choice;
        if (choice < 0 || choice > 3)
        {
            cout << "Not a valid chioce\n";
            continue;
        }
        switch (choice)
        {
        case 0:
            cout << "See you next time!";
            continue;
            break;
        case 1:

            // Adding the sim's first and last name:
            buff[0] = {'\0'};
            cout << "Enter the sim's first name: \n";
            cin >> buff;
            PerArr[simCounter].setFirstName(buff);
            buff[0] = {'\0'};
            cout << "Enter the sim's last name: \n";
            cin >> buff;
            PerArr[simCounter].setLastName(buff);
            buff[0] = '\0';
            strcpy(buff, PerArr[simCounter].getFirstName());
            cout << buff << " ";
            buff[0] = '\0';
            strcpy(buff, PerArr[simCounter].getLastName());
            cout << buff << " was added \n\n";

            // simCounter++ was here but it encreases the counter by 2 for every new sim so I deleted it

            // setting that sim's job:
            do
            {
                cout << "choose a job:\n";
                for (int j = 0; j <= 4; j++)
                {
                    buff[0] = '\0';
                    strcpy(buff, jobs[j].getJobTitle());
                    cout << j << '.' << buff << "\n";
                }
                cin >> JobChoise;
                if (JobChoise < 0 || JobChoise > 4)
                    cout << "Not a valid option\n";
            } while (JobChoise < 0 || JobChoise > 4);
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
            choiceSimFunctions(PerArr, simCounter);
            life(PerArr, simCounter);
        default:
            cout << "you shouldn't get this messege line: " << __LINE__ << endl;
            break;
        }
    }
    return 0;
}
