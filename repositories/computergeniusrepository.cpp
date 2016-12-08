#include "computergeniusrepository.h"

ComputerGeniusRepository::ComputerGeniusRepository()
{
    _db = QSqlDatabase::database();
}

vector<ComputerModel> ComputerGeniusRepository::getGeniuseComputers(GeniusModel model)
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

vector<GeniusModel> ComputerGeniusRepository::getComputerGeniuses(ComputerModel model)
{
    QSqlQuery query(_db);
    vector<GeniusModel> geniuses;

    query.prepare("SELECT Name, Gender, BirthYear, DeathYear FROM GC_Join as j \
               INNER JOIN Geniuses as g on g.GeniusID = j.GeniusId \
               WHERE ComputerID = :computerID");
    query.bindValue(":computerID", model.getId());
    geniuses = extractGeniusQueryToVector(query);

    return geniuses;
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

vector<GeniusModel> ComputerGeniusRepository::extractGeniusQueryToVector(QSqlQuery query) const
{
    vector<GeniusModel> geniuses;

    while(query.next()){
        string name = query.value("name").toString().toStdString();
        string gender = query.value("gender").toString().toStdString();
        unsigned int yearOfBirth = query.value("BirthYear").toUInt();
        unsigned int yearOfDeath = query.value("DeathYear").toUInt();
        GeniusModel model = GeniusModel(name, gender, yearOfBirth, yearOfDeath);
        geniuses.push_back(model);
    }

    return geniuses;
}
