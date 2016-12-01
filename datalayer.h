#ifndef DATALAYER_H
#define DATALAYER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "genius.h"

class DataLayer
{
public:
    DataLayer();
    vector<Genius> getInfo();
    bool save(Genius genius);
};

#endif //DATALAYER_H
