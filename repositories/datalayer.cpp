#include "datalayer.h"

using namespace std;

DataLayer::DataLayer()
{

}

// Reads data from comma seperated file (.csv)
// by pushing it into a vector of type Genius
vector<GeniusModel> DataLayer::getInfo()
{
    vector<GeniusModel> GeniusVector;
    string name, gender,str_birthyear, str_deathyear;
    unsigned int year_of_birth, year_of_death;

    ifstream theFile;
    theFile.open(FILE);

    if(theFile.is_open())
    {
        while (!theFile.eof())
        {
            getline(theFile, name, ',');
            getline(theFile, gender, ',');
            getline(theFile, str_birthyear, ',');
            getline(theFile, str_deathyear, '\n');
            year_of_birth = atoi(str_birthyear.c_str());
            year_of_death = atoi(str_deathyear.c_str());

            GeniusModel temp = GeniusModel(name, gender, year_of_birth, year_of_death);
            GeniusVector.push_back(temp);
        }
        GeniusVector.pop_back();
    }
    else
    {
        cerr << "List was not found" << endl;
    }
    theFile.close();

    return GeniusVector;
}

// Saves genius to the bottom of the file, if he is still
// alive then it saves N/A as a death year.
bool DataLayer::save(GeniusModel genius)
{
    ofstream theFile;
    theFile.open(FILE.c_str(), ios::out | ios::app);
    string deathYear = to_string(genius.getDeathYear());

    if (deathYear == "0")
    {
        deathYear = "N/A";
    }

    if(theFile.is_open())
    {
        theFile << genius.getName() << "," << genius.getGender() << "," << genius.getBirthYear() << "," << deathYear << endl;
    }
    else
    {
        return false;
    }
    theFile.close();

    return true;
}

// Checks if the genius is in the file and removes him. Saves the file
bool DataLayer::remove(GeniusModel genius)
{
    vector<GeniusModel> geniuses = getInfo();

    for (unsigned int i = 0; i < geniuses.size(); i++)
    {
        if (genius == geniuses[i])
        {
            geniuses.erase(geniuses.begin() + i);
            return saveList(geniuses);
        }
    }

    return false;
}

// Truncates the files and writes everything again to it.
bool DataLayer::saveList(vector<GeniusModel> geniuses)
{
    ofstream theFile;
    theFile.open(FILE.c_str());

    if(theFile.is_open())
    {
        for (unsigned int i = 0; i < geniuses.size(); i++)
        {
            string deathYear = to_string(geniuses[i].getDeathYear());

            if (deathYear == "0")
            {
                deathYear = "N/A";
            }
            theFile << geniuses[i].getName() << "," << geniuses[i].getGender() << "," << geniuses[i].getBirthYear() << "," << deathYear << endl;
        }
    }
    else
    {
        return false;
    }
    theFile.close();

    return true;
}
