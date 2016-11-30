#ifndef SERVICELAYER_H
#define SERVICELAYER_H

#include <vector>
#include <genius.h>
#include <datalayer.h>


using namespace std;

class ServiceLayer
{
public:
    ServiceLayer();

	Genius find(string name) const;
    vector<Genius> getGenius();
	vector<Genius> sort();
};

#endif SERVICELAYER_H
