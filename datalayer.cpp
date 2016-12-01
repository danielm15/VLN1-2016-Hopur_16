#include "datalayer.h"

using namespace std;

DataLayer::DataLayer()
{

}

// Reads data from comma seperated file (.csv)
// by pushing it into a vector of type Genius
vector<Genius> DataLayer::getInfo()
{
    vector<Genius> GeniusVector;
    string name, gender,str_birthyear, str_deathyear;
    unsigned int year_of_birth, year_of_death;

    ifstream theFile;
    theFile.open("data.csv");

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

            Genius temp = Genius(name, gender, year_of_birth, year_of_death);
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

bool DataLayer::save(Genius genius)
{
    string filename = "data.csv";

    ofstream theFile;
    theFile.open(filename.c_str(), ios::out | ios::app);
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
