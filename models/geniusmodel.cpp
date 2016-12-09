#include "models/geniusmodel.h"

GeniusModel::GeniusModel()
{

}

GeniusModel::GeniusModel(string name, string gender, unsigned int yearOfBirth, unsigned int yearOfDeath)
{
    _name = name;
    _gender = gender;
    _yearOfBirth = yearOfBirth;
    _yearOfDeath = yearOfDeath;
}

GeniusModel::GeniusModel(unsigned int id, string name, string gender, unsigned int yearOfBirth, unsigned int yearOfDeath)
{
    _id = id;
    _name = name;
    _gender = gender;
    _yearOfBirth = yearOfBirth;
    _yearOfDeath = yearOfDeath;
}

// Teach the class who should get higher in shorted list.
bool GeniusModel::operator <(const GeniusModel& p) const
{
    return _name < p._name;
}

unsigned int GeniusModel::getId() const
{
    return _id;
}

string GeniusModel::getName() const
{
    return _name;
}

string GeniusModel::getGender() const
{
    return _gender;
}

unsigned int GeniusModel::getBirthYear() const
{
    return _yearOfBirth;
}

unsigned int GeniusModel::getDeathYear() const
{
    return _yearOfDeath;
}

bool GeniusModel::update(string name, string gender, unsigned int birthYear, unsigned int deathYear)
{
    _name = name;
    _gender = gender;
    _yearOfBirth = birthYear;
    _yearOfDeath = deathYear;

    return true;
}

// Prints out genius line, if it is still alive death year
// prints out as a N/A
ostream& operator <<(ostream& out, const GeniusModel& p1)
{
    out << "|" << setw(23) << left << p1.getName() << " | ";
    out << setw(6) << p1.getGender() << " | ";
    out << setw(7) << p1.getBirthYear() << setw(6) << " - ";

    if(p1.getDeathYear() == 0)
    {
        out << setw(6) << "N/A" << setw(6) << "|";
    }
    else
    {
        out << setw(6) << p1.getDeathYear() << setw(6) << "|";
    }

    return out;
}

bool operator ==(const GeniusModel& g1, const GeniusModel& g2)
{
    if (g1._id != g2._id)
        return false;
    if (g1._name != g2._name)
        return false;
    if (g1._gender != g2._gender)
        return false;
    if (g1._yearOfBirth != g2._yearOfBirth)
        return false;
    if (g1._yearOfDeath != g2._yearOfDeath)
        return false;

    return true;
}
