#ifndef COMPUTERREPOSITORY_H
#define COMPUTERREPOSITORY_H

#include <QtSql>

#include <vector>
#include <string>

#include "models/computermodel.h"

using namespace std;

class ComputerRepository
{
public:
    ComputerRepository();
    ~ComputerRepository()
    {
        _db.close();
    }

    /**
    * @brief getAllComputers fetches all computers from the database
    * @return a vector containing all computers from the database
    */
    std::vector<ComputerModel> getAllComputers();

    /**
    * @brief searchForComputer fetches all computers from the database that matches name parameter
    * @param name that user wishes to filter by
    * @return a vector containing all computers from the database that matches this contition
    */
    std::vector<ComputerModel> searchForComputer(string name);

    /**
    * @brief addCopmuter saves a computer model to a file
    * @param The model to save
    * @return true if it was a success, false if it was a failure
    */
    bool addComputer(ComputerModel model);

private:
    QSqlDatabase _db;

    /**
     * @brief extractQueryToVector extrcts all variables from the query and makes new ComputerModel and pushes it to the vector
     * @param query object from the database
     * @return a vector for ComputerModel
     */
    vector<ComputerModel> extractQueryToVector(QSqlQuery query);

    /**
     * @brief toLowerCase converts string to lowercase
     * @param s
     * @return lowercase version of string s
     */
    string toLowerCase(string s) const;
};

#endif // COMPUTERREPOSITORY_H
