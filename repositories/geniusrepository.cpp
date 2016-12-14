#include "repositories/geniusrepository.h"


GeniusRepository::GeniusRepository()
{
    _db = QSqlDatabase::database();
}

vector<GeniusModel> GeniusRepository::getAllGeniuses()
{
    // For some reason if I do not do this again here I get database connection error
    _db = QSqlDatabase::database();

    QSqlQuery query(_db);
    vector<GeniusModel> geniuses;

    query.exec("SELECT * FROM Geniuses");

    geniuses = extractQueryToVector(query);

    return geniuses;
}

vector<GeniusModel> GeniusRepository::searchForGenius(string name)
{
    // For some reason if I do not do this again here I get database connection error
    _db = QSqlDatabase::database();

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
    // For some reason if I do not do this again here I get database connection error
    _db = QSqlDatabase::database();

    QSqlQuery query(_db);
    vector<GeniusModel> geniuses;
    string sortBy = "ASC";

    if (!asc)
    {
        sortBy = "DESC";
    }
    string queryString = ("SELECT * FROM Geniuses ORDER BY " + field + " " + sortBy + ", Name " + sortBy);
    query.exec(QString::fromStdString(queryString));

    geniuses = extractQueryToVector(query);

    return geniuses;
}

bool GeniusRepository::saveGenius(GeniusModel genius)
{
    // For some reason if I do not do this again here I get database connection error
    _db = QSqlDatabase::database();

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
    // For some reason if I do not do this again here I get database connection error
    _db = QSqlDatabase::database();

    QSqlQuery query(_db);

    query.prepare("DELETE FROM Geniuses WHERE GeniusID = :id");
    query.bindValue(":id", model.getId());

    if (!query.exec())
        return false;

    // Cascade GC_Join
    query.prepare("DELETE FROM GC_Join WHERE GeniusID = :genius");
    query.bindValue(":genius", QString::number(model.getId()));
    query.exec();

    return true;
}

bool GeniusRepository::updateGenius(GeniusModel model)
{
    // For some reason if I do not do this again here I get database connection error
    _db = QSqlDatabase::database();

    QSqlQuery query(_db);

    query.prepare("UPDATE Geniuses \
                  SET Name         = :name, \
                  Gender       = :gender, \
                  BirthYear    = :birthYear, \
                  DeathYear    = :deathYear \
            WHERE GeniusID   = :id");

            query.bindValue(":name",      QString::fromStdString(model.getName()));
            query.bindValue(":gender",    QString::fromStdString(model.getGender()));
    query.bindValue(":birthYear", model.getBirthYear());
    query.bindValue(":deathYear", model.getDeathYear());
    query.bindValue(":id",        model.getId());

    return query.exec();
}

vector<GeniusModel> GeniusRepository::extractQueryToVector(QSqlQuery query) const
{
    vector<GeniusModel> geniuses;

    while(query.next()){
        unsigned int id = query.value("GeniusID").toUInt();
        string name = query.value("Name").toString().toStdString();
        string gender = query.value("Gender").toString().toStdString();
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
