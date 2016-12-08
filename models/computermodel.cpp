#include "computermodel.h"

ComputerModel::ComputerModel()
{

}

ComputerModel::ComputerModel(string modelName, unsigned int makeYear, string type, bool built)
{
    _modelName = modelName;
    _makeYear = makeYear;
    _type = type;
    _built = built;
}

ComputerModel::ComputerModel(unsigned int id, string modelName, unsigned int makeYear, string type, bool built)
{
    _id = id;
    _modelName = modelName;
    _makeYear = makeYear;
    _type = type;
    _built = built;
}

unsigned int ComputerModel::getId() const
{
    return _id;
}

string ComputerModel::getModelName() const
{
    return _modelName;
}

unsigned int ComputerModel::getMakeYear() const
{
    return _makeYear;
}

string ComputerModel::getType() const
{
    return _type;
}

bool ComputerModel::getBuilt() const
{
    return _built;
}

bool operator ==(const ComputerModel& g1, const ComputerModel& g2)
{
    if (g1._id != g2._id)
        return false;
    if (g1._modelName != g2._modelName)
        return false;
    if (g1._makeYear != g2._makeYear)
        return false;
    if (g1._type != g2._type)
        return false;
    if (g1._built != g2._built)
        return false;

    return true;
}

ostream& operator <<(ostream& out, const ComputerModel& p1)
{
    out << "|" <<setw(25) << p1.getModelName() << " | ";
    out << setw(9) << p1.getMakeYear() << " | ";
    out << setw(20) << p1.getType() << " | ";

    if(p1.getBuilt() == true)
        out << setw(5) << "Y" << setw(5) << "  |";
    else
        out << setw(5) << "N" << setw(5) << "  |";

    return out;
}
