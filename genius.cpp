#include "genius.h"

Genius::Genius()
{

}

Genius::Genius(string name, string gender, size_t year_of_birth, size_t year_of_death)
{
    _name = name;
    _gender = gender;
    _year_of_birth = year_of_birth;
    _year_of_death = year_of_death;
}

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

