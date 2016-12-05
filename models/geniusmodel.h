#ifndef GENIUS_H
#define GENIUS_H

#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <iomanip>

using namespace std;

class GeniusModel
{
public:

    // Constructors
    GeniusModel();
    GeniusModel(string name, string gender, unsigned int year_of_birth, unsigned int year_of_death);

    // comparison for sort algorithm.
    bool operator <(const GeniusModel& p) const;

    // Getters for private parameters
    string getName() const;
    string getGender() const;
    unsigned int getBirthYear() const;
    unsigned int getDeathYear() const;

    // Friend functions
    friend ostream& operator <<(ostream& out, const GeniusModel& p1);
    friend bool operator ==(const GeniusModel& g1, const GeniusModel& p2);

private:
    unsigned int _id;
    string _name;
    string _gender;
    unsigned int _year_of_birth;
    unsigned int _year_of_death;
};

#endif //GENIUS_H
