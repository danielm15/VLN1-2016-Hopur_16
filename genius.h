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
    Genius(string name, string gender, size_t year_of_birth, size_t year_of_death);

    // comparison for sort algorithm.
    bool operator <(const Genius& p) const;

    // Getters for private parameters
    string getName() const;
    string getGender() const;
    size_t getBirthYear() const;
    size_t getDeathYear() const;

    // Friend functions
    friend ostream& operator <<(ostream& out, const Genius& p1);
    friend bool operator ==(const Genius& g1, const Genius& p2);

private:
    string _name;
    string _gender;
    size_t _year_of_birth;
    size_t _year_of_death;
};

#endif //GENIUS_H
