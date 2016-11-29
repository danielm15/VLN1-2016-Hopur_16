#ifndef GENIUS_H
#define GENIUS_H

#include <string>

using namespace std;

class Genius
{
public:
    Genius();
    Genius(string name, string gender, int age, int id);

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

    int getId() const
    {
        return _id;
    }

private:
    string _name;
    string _gender;
    int _age;
    int _id;
};

#endif // GENIUS_H
