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
    ComputerRepository c;
    return c.searchForComputer(modelName);
}

bool ComputerService::remove(ComputerModel model)
{
<<<<<<< HEAD
    ComputerRepository c;
    return c.removeComputer(model);
=======
    return true;
>>>>>>> ea2b2404611bc8ad9dce98c8279098f12970619a
}

