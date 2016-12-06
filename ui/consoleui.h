#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <iostream>
#include <vector>
#include <services/servicelayer.h>
#include <services/geniusservice.h>
#include <services/computerservice.h>
#include <stdlib.h>
#include <cstdio>


class ConsoleUI
{
public:
    ConsoleUI();
    void clearscreen ();
    void run();
private:
    ServiceLayer _service;
    GeniusService _geniusservice;
    ComputerService _computerservice;
    void displayUnsortedList();
    void displaySortedList();
    void addNewEntryToDataSet();
    void searchForEntries();
    void deleteAnEntry();
    void printVector(vector<GeniusModel> GVector);

    string promptForName();
    bool validateName(string name);

    char promptForGender();
    bool validateGender(string name);

    unsigned int promptForDateOfBirth();
    bool validateDateOfBirth(string date);

    unsigned int promptForDateOfDeath(string name);
    bool validateDateOfDeath(string date);
};

#endif //CONSOLEUI_H
