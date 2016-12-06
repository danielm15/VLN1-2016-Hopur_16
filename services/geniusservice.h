#ifndef GENIUSSERVICE_H
#define GENIUSSERVICE_H

#include "models/geniusmodel.h"
#include "repositories/geniusrepository.h"
<<<<<<< HEAD

#include <string>
=======
>>>>>>> dd162a8004d41a2115d507a558cd95468bc12f61

class GeniusService
{
public:
    GeniusService();
<<<<<<< HEAD
    vector<GeniusModel> getGenius();
    bool addGenius(string name, char gender, unsigned int dateOfBirth, unsigned int dateOfDeath);
    string getFullGenderName(char gender);

=======

    /**
     * @brief getAll Gets all Geniuses from the repository
     * @return
     */
    vector<GeniusModel> getAll();

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
    bool add(string name, char gender, unsigned int dateOfBirth, unsigned int dateOfDeath);

    /**
     * @brief removes genius from the database
     * @param genius model that should be deleted
     * @return true if it was a success, else false
     */
    bool remove(GeniusModel genius);

private:
    GeniusRepository _geniusRepository;
<<<<<<< HEAD
>>>>>>> dd162a8004d41a2115d507a558cd95468bc12f61
=======

    /**
     * @brief Takes char of eather m or f and returns full gender name
     * @param gender
     * @return gender name
     */
    string getFullGenderName(char gender);
>>>>>>> 8f4df392ccd7de6dea20dd4e745293b50de49446
};

#endif // GENIUSSERVICE_H
