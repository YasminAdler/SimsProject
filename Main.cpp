/*Problems:
    12 want to change to referance wherever possible

*/
#include <iostream>
#include <cstring>
using namespace std;
#include "Person.h"

enum choices
{
    exitGame,
    addSim,
    deleteSim,
    controlSim
};
enum social
{
    talk = 1,
    text,
    phoneCall
};
enum needNumber
{
    bladder = 1,
    hunger,
    energy,
    fun,
    social,
    hygiene
};
enum fun
{
    playGuitar = 1,
    playComputer,
    playAnimal
};

// Prints sim name
void printSimName(Person &Sim)
{
    cout << Sim.getFirstName()
         << " "
         << Sim.getLastName();
}
// Gives chocies of whom a sim can contact and returns requested sim
Person *contactSim(Person *personArray, int numberOfSims, int currentSimNum)
{
    char choice;
    do
    {
        cout << "Who will ";
        printSimName(personArray[currentSimNum]);
        cout << " socialize with?\n";
        for (int i = 0; i < numberOfSims; i++)
        {
            if (currentSimNum == i)
                continue;
            cout << i << ". ";
            printSimName(*(personArray + i));
            cout << "\n";
        }
        cin >> choice;
        choice -= 48;
        if (currentSimNum == choice || choice < 0 || choice > numberOfSims)
            cout << "Not a valid option\n";
    } while (choice < 0 || choice > numberOfSims);
    return personArray + choice;
}
// Gives Fun options
void optionFun(Person &sim)
{
    char choice;
    Animal a;
    do
    {
        cout << "What kind of fun?\n"
             << "1. PlayGuitar\n"
             << "2. PlayComputer\n"
             << "3. PlayAnimal\n";
        cin >> choice;
        choice -= 48;
        if (choice < 1 || choice > 3)
            cout << "Not a valid option\n";
    } while (choice < 1 || choice > 3);
    switch (choice)
    {
    case playGuitar:
        sim.increaseFunGuitar();
        break;
    case playComputer:
        sim.increaseFunComputer();
        break;
    case playAnimal:
        sim.increaseFunAnimal(a);
        break;
    default:
        cout << "error you shouldn't get this messege line: " << __LINE__ << __func__ << endl;
        break;
    }
}
// Gives Social options
void optionSocial(Person *simArray, Person &currentSim, int currentSimNum, int numberOfSims)
{
    char choice;
    do
    {
        cout << "what kind of socializing?\n"
             << "1. Face to Face\n"
             << "2. Messege\n"
             << "3. Phone\n";
        cin >> choice;
        choice -= 48;
        if (choice < 1 || choice > 3)
            cout << "Not a valid option\n";
    } while (choice < 1 || choice > 3);
    switch (choice)
    {
    case talk:
        currentSim.increaseSocialTalk(*contactSim(simArray, numberOfSims, currentSimNum));
        break;
    case text:
        currentSim.increaseSocialText(*contactSim(simArray, numberOfSims, currentSimNum));
        break;
    case phoneCall:
        currentSim.increaseSocialPhone(*contactSim(simArray, numberOfSims, currentSimNum));
        break;
    default:
        cout << "error you shouldn't get this messege line: " << __LINE__ << __func__ << endl;
        break;
    }
}
// Gives sim functions and operates according to input
void choiceSimFunctions(Person *personArray, int numberOfSims)
{
    int count = 0;
    char choice;
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
            choice -= 48;
            if (choice < 1 || choice > 6)
                cout << "Not a valid option\n";
        } while (choice < 1 || choice > 6);
        switch (choice)
        {
        case bladder:
            (personArray + i)->increaseBladder();
            break;
        case hunger:
            (personArray + i)->increaseHunger(NULL);
            break;
        case energy:
            (personArray + i)->increaseEnergy();
            break;
        case fun:
            optionFun(*(personArray + i));
            break;
        case social:
            if (numberOfSims == 1)
            {
                cout << "Its lonely here. ";
                printSimName(personArray[i]);
                cout << " has no one to socialize with :(\n";
                break;
            }
            optionSocial(personArray, personArray[i], i, numberOfSims);
            break;
        case hygiene:
            (personArray + i)->increaseHygiene();
            break;
        default:
            cout << "error you shouldn't get this messege line: " << __LINE__ << __func__ << endl;
            break;
        }
    }
    return;
}
/*
Daily living is taxing,
so reprisenting this is fuction named "life" which removes 1 (-1) from all of the sims stats(Needs).
*/
void life(Person *simArray, int simArraySize)
{
    for (int i = 0; i < simArraySize; i++)
    {
        (*(simArray + i)).life();
        if ((*(simArray + i)).CheckIfDead())
        {
            cout << "\n";
            printSimName(*(simArray + i));
            cout << " is dead!\n";
        }
        else
        {
            printSimName((*(simArray + i)));
            cout << " stats:\n";
            (*(simArray + i)).printNeeds();
        }
    }
}

