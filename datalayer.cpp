#include "datalayer.h"
#include "genius.h"

using namespace std;

DataLayer::DataLayer()
{

}

istream& operator >>(istream& in, const Genius& p1)
{
    string name = p1.getName();
    string gender = p1.getGender();
    int age = p1.getAge();

    getline(in, name, ',');
    getline(in, gender, ',');
    in >> age;

    return in;
}


vector<Genius> DataLayer::getVector()
{
    vector<Genius> GeniusVector;
    fstream theFile ("data.txt", ios::in);
    Genius temp;
    if(theFile.is_open())
    {
        while(theFile >> temp)
        {
            GeniusVector.push_back(temp);
        }
    }
    else
    {
        cout << "List was not found" << endl;
    }

    return GeniusVector;
}

// Post fall
