#ifndef GENIUS_H
#define GENIUS_H

#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <iomanip>
#include <vector>
#include "models/computermodel.h"

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
     * @brief GeniusModel
     * @param id
     * @param name
     * @param gender
     * @param yearOfBirth
     * @param yearOfDeath
     * @param computers
     */
    GeniusModel(unsigned int id, string name, string gender, unsigned int yearOfBirth, unsigned int yearOfDeath, vector<ComputerModel> computers);

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
     * @brief getComputers Returns all computer genius has been associated with
     * @return vector of computers
     */
    vector<ComputerModel> getComputers() const;

    /**
     * @brief addComputer Adds new computer that genius has built
     * @param model
     * @return true if success, else false
     */
    void addComputer(ComputerModel model);

    /**
     * @brief addComputers adds many computers to the genius computer vector
     * @param model
     */
    void addComputers(vector<ComputerModel> model);

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
    vector<ComputerModel> _computers;

    /**
     * @brief isComputerAlreadyInGenius validates if computer has already been added to genius model.
     * @param model
     * @return
     */
    bool isComputerAlreadyInGenius(ComputerModel model);
};

#endif //GENIUS_H
