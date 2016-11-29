#include "datalayer.h"
#include <fstream>
#include <iostream>
#include <istream>
#include <iomanip>
#include <vector>
#include <string>
#include "genius.h"

using namespace std;

DataLayer::DataLayer()
{

}

ostream& operator <<(ostream& out, const Genius& p1)
{
    out << p1.getName();
    out << p1.getAge();
    out << p1.getGender();
    return out;

}

/*istream& operator >>(istream& in, Genius& p1)
{
    getline(in, p1.getName());
    in >> p1.getAge();
    in >> p1.getGender();
    in.ignore();
    return in;
}
*/

void readFile(vector<Genius> getGenius)
{
    ifstream theFile;
    theFile.open("data.txt");
    Genius temp;
    if(theFile.is_open())
    {
        while(theFile >> temp)
        {
            getGenius.push_back(temp);
        }
        for(int i=0; i < getGenius.size(); i++)
        {
            cout << getGenius[i] << endl;
        }
    }
    else
    {
        cout << "List was not found" << endl;
    }
}

// Post fall
