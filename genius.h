#ifndef GENIUS_H
#define GENIUS_H

#include <string>

using namespace std;

class Genius
{
public:
    Genius();
    Genius(string name, string gender, int age);

    string getName() const
    {
        return _name;
    }

    string getGender() const
    {
        return _gender;
    }

    int getAge() const
    {
        return _age;
    }



private:
    string _name;
    string _gender;
    int _age;
};

#endif // GENIUS_H
