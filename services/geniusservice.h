#ifndef GENIUSSERVICE_H
#define GENIUSSERVICE_H

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

private:
    GeniusRepository _geniusRepository;
>>>>>>> dd162a8004d41a2115d507a558cd95468bc12f61
};

#endif // GENIUSSERVICE_H
