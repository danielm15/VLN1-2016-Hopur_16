#ifndef GENIUS_H
#define GENIUS_H

#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <iomanip>

using namespace std;

class Genius
{
public:
    Genius();
    Genius(string name, string gender, size_t year_of_birth, size_t year_of_death);
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

    size_t getBirthYear() const
    {
        return _year_of_birth;
    }

    size_t getDeathYear() const
    {
        return _year_of_death;
    }

private:
    string _name;
    string _gender;
    size_t _year_of_birth;
    size_t _year_of_death;
};

#endif GENIUS_H
