#include "computergeniusrepository.h"

ComputerGeniusRepository::ComputerGeniusRepository()
{
    _db = QSqlDatabase::database();
}

bool ComputerGeniusRepository::addRelationship(ComputerModel computer, GeniusModel genius)
{
    // For some reason if I do not do this again here I get database connection error
    _db = QSqlDatabase::database();

    QSqlQuery query(_db);


    query.prepare("INSERT INTO GC_Join(GeniusID, ComputerID) VALUES(:genius, :computer)");
    query.bindValue(":genius", QString::number(genius.getId()));
    query.bindValue(":computer", QString::number(computer.getId()));

    return query.exec();
}

vector<ComputerModel> ComputerGeniusRepository::getGeniusComputers(GeniusModel model)
{
    // For some reason if I do not do this again here I get database connection error
    _db = QSqlDatabase::database();

    QSqlQuery query(_db);
    vector<ComputerModel> computers;

    query.prepare("SELECT ModelName, MakeYear, Type, Built FROM GC_Join as j \
               INNER JOIN Computers as c on c.ComputerID = j.ComputerID \
               WHERE GeniusID = :geniusID");
    query.bindValue(":geniusID", model.getId());
    query.exec();
    computers = extractComputerQueryToVector(query);

    return computers;
}

vector<GeniusModel> ComputerGeniusRepository::getComputerGeniuses(ComputerModel model)
{
    // For some reason if I do not do this again here I get database connection error
    _db = QSqlDatabase::database();

    QSqlQuery query(_db);
    vector<GeniusModel> geniuses;

    query.prepare("SELECT Name, Gender, BirthYear, DeathYear FROM GC_Join as j \
               INNER JOIN Geniuses as g on g.GeniusID = j.GeniusID \
               WHERE ComputerID = :computerID");
    query.bindValue(":computerID", model.getId());
    query.exec();

    geniuses = extractGeniusQueryToVector(query);

    return geniuses;
}

vector<ComputerModel> ComputerGeniusRepository::extractComputerQueryToVector(QSqlQuery query) const
{
    vector<ComputerModel> computers;

    while(query.next()){
        //unsigned int id = query.value("ComputerID").toUInt();
        string modelName = query.value("ModelName").toString().toStdString();
        unsigned int makeYear = query.value("MakeYear").toUInt();
        string type = query.value("Type").toString().toStdString();
        bool built = query.value("Built").toUInt();
        computers.push_back(ComputerModel(modelName, makeYear, type, built));
    }

    return computers;
}

vector<GeniusModel> ComputerGeniusRepository::extractGeniusQueryToVector(QSqlQuery query) const
{
    vector<GeniusModel> geniuses;

    while(query.next()){
        //unsigned int id = query.value("GeniusID").toUInt();
        string name = query.value("name").toString().toStdString();
        string gender = query.value("gender").toString().toStdString();
        unsigned int yearOfBirth = query.value("BirthYear").toUInt();
        unsigned int yearOfDeath = query.value("DeathYear").toUInt();
        GeniusModel model = GeniusModel(name, gender, yearOfBirth, yearOfDeath);
        geniuses.push_back(model);
    }

    return geniuses;
}
