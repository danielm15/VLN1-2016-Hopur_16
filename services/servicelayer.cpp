#include "services/servicelayer.h"

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

vector<Genius> ServiceLayer::sortByGenderVector()
{
    vector<Genius> GVector = getGenius();
    vector<Genius> newGVector;

    for(unsigned i = 0; i < GVector.size(); i++)
    {
        if(GVector[i].getGender() == "Female")
            newGVector.push_back(GVector[i]);
    }
    for(unsigned i = 0; i < GVector.size(); i++)
    {
        if(GVector[i].getGender() == "Male")
            newGVector.push_back(GVector[i]);
    }
    for(unsigned i = 0; i < GVector.size(); i++)
    {
        if(GVector[i].getGender() == "N/A")
            newGVector.push_back(GVector[i]);
    }
    return newGVector;
}

struct Birth
{
    bool operator() (Genius &rhs, Genius &lhs)
    {
        return lhs.getBirthYear() < rhs.getBirthYear();
    }
};

vector<Genius> ServiceLayer::sortByBirthYearVector()
{
    vector<Genius> GVector = getGenius();

    Birth birth;

    sort(GVector.begin(), GVector.end(), birth);

    return GVector;
}

struct Death
{
    bool operator() (Genius &rhs, Genius &lhs)
    {
        return lhs.getDeathYear() < rhs.getDeathYear();
    }
};

vector<Genius> ServiceLayer::sortByDeathYearVector()
{
    vector<Genius> GVector = getGenius();

    Death death;

    sort(GVector.begin(), GVector.end(), death);

    return GVector;
}


// Fetches the GeniusVector from the DataLayer
vector<Genius> ServiceLayer::getGenius()
{
    DataLayer p;
    return p.getInfo();
}


// Searches for name in Genius vector from the data layer.
// If it finds a subset of the query in name it returns corresponding
// Genius object. If it does not find anything it raises a exception
Genius ServiceLayer::find(string name) const
{
    DataLayer d;
    vector<Genius> GVector = d.getInfo();
    Genius g;
    string lowercaseName = toLowerCase(name);

    for(unsigned int i = 0; i < GVector.size(); i++)
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

vector<Genius> ServiceLayer::filter(string name) const
{
    DataLayer d;
    vector<Genius> GVector = d.getInfo();
    vector<Genius> filtered;
    Genius g;
    string lowercaseName = toLowerCase(name);

    for(unsigned int i = 0; i < GVector.size(); i++)
    {
        string geniusName = toLowerCase(GVector[i].getName());

        // http://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c
        if (geniusName.find(lowercaseName) != std::string::npos)
        {
            filtered.push_back(GVector[i]);
        }
    }
    return filtered;
}

// Saves a new line to data.csv file, checks which gender
// it is and fills in the right one. Returns true if it
// could save, false if not
bool ServiceLayer::addEntry(string name, char gender, unsigned int dateOfBirth, unsigned int dateOfDeath)
{
    DataLayer d;
    string fullGender = getFullGenderName(gender);
    Genius genius(name, fullGender, dateOfBirth, dateOfDeath);
    return d.save(genius);
}


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
    for (unsigned int i = 0; i < s.length(); i++)
    {
        lowercaseName[i] = tolower(lowercaseName[i]);
    }
    return lowercaseName;
}
