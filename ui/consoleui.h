#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <iostream>
#include <fstream>
#include <vector>
#include <services/servicelayer.h>
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
};

#endif //CONSOLEUI_H
