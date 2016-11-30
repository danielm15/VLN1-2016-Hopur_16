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

    for(size_t i = 0; i < GVector.size(); i++)
    {
        string geniusName = GVector[i].getName();

        // http://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c
        if (geniusName.find(name) != std::string::npos)
        {
            return GVector[i];
        }
    }
    throw -1;
}

bool ServiceLayer::addEntry(string name, char gender, size_t date_of_birth, size_t date_of_death)
{
    DataLayer d;
    string fullGender;

    //Error check TODO
    if (gender == 'm')
    {
        fullGender = "Male";
    }
    else if (gender == 'f')
    {
        fullGender = "Female";
    }
    else
    {
        fullGender = "N/A";
    }
    Genius genius(name, fullGender, date_of_birth, date_of_death);
    return d.save(genius);
}
