#include "geniusservice.h"

GeniusService::GeniusService()
{

}

// Fetches the GeniusVector from the DataLayer
vector<GeniusModel> GeniusService::getGenius()
{
    GeniusRepository repo;
    return repo.getAllGeniuses();
}

bool GeniusService::addGenius(string name, char gender, unsigned int dateOfBirth, unsigned int dateOfDeath)
{
    GeniusRepository g;
    string fullGender = getFullGenderName(gender);
    GeniusModel genius(name, fullGender, dateOfBirth, dateOfDeath);
    return g.saveGenius(genius);
}

// Give me a char and I will tell you what gender it is supposed to be
string GeniusService::getFullGenderName(char gender)
{
    string fullGender = "";
    if (gender == 'm' || gender == 'M')
    {
        fullGender = "Male";
    }
    else if (gender == 'f' || gender == 'F')
    {
        fullGender = "Female";
    }
    else
    {
        fullGender = "N/A";
    }

    return fullGender;
}