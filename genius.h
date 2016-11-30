#ifndef GENIUS_H
#define GENIUS_H

#include <iostream>
#include <fstream>
#include <string>
#include <istream>

using namespace std;

class Genius
{
private:
    string _name;
    string _gender;
    unsigned int _year_of_birth;
    unsigned int _year_of_death;
public:
    Genius();
    Genius(string name, string gender, unsigned int year_of_birth, unsigned int year_of_death);
    friend ostream& operator <<(ostream& out, const Genius& p1);
<<<<<<< HEAD
=======

    bool operator <(const Genius& p) const
    {
        return _name < p._name;
    }
>>>>>>> bcb7d08d5c2d3979683b10917a90db9b45b91e4f

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

<<<<<<< HEAD
private:
    string _name;
    string _gender;
    unsigned int _year_of_birth;
    unsigned int _year_of_death;
=======

>>>>>>> bcb7d08d5c2d3979683b10917a90db9b45b91e4f
};

#endif GENIUS_H
