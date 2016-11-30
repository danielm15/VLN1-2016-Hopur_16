#include "datalayer.h"
#include "genius.h"

using namespace std;

DataLayer::DataLayer()
{

}

vector<Genius> DataLayer::getInfo()
{
    vector<Genius> GeniusVector;
    string name, gender,str_age;
    unsigned int age;

    ifstream theFile;
    theFile.open("data.csv");

    if(theFile.is_open())
    {
        while (!theFile.eof())
        {
            getline(theFile, name, ',');
            getline(theFile, gender, ',');
            getline(theFile, str_age, '\n');
            age = atoi(str_age.c_str());

            Genius temp = Genius(name, gender, age);
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
