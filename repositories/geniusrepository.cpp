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

    query.exec("SELECT * FROM Geniuses");

    geniuses = extractQueryToVector(query);

    return geniuses;
}

vector<GeniusModel> GeniusRepository::searchForGenius(string name)
{
    QSqlQuery query(_db);
    vector<GeniusModel> searchlist;

    //query.exec("SELECT * FROM Geniuses WHERE name LIKE %" + name + "%");

    searchlist = extractQueryToVector(query);

    return searchlist;
}

bool GeniusRepository::saveGenius(GeniusModel genius)
{
    QString Qname = QString::fromStdString(genius.getName());
    QString Qgender = QString::fromStdString(genius.getGender());
    unsigned int birthYear = genius.getBirthYear();
    unsigned int deathYear = genius.getDeathYear();

    QSqlQuery query(_db);
    query.prepare("INSERT INTO Geniuses(Name, Gender, BirthYear, DeathYear) VALUES(:Name,:Gender,:BirthYear,:DeathYear)");
    query.bindValue(":Name", Qname);
    query.bindValue(":Gender", Qgender);
    query.bindValue(":BirthYear", birthYear);
    query.bindValue(":DeathYear", deathYear);

    return query.exec();
}


vector<GeniusModel> GeniusRepository::extractQueryToVector(QSqlQuery query)
{
    vector<GeniusModel> geniuses;

    while(query.next()){
        string name = query.value("name").toString().toStdString();
        string gender = query.value("gender").toString().toStdString();
        unsigned int yearOfBirth = query.value("BirthYear").toUInt();
        unsigned int yearOfDeath = query.value("DeathYear").toUInt();

        geniuses.push_back(GeniusModel(name, gender, yearOfBirth, yearOfDeath));
    }

    return geniuses;
}
