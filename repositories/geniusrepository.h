#ifndef GENIUSREPOSITORY_H
#define GENIUSREPOSITORY_H

#include <vector>
#include <string>

#include "models/geniusmodel.h"

using namespace std;

class GeniusRepository
{
public:
    GeniusRepository();

    vector<Genius> getAllGeniuses();
    vector<Genius> searchForGenius();
    bool addGenius();

private:
    string databasePath;
};

#endif // GENIUSREPOSITORY_H
