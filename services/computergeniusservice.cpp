#include "computergeniusservice.h"

ComputerGeniusService::ComputerGeniusService()
{

}

bool ComputerGeniusService::getRelationship(ComputerModel computer, GeniusModel genius)
{
    return _computerGeniusRepository.addRelationship(computer, genius);
}
