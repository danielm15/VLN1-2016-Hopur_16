#ifndef SERVICELAYER_H
#define SERVICELAYER_H

#include <vector>
#include <algorithm>

#include "models/geniusmodel.h"
#include "repositories/datalayer.h"
#include "repositories/geniusrepository.h"

using namespace std;

class ServiceLayer
{
public:
    ServiceLayer();

    vector<GeniusModel> filter(string name);

    // Returns all data sorted in alphabetical order
    vector<GeniusModel> sortVector();

    // Checks if name is a substring in the dataset
    GeniusModel find(string name) const;

    // Returns the dataset
    vector<GeniusModel> getGenius();

    // Adds a new line to the dataset.
    bool addEntry(string name, char gender, unsigned int date_of_birth, unsigned int date_of_death);


    // Removes entry
    // Use find to get genius
    // send it to this method and it deletes it.
    bool removeEntry(GeniusModel genius);

    // Takes char and returns corresponding gender
    string getFullGenderName(char gender);

    vector<GeniusModel> sortByGenderVector();

    vector<GeniusModel> sortByBirthYearVector();

    vector<GeniusModel> sortByDeathYearVector();

private:
    // Converts string to lowercase and returns it.
    string toLowerCase(string s) const;

    GeniusRepository _g;
};

#endif //SERVICELAYER_H
