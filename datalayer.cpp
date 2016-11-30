#include "datalayer.h"
#include "genius.h"

using namespace std;

DataLayer::DataLayer()
{

}

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
        cout << "List was not found" << endl;
    }
    theFile.close();

    return GeniusVector;
}

// Post fall
