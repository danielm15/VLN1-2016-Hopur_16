#ifndef SERVICELAYER_H
#define SERVICELAYER_H

#include <vector>
#include <algorithm>
#include <genius.h>
#include <datalayer.h>

using namespace std;

class ServiceLayer
{
public:
    ServiceLayer();
    vector<Genius> sortVector();
    Genius find(string name) const;
    vector<Genius> getGenius();
    bool addEntry(string name, char gender, size_t date_of_birth, size_t date_of_death);
};

#endif SERVICELAYER_H
