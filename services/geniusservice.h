#ifndef GENIUSSERVICE_H
#define GENIUSSERVICE_H

#include "models/geniusmodel.h"
#include "repositories/geniusrepository.h"

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
    vector<GeniusModel> sort(bool ascending);

    /**
     * @brief find all geniuses that have name that matches name parameter
     * @param name
     * @return GeniusModel vector of all geniuses filtered by parameter
     */
    vector<GeniusModel> find(string name) const;

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

private:
    GeniusRepository _geniusRepository;

    /**
     * @brief Takes char of eather m or f and returns full gender name
     * @param gender
     * @return gender name
     */
    string getFullGenderName(char gender);
};

#endif // GENIUSSERVICE_H
