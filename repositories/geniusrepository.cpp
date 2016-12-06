#include "repositories/geniusrepository.h"
#include <QString>

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
    GeniusModel g;
    vector<GeniusModel> filtered;
    vector<GeniusModel> searchlist = getAllGeniuses();

    string lowercaseName = toLowerCase(name);

    for(unsigned int i = 0; i < searchlist.size(); i++)
    {
        string geniusName = toLowerCase(searchlist[i].getName());

        // http://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c
        if (geniusName.find(lowercaseName) != std::string::npos)
        {
            filtered.push_back(searchlist[i]);
        }
    }

    return filtered;
}

vector<GeniusModel> GeniusRepository::sortByName(bool asc)
{
    QSqlQuery query(_db);
    vector<GeniusModel> geniuses;
    string sortBy = "ASC";

    if (!asc)
    {
        sortBy = "DESC";
    }

    string queryString = "SELECT * FROM Geniuses SORT BY name " + sortBy;

    query.exec(QString::fromStdString(queryString));

    geniuses = extractQueryToVector(query);

    return geniuses;
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

vector<GeniusModel> GeniusRepository::extractQueryToVector(QSqlQuery query) const
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

string GeniusRepository::toLowerCase(string s) const
{
    string lowercaseName = s;
    for (unsigned int i = 0; i < s.length(); i++)
    {
        lowercaseName[i] = tolower(lowercaseName[i]);
    }
    return lowercaseName;
}
