#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <iostream>
#include <fstream>
#include <vector>
#include <services/geniusservice.h>
#include <services/computerservice.h>
#include <services/computergeniusservice.h>
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
    ComputerGeniusService _computergeniusservice;
    void displayUnsortedList();
    void displaySortedList();
    void addNewEntryToDataSet();
    void searchForEntries();
    void deleteAnEntry();
    void addRelationship();
    void modifyAnEntry();
    void printGVector(vector<GeniusModel> GVector);
    void printCVector(vector<ComputerModel> CVector);
    void printGeniusSort();
    void printComputerSort();
    void printError();
    void game();
    void printMenu();
    void clearscreen ();
};

#endif //CONSOLEUI_H
