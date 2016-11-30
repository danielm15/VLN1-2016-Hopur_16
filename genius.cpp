#include "genius.h"

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

ostream& operator <<(ostream& out, const Genius& p1)
{
    out << p1.getName() << " | ";
    out << p1.getGender() << " | ";
    out << p1.getBirthYear() << "-";
    out << p1.getDeathYear() << " | ";

    return out;
}
