#ifndef DATALAYER_H
#define DATALAYER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "models/geniusmodel.h"

class DataLayer
{
public:
    DataLayer();

    // Returns all the geniuses.
    vector<GeniusModel> getInfo();

    // Saves new genius to the file
    bool save(GeniusModel genius);

    // Removes genius from file
    bool remove(GeniusModel genius);
private:
    const string FILE = "data.csv";

    // Updates the file
    bool saveList(vector<GeniusModel> geniuses);
};

#endif //DATALAYER_H
