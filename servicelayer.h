#ifndef SERVICELAYER_H
#define SERVICELAYER_H

#include <vector>
#include "genius.h"
#include "datalayer.h"
#include <algorithm>

using namespace std;

class ServiceLayer
{
public:
    ServiceLayer();
    vector<Genius> sortVector();
};

#endif SERVICELAYER_H
