#include "repositories/geniusrepository.h"
#include <QString>

GeniusRepository::GeniusRepository()
{
    _db = QSqlDatabase::database();
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
    vector<GeniusModel> geniuses;

    string likeName = "%" + name + "%";

    query.prepare("SELECT * FROM Geniuses WHERE name LIKE :name");
    query.bindValue(":name", QString::fromStdString(likeName));
    query.exec();

    geniuses = extractQueryToVector(query);

    return geniuses;
}

vector<GeniusModel> GeniusRepository::sort(string field, bool asc)
{
    cout << field << endl;
    cout << asc << endl;
    QSqlQuery query(_db);
    vector<GeniusModel> geniuses;
    string sortBy = "ASC";

    if (!asc)
    {
        sortBy = "DESC";
    }
    string queryString = ("SELECT * FROM Geniuses ORDER BY " + field + " " + sortBy);
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
    if(deathYear == 0)
    {
        query.bindValue(":DeathYear", QVariant(QVariant::Int));
    }
    else
    {
        query.bindValue(":DeathYear", deathYear);
    }

    return query.exec();
}

bool GeniusRepository::removeGenius(GeniusModel model)
{
    QSqlQuery query(_db);

    query.prepare("DELETE FROM Geniuses WHERE GeniusID = :id");
    query.bindValue(":id", model.getId());

    return query.exec();
}

vector<GeniusModel> GeniusRepository::extractQueryToVector(QSqlQuery query) const
{
    vector<GeniusModel> geniuses;

    while(query.next()){
        unsigned int id = query.value("GeniusID").toUInt();
        string name = query.value("name").toString().toStdString();
        string gender = query.value("gender").toString().toStdString();
        unsigned int yearOfBirth = query.value("BirthYear").toUInt();
        unsigned int yearOfDeath = query.value("DeathYear").toUInt();
        GeniusModel model = GeniusModel(id, name, gender, yearOfBirth, yearOfDeath);
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
