#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H

#include "models/computermodel.h"
#include "models/geniusmodel.h"
#include "repositories/computerrepository.h"
#include "repositories/computergeniusrepository.h"


class ComputerService
{
public:
    ComputerService();

    /**
     * @brief getAll Gets all computers from the repository
     * @return
     */
    vector<ComputerModel> getComputer();

    /**
     * @brief sort Gets all computers and sorts them eather ascending or decending
     * @return ComputerModel vector of all geniuses sorted
     */
    vector<ComputerModel> sort(string column, bool ascending);

    /**
     * @brief sortOrder
     * @param sortBy
     * @return
     */
    bool sortOrder(string sortBy);

    /**
     * @brief sortComputer
     * @param sortedInput
     * @param sortBy
     * @return
     */
    vector<ComputerModel> sortComputer(string sortedInput, string sortBy);

    /**
     * @brief find all computers that have name that matches name parameter
     * @param name
     * @return GeniusModel vector of all geniuses filtered by parameter
     */
    vector<ComputerModel> find(string modelName);

    /**
     * @brief add new entry to the repository
     * @param id
     * @param modelName
     * @param makeYear
     * @param type
     * @param built
     * @return
     */
    bool addComputer(string modelName, unsigned int makeYear, string type, bool built);

    /**
     * @brief removes genius from the database
     * @param genius model that should be deleted
     * @return true if it was a success, else false
     */
    bool remove(ComputerModel genius);

    /**
     * @brief update, Calls the datalayer for a update of the model.
     * @param model
     * @return true if success, else false
     */
    bool update(ComputerModel model);

    /**
     * @brief getAllGeniusesWhoBuiltComputer, Returns from the datalayer all geniuses that built that computer
     * @param model
     * @return
     */
    vector<GeniusModel> getAllGeniusesWhoBuiltComputer(ComputerModel model);

private:
    ComputerRepository _computerRepository;
    ComputerGeniusRepository _computerGeniusRepository;
};

#endif // COMPUTERSERVICE_H
