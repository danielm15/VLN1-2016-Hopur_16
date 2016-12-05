#include "computermodel.h"

ComputerModel::ComputerModel()
{

}

ComputerModel::ComputerModel(unsigned int id, string modelName, unsigned int makeYear, string type, bool build)
{
    _id = id;
    _modelName = modelName;
    _makeYear = makeYear;
    _type = type;
    _build = build;
}

unsigned int ComputerModel::getId()
{
    return _id;
}

string ComputerModel::getModelName()
{
    return _modelName;
}

unsigned int ComputerModel::getMakeYear()
{
    return _makeYear;
}

string ComputerModel::getType()
{
    return _type;
}

bool ComputerModel::getBuild()
{
    return _build;
}
