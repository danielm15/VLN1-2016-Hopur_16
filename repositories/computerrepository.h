#ifndef COMPUTERREPOSITORY_H
#define COMPUTERREPOSITORY_H

#include <vector>
#include <string>

#include "models/computermodel.h"

using namespace std;

class ComputerRepository
{
public:
    ComputerRepository();
    std::vector<ComputerModel> getAllComputers();
    std::vector<ComputerModel> searchForComputer(string name);
    bool addComputer();
};

#endif // COMPUTERREPOSITORY_H
