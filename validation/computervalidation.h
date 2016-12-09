#ifndef COMPUTERVALIDATION_H
#define COMPUTERVALIDATION_H

#include <ui/consoleui.h>

#include <string>
#include <iostream>
#include <stdlib.h>
#include <cstdio>

using namespace std;

class ComputerValidation
{
public:
    ComputerValidation();

    string promptForModelName();
    bool validateModelName(string modelName);

    unsigned int promptForMakeYear();
    bool validateMakeYear(string makeYearString);

    string promptForType();
    bool validateType(string type);

    int promptForBuilt();
    bool validateBuilt(string built);
private:
    void leave();
};

#endif // COMPUTERVALIDATION_H
