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
    /**
     * @brief GeniusModel
     */
    GeniusModel();

    /**
     * @brief GeniusModel
     * @param name
     * @param gender
     * @param yearOfBirth
     * @param yearOfDeath
     */
    GeniusModel(string name, string gender, unsigned int yearOfBirth, unsigned int yearOfDeath);

    /**
     * @brief GeniusModel
     * @param id
     * @param name
     * @param gender
     * @param yearOfBirth
     * @param yearOfDeath
     */
    GeniusModel(unsigned int id, string name, string gender, unsigned int yearOfBirth, unsigned int yearOfDeath);

    /**
     * @brief operator < compares two models together and checks who's smaller
     * @param p
     * @return true of false
     */
    bool operator <(const GeniusModel& p) const;


    /**
     * @brief getId getter
     * @return _id
     */
    unsigned int getId() const;

    /**
     * @brief getName getter
     * @return _name
     */
    string getName() const;

    /**
     * @brief getGender getter
     * @return _gender
     */
    string getGender() const;

    /**
     * @brief getBirthYear getter
     * @return _birthYear
     */
    unsigned int getBirthYear() const;

    /**
     * @brief getDeathYear getter
     * @return _deathYear
     */
    unsigned int getDeathYear() const;

    /**
     * @brief operator << Prints out the model
     * @param out
     * @param p1
     * @return void
     */
    friend ostream& operator <<(ostream& out, const GeniusModel& p1);

    /**
     * @brief operator == Checks if two objects are the same
     * @param g1
     * @param p2
     * @return bool
     */
    friend bool operator ==(const GeniusModel& g1, const GeniusModel& p2);

private:
    unsigned int _id;
    string _name;
    string _gender;
    unsigned int _yearOfBirth;
    unsigned int _yearOfDeath;
};

#endif //GENIUS_H
