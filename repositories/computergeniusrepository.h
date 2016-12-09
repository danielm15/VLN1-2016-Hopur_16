#ifndef COMPUTERGENIUSREPOSITORY_H
#define COMPUTERGENIUSREPOSITORY_H

#include "repositories/computergeniusrepository.h"
#include "repositories/computerrepository.h"
#include "repositories/geniusrepository.h"
#include "models/computermodel.h"
#include "models/geniusmodel.h"

#include <vector>
#include <QtSql>

using namespace std;

class ComputerGeniusRepository
{
public:
    ComputerGeniusRepository();

    /**
     * @brief getGeniuseComputers, Fetches all computers genius has worked on
     * @param model
     * @return vector of computers
     */
    vector<ComputerModel> getGeniusComputers(GeniusModel model);

    /**
     * @brief getComputerGeniuses, fetch all geniuses thata have worked on computer model
     * @param model that should fetch by
     * @return vector of geniuses
     */
    vector<GeniusModel> getComputerGeniuses(ComputerModel model);

    /**
     * @brief addRelationship, adds a new relationship between genius and computer
     * @param computer
     * @param genius
     * @return bool if success, else false
     */
    bool addRelationship(ComputerModel computer, GeniusModel genius);

private:
    QSqlDatabase _db;

    vector<ComputerModel> extractComputerQueryToVector(QSqlQuery query) const;
    vector<GeniusModel> extractGeniusQueryToVector(QSqlQuery query) const;
};

#endif // COMPUTERGENIUSREPOSITORY_H
