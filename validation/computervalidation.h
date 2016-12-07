#ifndef COMPUTERVALIDATION_H
#define COMPUTERVALIDATION_H

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

    bool promptForBuilt();
    bool validateBuilt(string built);
};

#endif // COMPUTERVALIDATION_H
