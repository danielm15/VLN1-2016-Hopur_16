#ifndef GENIUSREPOSITORY_H
#define GENIUSREPOSITORY_H

#include <QtSql>

#include <vector>
#include <string>

#include "models/geniusmodel.h"

using namespace std;

class GeniusRepository
{
public:
    GeniusRepository();

    vector<GeniusModel> getAllGeniuses();
    vector<GeniusModel> searchForGenius();
    bool addGenius();
private:
    QSqlDatabase _db;
};

#endif // GENIUSREPOSITORY_H
