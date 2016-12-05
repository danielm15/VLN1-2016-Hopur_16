#include "repositories/geniusrepository.h"

GeniusRepository::GeniusRepository()
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "db.sqlite";
    _db.setDatabaseName(dbName);
    _db.open();
}

vector<GeniusModel> GeniusRepository::getAllGeniuses()
{
    QSqlQuery query(_db);
    vector<GeniusModel> geniuses;

    query.exec("SELECT * FROM Computers");

    while(query.next()){
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        int age = query.value("age").toUInt();
        // TODO: Push to vector
    }

    return geniuses;
}

vector<GeniusModel> GeniusRepository::searchForGenius()
{
    vector<GeniusModel> searchlist;
    return searchlist;
}

bool GeniusRepository::addGenius()
{
    return true;
}
