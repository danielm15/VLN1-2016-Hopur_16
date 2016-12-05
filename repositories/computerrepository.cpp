#include "repositories/computerrepository.h"

ComputerRepository::ComputerRepository()
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "db.sqlite";
    _db.setDatabaseName(dbName);
    _db.open();
}

ComputerRepository::~ComputerRepository()
{
    _db.close();
}

vector<ComputerModel> ComputerRepository::getAllComputers()
{
    QSqlQuery query(_db);
    vector<ComputerModel> computers;

    query.exec("SELECT * FROM Computers");

    computers = extractQueryToVector(query);

    return computers;
}

vector<ComputerModel> ComputerRepository::searchForComputer(string name)
{
    vector<ComputerModel> computers;
    QSqlQuery query(_db);


    computers = extractQueryToVector(query);

    return computers;
}

bool ComputerRepository::addComputer(ComputerModel model)
{
    return true;
}

vector<ComputerModel> ComputerRepository::extractQueryToVector(QSqlQuery query)
{
    vector<ComputerModel> computers;

    while(query.next()){
        unsigned int id = query.value("MakeYear").toUInt();
        string modelName = query.value("ModelName").toString().toStdString();
        unsigned int makeYear = query.value("MakeYear").toUInt();
        string type = query.value("Type").toString().toStdString();
        bool build = query.value("Build").toUInt();

        computers.push_back(ComputerModel(id, modelName, makeYear, type, build));
    }

    return computers;
}
