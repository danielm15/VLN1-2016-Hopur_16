#ifndef GENIUSREPOSITORY_H
#define GENIUSREPOSITORY_H

#include <QtSql>
#include <QVariant>
#include <QString>


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
     * @brief sort Sorts geniuses by name
     * @param field, which field should be sorted by
     * @param asc if true sort by ascending
     * @return sorted vector
     */
    vector<GeniusModel> sort(string field, bool asc);

    /**
    * @brief addGenius saves a genius model to a file
    * @param The model to save
    * @return true if it was a success, false if it was a failure
    */
    bool saveGenius(GeniusModel genius);

    /**
     * @brief removeGenius removes genius from the repository, it uses id from the model to find out which one to remve
     * @param model
     * @return true if delete was a success, else false
     */
    bool removeGenius(GeniusModel model);

    /**
     * @brief updateGenius, updates the record for the genius based on genius model fields in the model.
     * @param model
     * @return true if success, else false
     */
    bool updateGenius(GeniusModel model);
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
