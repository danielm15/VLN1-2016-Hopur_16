#ifndef SERVICELAYER_H
#define SERVICELAYER_H

#include <vector>
<<<<<<< HEAD
#include "genius.h"
#include "datalayer.h"
#include <algorithm>
=======
#include <genius.h>
#include <datalayer.h>

>>>>>>> 64987420dd9cd958d282cfa45190bd683d1bac98

using namespace std;

class ServiceLayer
{
public:
    ServiceLayer();
<<<<<<< HEAD
    vector<Genius> sortVector();
=======

	Genius find(string name) const;
    vector<Genius> getGenius();
	vector<Genius> sort();
    bool addEntry(string name, char gender, size_t date_of_birth, size_t date_of_death);
>>>>>>> 64987420dd9cd958d282cfa45190bd683d1bac98
};

#endif SERVICELAYER_H
