#include "computergeniusservice.h"

ComputerGeniusService::ComputerGeniusService()
{

}

bool ComputerGeniusService::getRelationship(ComputerModel computer, GeniusModel genius)
{
    return _computerGeniusRepository.addRelationship(computer, genius);
}

bool ComputerGeniusService::removeRelationship(ComputerModel computer, GeniusModel genius)
{
    return _computerGeniusRepository.removeRelationship(computer, genius);
}


