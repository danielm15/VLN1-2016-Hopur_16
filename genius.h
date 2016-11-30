#ifndef GENIUS_H
#define GENIUS_H

#include <iostream>
#include <fstream>
#include <string>
#include <istream>

using namespace std;

class Genius
{
public:
    Genius();
    Genius(string name, string gender, unsigned int year_of_birth, unsigned int year_of_death);
    friend ostream& operator <<(ostream& out, const Genius& p1);

    bool operator <(const Genius& p) const
    {
        return _name < p._name;
    }

    string getName() const
    {
        return _name;
    }

    string getGender() const
    {
        return _gender;
    }

    unsigned int getBirthYear() const
    {
        return _year_of_birth;
    }

    unsigned int getDeathYear() const
    {
        return _year_of_death;
    }

private:
    string _name;
    string _gender;
    unsigned int _year_of_birth;
    unsigned int _year_of_death;
};

#endif GENIUS_H
