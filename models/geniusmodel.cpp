#include "models/geniusmodel.h"

Genius::Genius()
{

}

Genius::Genius(string name, string gender, unsigned int year_of_birth, unsigned int year_of_death)
{
    _name = name;
    _gender = gender;
    _year_of_birth = year_of_birth;
    _year_of_death = year_of_death;
}

// Teach the class who should get higher in shorted list.
bool Genius::operator <(const Genius& p) const
{
    return _name < p._name;
}

string Genius::getName() const
{
    return _name;
}

string Genius::getGender() const
{
    return _gender;
}

unsigned int Genius::getBirthYear() const
{
    return _year_of_birth;
}

unsigned int Genius::getDeathYear() const
{
    return _year_of_death;
}

// Prints out genius line, if it is still alive death year
// prints out as a N/A
ostream& operator <<(ostream& out, const Genius& p1)
{
    out << setw(20) << p1.getName() << " | ";
    out << setw(6) << p1.getGender() << " | ";
    out << setw(7) << p1.getBirthYear() << "-";

    if(p1.getDeathYear() == 0)
    {
        out << "N/A";
    }
    else
    {
        out << p1.getDeathYear();
    }

    return out;
}

bool operator ==(const Genius& g1, const Genius& g2)
{
    if (g1._name != g2._name)
        return false;
    if (g1._gender != g2._gender)
        return false;
    if (g1._year_of_birth != g2._year_of_birth)
        return false;
    if (g1._year_of_death != g2._year_of_death)
        return false;

    return true;
}
