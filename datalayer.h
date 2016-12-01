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

    // Returns all the geniuses.
    vector<Genius> getInfo();

    // Saves new genius to the file
    bool save(Genius genius);

    // Removes genius from file
    bool remove(Genius genius);
private:
    const string FILE = "data.csv";

    // Updates the file
    bool saveList(vector<Genius> geniuses);
};

#endif //DATALAYER_H