int main()
{
    cout << "\n\n--------------------  Welcome to The Sims -------------------\n\n\n";
    cout << "-------------------------- Main Manu -----------------------\n\n";
    char choice = 1;
    Person PerArr[8];
    char JobChoise;
    char buff[20] = {'\0'};
    Job jobs[5];
    char delSIm;
    int inJobChoice;
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
        choice -= 48;
        if (!(choice == 0 || choice == 1 || choice == 2 || choice == 3))
        {
            cout << "Not a valid chioce\n";
            continue;
        }
        switch (choice)
        {
        case exitGame:
            cout << "See you next time!";
            continue;
            break;
        case addSim:

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

            // setting that sim's job:
            do
            {
                JobChoise = 0;
                cout << "choose a job:\n";
                for (int j = 0; j <= 4; j++)
                {
                    buff[0] = '\0';
                    strcpy(buff, jobs[j].getJobTitle());
                    cout << j << '.' << buff << "\n";
                }
                cin >> JobChoise;
                if (JobChoise < '0' || JobChoise > '4')
                    cout << "Not a valid option\n";
            } while ((JobChoise != '0') && JobChoise != '1' && JobChoise != '2' && JobChoise != '3' && JobChoise != '4');
            inJobChoice = JobChoise - 48;
            TempJob = jobs[inJobChoice];
            PerArr[simCounter].setJob(TempJob);
            buff[0] = '\0';

            strcpy(buff, TempJob.getJobTitle());
            cout << "Chosen: " << buff << "\n";

            simCounter++;

            break;
        case deleteSim:
            //----------------//Deleting a sim: -----------------
            // option 1: there are no sims
            if (simCounter == 0)
            {
                cout << "There are no sims yet\n";
                break;
            }
            // option 2: the wanted sim is the last in the array
            do
            {
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
                delSIm -= 48;
                if (delSIm < 0 || delSIm > simCounter)
                    cout << "Not a valid option\n";
            } while (delSIm < 0 || delSIm > simCounter);
            // cout << "Sim counter:" << simCounter<< "\n";
            if (delSIm == simCounter)
            {
                // PerArr[simCounter].~Person();
                simCounter--;
                break;
            }

            // option 3: the sim is not the last one in the array
            for (int c = delSIm - 1; c <= simCounter - 1; c++)
            {
                PerArr[c] = PerArr[c + 1];
            }
            // PerArr[simCounter - 1].~Person();
            simCounter--;
            break;
        case controlSim:
            // option 3 output
            /*If there are no sims dont do anything*/
            if (simCounter == 0)
            {
                cout << "There are no sims yet\n";
                break;
            }
            /*If there are sims give options*/
            choiceSimFunctions(PerArr, simCounter);
            /*
            Daily living is taxing,
            so reprisenting this is fuction named "life" which removes 1 (-1) from all stats(Needs).
            */
            life(PerArr, simCounter);
            break;
        default:
            cout << "error you shouldn't get this messege line: " << __LINE__ << __func__ << endl;
            break;
        }
    }
    return 0;
}
