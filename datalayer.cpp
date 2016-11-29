#include "datalayer.h"
#include "genius.h"

using namespace std;

DataLayer::DataLayer()
{

}

ostream& operator <<(ostream& out, const Genius& p1)
{
    out << p1.getName();
    out << p1.getGender();
    out << p1.getAge();

    return out;

}

istream& operator >>(istream& in, const Genius& p1)
{
    string name = p1.getName();
    string gender = p1.getGender();
    int age = p1.getAge();

    getline(in, name, ',');
    getline(in, gender, ',');
    in >> age;
    in.ignore();

    return in;
}


vector<Genius> getVector()
{
    vector<Genius> GeniusVector;
    fstream theFile("data.txt", ios::in);
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
