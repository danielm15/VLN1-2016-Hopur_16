#ifndef COMPUTERREPOSITORY_H
#define COMPUTERREPOSITORY_H

#include <QtSql>

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

private:
    QSqlDatabase _db;
};

#endif // COMPUTERREPOSITORY_H
