#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <iostream>
#include <fstream>
#include <vector>
#include <services/geniusservice.h>
#include <services/computerservice.h>
#include <validation/computervalidation.h>
#include <validation/geniusvalidation.h>
#include <stdlib.h>
#include <cstdio>
#include <string>

class ConsoleUI
{
public:
    ConsoleUI();
    void run();
private:
    GeniusService _geniusservice;
    ComputerService _computerservice;
    void displayUnsortedList();
    void displaySortedList();
    void addNewEntryToDataSet();
    void searchForEntries();
    void deleteAnEntry();
    void modifyAnEntry();
    void printGVector(vector<GeniusModel> GVector);
    void printCVector(vector<ComputerModel> CVector);
    void printGeniusSort();
    void printComputerSort();
    void printError();
    void smile();
    void printMenu();
    void clearscreen ();
};

#endif //CONSOLEUI_H
