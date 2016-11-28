#ifndef GENIUS_H
#define GENIUS_H

#include <string>

using namespace std;

class Genius
{
public:
    Genius();
    Genius(string name, int age);

    string getName() const
    {
        return _name;
    }

    int getAge() const
    {
        return _age;
    }

private:
    string _name;
    int _age;
};

#endif // GENIUS_H
