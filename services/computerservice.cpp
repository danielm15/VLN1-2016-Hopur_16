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
    ComputerModel model(modelName, makeYear, type, built);
    return _computerRepository.saveComputer(model);
}

vector<ComputerModel> ComputerService::sort(string column, bool ascending)
{
    return _computerRepository.sort(column, ascending);
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

vector<ComputerModel> ComputerService::find(string modelName)
{
    return _computerRepository.searchForComputer(modelName);
}

bool ComputerService::remove(ComputerModel model)
{
    return _computerRepository.removeComputer(model);
}

bool ComputerService::update(ComputerModel model)
{
    return _computerRepository.updateComputer(model);
}

