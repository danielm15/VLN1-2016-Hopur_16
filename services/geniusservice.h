#ifndef GENIUSSERVICE_H
#define GENIUSSERVICE_H

#include "repositories/geniusrepository.h"

#include <string>

class GeniusService
{
public:
    GeniusService();
    vector<GeniusModel> getGenius();
    bool addGenius(string name, char gender, unsigned int dateOfBirth, unsigned int dateOfDeath);
    string getFullGenderName(char gender);

};

#endif // GENIUSSERVICE_H
