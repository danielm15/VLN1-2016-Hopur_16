#include "computerservice.h"

ComputerService::ComputerService()
{

}

vector<ComputerModel> ComputerService::getComputer()
{
    ComputerRepository repo;
    return repo.getAllComputers();
}

bool ComputerService::addComputer(string modelName, unsigned int makeYear, string type, bool built)
{
    ComputerRepository c;
    ComputerModel model(modelName, makeYear, type, built);
    return c.saveComputer(model);
}

vector<ComputerModel> ComputerService::sort(bool ascending)
{
    ComputerRepository c;

    return c.sortByName(ascending);
}

vector<ComputerModel> ComputerService::find(string modelName) const
{
    vector<ComputerModel> filtered;

    ComputerRepository c;

    filtered = c.searchForComputer(modelName);

    return filtered;
}

bool ComputerService::remove(ComputerModel model)
{
    return true;
}

