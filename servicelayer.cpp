#include "servicelayer.h"

using namespace std;

ServiceLayer::ServiceLayer()
{

}

// Fetches the GeniusVector with getGenius and sorts
// it in descending alphabetical order.
// Makes use of the overloaded < operator
vector<Genius> ServiceLayer::sortVector()
{
    vector<Genius> GVector = getGenius();

    sort(GVector.begin(), GVector.end());

    return GVector;
}

// Fetches the GeniusVector from the DataLayer
vector<Genius> ServiceLayer::getGenius()
{
    DataLayer p;
    return p.getInfo();
}


// Searches for name in Geniues vector from the data layer.
// If it finds a subset of the query in name it returns corresponding
// Genius object. If it does not find anything it raises a exception
Genius ServiceLayer::find(string name) const
{
    DataLayer d;
    vector<Genius> GVector = d.getInfo();
    Genius g;
    string lowercaseName = toLowerCase(name);

    for(size_t i = 0; i < GVector.size(); i++)
    {
        string geniusName = toLowerCase(GVector[i].getName());

        // http://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c
        if (geniusName.find(lowercaseName) != std::string::npos)
        {
            return GVector[i];
        }
    }
    throw -1;
}

// Saves a new line to data.csv file, checks which gender
// it is and fills in the right one. Returns true if it
// could save, false if not
bool ServiceLayer::addEntry(string name, char gender, size_t date_of_birth, size_t date_of_death)
{
    DataLayer d;
    string fullGender = getFullGenderName(gender);
    Genius genius(name, fullGender, date_of_birth, date_of_death);
    return d.save(genius);
}

// could save, false if not
bool ServiceLayer::removeEntry(Genius genius)
{
    DataLayer d;
    return d.remove(genius);
}

// Give me a char and I will tell you what gender it is supposed to be
string ServiceLayer::getFullGenderName(char gender)
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

// Converts string to lowercase and returns it.
string ServiceLayer::toLowerCase(string s) const
{
    string lowercaseName = s;
    for (size_t i = 0; i < s.length(); i++)
    {
        lowercaseName[i] = tolower(lowercaseName[i]);
    }
    return lowercaseName;
}
