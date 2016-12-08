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

vector<ComputerModel> ComputerService::sort(string column, bool ascending)
{
    ComputerRepository c;
    return c.sort(column, ascending);
}

bool ComputerService::sortOrder(string sortBy)
{
    bool ascending = true;

    if (sortBy == "D" || sortBy == "d")
        ascending = false;
    else if (sortBy == "A" || sortBy == "a")
        ascending = true;

    return ascending;
}

vector<ComputerModel> ComputerService::sortComputer(string sortedInput, string sortBy)
{
    string column;
    bool asc;

    if(sortedInput == "a" || sortedInput == "A")
    {
        column = "ModelName";
    }
    else if(sortedInput == "b" || sortedInput == "B")
    {
        column = "MakeYear";
    }
    else if(sortedInput == "c" || sortedInput == "C")
    {
        column = "Type";
    }
    else if(sortedInput == "d" || sortedInput == "D")
    {
        column = "Built";
    }
    asc = sortOrder(sortBy);

    return sort(column, asc);
}

vector<ComputerModel> ComputerService::find(string modelName) const
{
    ComputerRepository c;
    return c.searchForComputer(modelName);
}

bool ComputerService::remove(ComputerModel model)
{
    ComputerRepository c;
    return c.removeComputer(model);
}

bool ComputerService::update(ComputerModel model)
{
    return _computerRepository.updateComputer(model);
}

