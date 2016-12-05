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

    /**
    * @brief getAllGeniuses fetches all geniuses from the database
    * @return a vector containing all geniuses from the database
    */
    vector<GeniusModel> getAllGeniuses();

    /**
    * @brief searchForGenius fetches all geniuses from the database that matches name parameter
    * @param name that user wishes to filter by
    * @return a vector containing all geniuses from the database that matches this contition
    */
    vector<GeniusModel> searchForGenius();

    /**
    * @brief addGenius saves a genius model to a file
    * @param The model to save
    * @return true if it was a success, false if it was a failure
    */
    bool addGenius(GeniusModel model);
private:
    QSqlDatabase _db;

    /**
     * @brief extractQueryToVector extrcts all variables from the query and makes new GeniusModel and pushes it to the vector
     * @param query object from the database
     * @return a vector for GeniusModels
     */
    vector<GeniusModel> extractQueryToVector(QSqlQuery query);
};

#endif // GENIUSREPOSITORY_H
