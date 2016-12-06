#include "computergeniusrepository.h"

ComputerGeniusRepository::ComputerGeniusRepository()
{
    _db = QSqlDatabase::database();
}

vector<ComputerModel> ComputerGeniusRepository::getGeniusesComputers(GeniusModel model)
{
    QSqlQuery query(_db);
    vector<ComputerModel> computers;

    query.prepare("SELECT ModelName, MakeYear, Type, Built FROM GC_Join as j \
               INNER JOIN Computers as c on c.ComputerID = j.ComputerID \
               WHERE GeniusID = :geniusID");
    query.bindValue(":geniusID", model.getId());
    computers = extractComputerQueryToVector(query);

    return computers;
}

vector<ComputerModel> ComputerGeniusRepository::extractComputerQueryToVector(QSqlQuery query) const
{
    vector<ComputerModel> computers;

    while(query.next()){
        unsigned int id = query.value("MakeYear").toUInt();
        string modelName = query.value("ModelName").toString().toStdString();
        unsigned int makeYear = query.value("MakeYear").toUInt();
        string type = query.value("Type").toString().toStdString();
        bool built = query.value("Built").toUInt();

        computers.push_back(ComputerModel(id, modelName, makeYear, type, built));
    }

    return computers;
}
