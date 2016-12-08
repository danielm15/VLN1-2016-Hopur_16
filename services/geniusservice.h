#ifndef GENIUSSERVICE_H
#define GENIUSSERVICE_H

#include "models/computermodel.h"
#include "models/geniusmodel.h"
#include "repositories/geniusrepository.h"
#include "repositories/computergeniusrepository.h"

#include <string>


class GeniusService
{
public:
    GeniusService();

    /**
     * @brief getAll Gets all Geniuses from the repository
     * @return
     */
    vector<GeniusModel> getGenius();

    /**
     * @brief sort Gets all Geniuses and sorts them eather ascending or decending
     * @return GeniuseModel vector of all geniuses sorted
     */
    vector<GeniusModel> sort(string column, bool ascending);

    /**
     * @brief sortOrder
     * @param sortBy
     * @return
     */
    bool sortOrder(string sortBy);

    /**
     * @brief sortGenius Uses sort() to sort Geniuses according to the selected column name
     * @param sortedInput
     * @return
     */
    vector<GeniusModel> sortGenius(string sortedInput, string sortBy);

    /**
     * @brief sortComputer Uses sort() to sort Computers according to the selected column name
     * @param sortedInput
     * @return
     */
    vector<GeniusModel> sortComputer(string sortedInput);

    /**
     * @brief find all geniuses that have name that matches name parameter
     * @param name
     * @return GeniusModel vector of all geniuses filtered by parameter
     */
    vector<GeniusModel> find(string name);

    /**
     * @brief add new entry to the database
     * @param name
     * @param gender
     * @param date_of_birth
     * @param date_of_death
     * @return true if it was a success, else false
     */
    bool addGenius(string name, char gender, unsigned int dateOfBirth, unsigned int dateOfDeath);

    /**
     * @brief removes genius from the database
     * @param genius model that should be deleted
     * @return true if it was a success, else false
     */
    bool remove(GeniusModel genius);

    /**
     * @brief update, Calls the datalayer for a update of the model.
     * @param model
     * @return true if success, else false
     */
    bool update(GeniusModel model);

    /**
     * @brief getAllComputersGeniusBuilt Returns all compuers genius has built
     * @param model
     * @return vector of computers
     */
    vector<ComputerModel> getAllComputersGeniusBuilt(GeniusModel model);

private:
    GeniusRepository _geniusRepository;
    ComputerGeniusRepository _computerGeniusRepository;


    /**
     * @brief Takes char of eather m or f and returns full gender name
     * @param gender
     * @return gender name
     */
    string getFullGenderName(char gender);
};

#endif // GENIUSSERVICE_H
