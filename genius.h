#ifndef GENIUS_H
#define GENIUS_H

#include <iostream>
#include <fstream>
#include <string>
#include <istream>

using namespace std;

class Genius
{
public:
    Genius();
    Genius(string name, string gender, unsigned int age);
    friend ostream& operator <<(ostream& out, const Genius& p1);

    string getName() const
    {
        return _name;
    }

    string getGender() const
    {
        return _gender;
    }

    unsigned int getAge() const
    {
        return _age;
    }



private:
    string _name;
    string _gender;
    unsigned int _age;
};

#endif GENIUS_H
