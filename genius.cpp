#include "genius.h"

Genius::Genius()
{

}

Genius::Genius(string name, string gender, unsigned int age)
{
    _name = name;
    _gender = gender;
    _age = age;
}

ostream& operator <<(ostream& out, const Genius& p1)
{
    out << p1.getName() << " | ";
    out << p1.getGender() << " | ";
    out << p1.getAge() << " | ";

    return out;
}

