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

    // Constructors
    Genius();
    Genius(string name, string gender, unsigned int year_of_birth, unsigned int year_of_death);

    // comparison for sort algorithm.
    bool operator <(const Genius& p) const;

    // Getters for private parameters
    string getName() const;
    string getGender() const;
    unsigned int getBirthYear() const;
    unsigned int getDeathYear() const;

    // Friend functions
    friend ostream& operator <<(ostream& out, const Genius& p1);
    friend bool operator ==(const Genius& g1, const Genius& p2);

private:
    string _name;
    string _gender;
    unsigned int _year_of_birth;
    unsigned int _year_of_death;
};

#endif //GENIUS_H
