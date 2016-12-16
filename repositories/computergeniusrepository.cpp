#include "computergeniusrepository.h"
#include <QDebug>

ComputerGeniusRepository::ComputerGeniusRepository()
{
    _db = QSqlDatabase::database();
}

/**
 * @brief ComputerGeniusRepository::addRelationship Addes new row to GC_Join table if it does not already exists
 * @param computer
 * @param genius
 * @return boolean value from the query
 */
bool ComputerGeniusRepository::addRelationship(ComputerModel computer, GeniusModel genius)
{
    // Return early if models are already linked together
    if (checkIfComputerAndGeniusAreAlreadyLinked(computer, genius))
    {
        return false;
    }

    // For some reason if I do not do this again here I get database connection error
    _db = QSqlDatabase::database();

    QSqlQuery query(_db);

    query.prepare("INSERT INTO GC_Join(GeniusID, ComputerID) VALUES(:genius, :computer)");
    query.bindValue(":genius", QString::number(genius.getId()));
    query.bindValue(":computer", QString::number(computer.getId()));

    return query.exec();
}

/**
 * @brief ComputerGeniusRepository::removeRelationship, Removes relationship from GC_Join, if it exists.
 * @param computer
 * @param genius
 * @return boolean return value from the query.
 */
bool ComputerGeniusRepository::removeRelationship(ComputerModel computer, GeniusModel genius)
{
    if (!checkIfComputerAndGeniusAreAlreadyLinked(computer, genius))
        return false;
    // For some reason if I do not do this again here I get database connection error
    _db = QSqlDatabase::database();

    QSqlQuery query(_db);

    query.prepare("DELETE FROM GC_Join \
                  WHERE ComputerID = :computer and GeniusID = :genius");
    query.bindValue(":genius", QString::number(genius.getId()));
    query.bindValue(":computer", QString::number(computer.getId()));

    return query.exec();
}

/**
 * @brief ComputerGeniusRepository::getGeniusComputers Returns all Computers that were built by genius
 * @param model
 * @return vector of computers
 */
vector<ComputerModel> ComputerGeniusRepository::getGeniusComputers(GeniusModel model)
{
    // For some reason if I do not do this again here I get database connection error
    _db = QSqlDatabase::database();

    QSqlQuery query(_db);
    vector<ComputerModel> computers;

    query.prepare("SELECT c.ComputerID, c.ModelName, c.MakeYear, c.Type, c.Built FROM GC_Join as j \
                  INNER JOIN Computers as c on c.ComputerID = j.ComputerID \
            WHERE GeniusID = :geniusID");
            query.bindValue(":geniusID", model.getId());
            query.exec();
    computers = extractComputerQueryToVector(query);

    return computers;
}

/**
 * @brief ComputerGeniusRepository::getComputerGeniuses, Fetches all Geniuses that built computer from the database
 * @param model
 * @return vector of geniuses
 */
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

/**
 * @brief ComputerGeniusRepository::extractComputerQueryToVector, Transforms query to model objects
 * @param query
 * @return vector of computers
 */
vector<ComputerModel> ComputerGeniusRepository::extractComputerQueryToVector(QSqlQuery query) const
{
    vector<ComputerModel> computers;

    while(query.next()){
        unsigned int id = query.value("ComputerID").toUInt();
        string modelName = query.value("ModelName").toString().toStdString();
        unsigned int makeYear = query.value("MakeYear").toUInt();
        string type = query.value("Type").toString().toStdString();
        int built = query.value("Built").toUInt();
        computers.push_back(ComputerModel(id, modelName, makeYear, type, built));
    }

    return computers;
}

/**
 * @brief ComputerGeniusRepository::extractGeniusQueryToVector, Transforms query to model objects
 * @param query
 * @return vector of geniuses
 */
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

/**
 * @brief ComputerGeniusRepository::checkIfComputerAndGeniusAreAlreadyLinked
 *        Check's if computer and genius have already been linked together.
 * @param computer
 * @param genius
 * @return true if computer and genius are linked, else false.
 */
bool ComputerGeniusRepository::checkIfComputerAndGeniusAreAlreadyLinked(ComputerModel computer, GeniusModel genius)
{
    // For some reason if I do not do this again here I get database connection error
    _db = QSqlDatabase::database();

    QSqlQuery query(_db);

    query.prepare("SELECT * FROM GC_Join \
                   WHERE ComputerID = :computerID and GeniusID = :geniusID");

    query.bindValue(":computerID", QString::number(computer.getId()));
    query.bindValue(":geniusID", QString::number(genius.getId()));

    query.exec();

    if (query.next())
        return true; // They are linked

    return false; // They are not linked
}
