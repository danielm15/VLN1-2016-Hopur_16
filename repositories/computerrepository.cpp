#include "repositories/computerrepository.h"

ComputerRepository::ComputerRepository()
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "db.sqlite";
    _db.setDatabaseName(dbName);
    _db.open();
}

vector<ComputerModel> ComputerRepository::getAllComputers()
{
    QSqlQuery query(_db);
    vector<ComputerModel> computers;

    query.exec("SELECT * FROM Computers");

    while(query.next()){
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        int age = query.value("age").toUInt();
        // TODO: Push to vector
    }

    return computers;
}

vector<ComputerModel> ComputerRepository::searchForComputer(string name)
{
    vector<ComputerModel> computers;
    return computers;
}

bool ComputerRepository::addComputer()
{
    return true;
}
