#ifndef SERVICELAYER_H
#define SERVICELAYER_H

#include <vector>
#include <algorithm>
#include <genius.h>
#include <datalayer.h>

using namespace std;

class ServiceLayer
{
public:
    ServiceLayer();

    // Returns all data sorted in alphabetical order
    vector<Genius> sortVector();

    // Checks if name is a substring in the dataset
    Genius find(string name) const;

    // Reterns the dataset
    vector<Genius> getGenius();

    // Adds a new line to the dataset.
    bool addEntry(string name, char gender, size_t date_of_birth, size_t date_of_death);

    // Removes entry
    // Use find to get genius
    // send it to this method and it deletes it.
    bool removeEntry(Genius genius);

    // Takes char and returns corresponding gender
    string getFullGenderName(char gender);

};

#endif //SERVICELAYER_H
