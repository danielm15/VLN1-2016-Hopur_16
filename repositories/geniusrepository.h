#ifndef GENIUSREPOSITORY_H
#define GENIUSREPOSITORY_H

#include <QtSql>
#include <QVariant>

#include <vector>
#include <string>

#include "models/geniusmodel.h"

using namespace std;

class GeniusRepository
{
public:
    GeniusRepository();
    ~GeniusRepository()
    {
        _db.close();
    }

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
    vector<GeniusModel> searchForGenius(string name);

    /**
     * @brief sortByName Sorts geniuses by name
     * @param asc if true sort by ascending
     * @return sorted vector
     */
    vector<GeniusModel> sortByName(bool asc);

    /**
    * @brief addGenius saves a genius model to a file
    * @param The model to save
    * @return true if it was a success, false if it was a failure
    */
    bool saveGenius(GeniusModel genius);

    /**
     * @brief removeGenius removes genius from the repository
     * @param model
     * @return true if delete was a success, else false
     */
    bool removeGenius(GeniusModel model);
private:
    QSqlDatabase _db;

    /**
     * @brief extractQueryToVector extrcts all variables from the query and makes new GeniusModel and pushes it to the vector
     * @param query object from the database
     * @return a vector for GeniusModels
     */
    vector<GeniusModel> extractQueryToVector(QSqlQuery query) const;

    /**
     * @brief toLowerCase converts string to lowercase
     * @param s
     * @return lowercase version of string s
     */
    string toLowerCase(string name) const;
};

#endif // GENIUSREPOSITORY_H
