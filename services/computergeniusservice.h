#ifndef COMPUTERGENIUSSERVICE_H
#define COMPUTERGENIUSSERVICE_H

#include "models/computermodel.h"
#include "models/geniusmodel.h"

#include "repositories/computergeniusrepository.h"

class ComputerGeniusService
{
public:
    ComputerGeniusService();
    bool getRelationship(ComputerModel computer, GeniusModel genius);
    bool removeRelationship(ComputerModel computer, GeniusModel genius);
private:
    ComputerGeniusRepository _computerGeniusRepository;
};

#endif // COMPUTERGENIUSSERVICE_H
