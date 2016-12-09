#ifndef GENIUSVALIDATION_H
#define GENIUSVALIDATION_H

#include <ui/consoleui.h>

#include <string>
#include <iostream>
#include <stdlib.h>
#include <cstdio>

using namespace std;

class GeniusValidation
{
public:
    GeniusValidation();

    string promptForName();
    bool validateName(string name);

    char promptForGender();
    bool validateGender(string strgender);

    unsigned int promptForDateOfBirth();
    bool validateDateOfBirth(string date);

    unsigned int promptForDateOfDeath(string name, unsigned int dateOfBirth);
    bool validateDateOfDeath(string date, unsigned int dateOfBirth);
private:
    void leave();
};

#endif // GENIUSVALIDATION_H
