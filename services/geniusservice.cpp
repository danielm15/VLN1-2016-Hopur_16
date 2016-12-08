#include "geniusservice.h"

GeniusService::GeniusService()
{

}

// Fetches the GeniusVector from the DataLayer
vector<GeniusModel> GeniusService::getGenius()
{
    return _geniusRepository.getAllGeniuses();
}

vector<GeniusModel> GeniusService::sort(string column, bool ascending)
{
    return _geniusRepository.sort(column, ascending);
}

bool GeniusService::sortOrder(string sortBy)
{
    bool ascending = true;

    if (sortBy == "D" || sortBy == "d")
        ascending = false;
    else if (sortBy == "A" || sortBy == "a")
        ascending = true;

    return ascending;
}

vector<GeniusModel> GeniusService::sortGenius(string sortedInput, string sortBy)
{
    string column;
    bool asc;

    if(sortedInput == "a" || sortedInput == "A")
    {
        column = "Name";
    }
    else if(sortedInput == "b" || sortedInput == "B")
    {
        column = "Gender";
    }
    else if(sortedInput == "c" || sortedInput == "C")
    {
        column = "BirthYear";
    }
    else if(sortedInput == "d" || sortedInput == "D")
    {
        column = "DeathYear";
    }
    asc = sortOrder(sortBy);

    return sort(column, asc);
}

vector<GeniusModel> GeniusService::find(string name)
{
    return _geniusRepository.searchForGenius(name);
}

bool GeniusService::addGenius(string name, char gender, unsigned int dateOfBirth, unsigned int dateOfDeath)
{
    string fullGender = getFullGenderName(gender);
    GeniusModel genius(name, fullGender, dateOfBirth, dateOfDeath);
    return _geniusRepository.saveGenius(genius);
}

bool GeniusService::remove(GeniusModel genius)
{
    return _geniusRepository.removeGenius(genius);
}

bool GeniusService::update(GeniusModel model)
{
    return _geniusRepository.updateGenius(model);
}

vector<ComputerModel> GeniusService::getAllComputersGeniusBuilt(GeniusModel model)
{
    return _computerGeniusRepository.getGeniuseComputers(model);
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
