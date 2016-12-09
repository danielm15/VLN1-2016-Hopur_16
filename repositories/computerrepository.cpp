#include "repositories/computerrepository.h"

ComputerRepository::ComputerRepository()
{
    _db = QSqlDatabase::database();
}

vector<ComputerModel> ComputerRepository::getAllComputers()
{
    // For some reason if I do not do this again here I get database connection error
    _db = QSqlDatabase::database();

    QSqlQuery query(_db);
    vector<ComputerModel> computers;

    query.exec("SELECT * FROM Computers");
    computers = extractQueryToVector(query);

    return computers;
}

vector<ComputerModel> ComputerRepository::searchForComputer(string name)
{
    // For some reason if I do not do this again here I get database connection error
    _db = QSqlDatabase::database();

    QSqlQuery query(_db);
    vector<ComputerModel> computers;

    string likeName = "%" + name + "%";

    query.prepare("SELECT * FROM Computers WHERE ModelName LIKE :name");
    query.bindValue(":name", QString::fromStdString(likeName));
    query.exec();

    computers = extractQueryToVector(query);

    return computers;
}

vector<ComputerModel> ComputerRepository::sort(string field, bool asc)
{
    // For some reason if I do not do this again here I get database connection error
    _db = QSqlDatabase::database();

    QSqlQuery query(_db);
    vector<ComputerModel> computers;
    string sortBy = "ASC";

    if (!asc)
    {
        sortBy = "DESC";
    }

    string queryString = ("SELECT * FROM Computers ORDER BY " + field + " " + sortBy + ", ModelName " + sortBy);
    query.exec(QString::fromStdString(queryString));

    computers = extractQueryToVector(query);

    return computers;
}

bool ComputerRepository::saveComputer(ComputerModel model)
{
    // For some reason if I do not do this again here I get database connection error
    _db = QSqlDatabase::database();

    QString QmodelName = QString::fromStdString(model.getModelName());
    QString Qtype = QString::fromStdString(model.getType());
    unsigned int makeYear = model.getMakeYear();
    bool built = model.getBuilt();

    QSqlQuery query(_db);
    query.prepare("INSERT INTO Computers(ModelName, MakeYear, Type, Built) VALUES(:ModelName,:MakeYear,:Type,:Built)");
    query.bindValue(":ModelName", QmodelName);
    query.bindValue(":MakeYear", makeYear);
    query.bindValue(":Type", Qtype);
    query.bindValue(":Built", built);

    return query.exec();
}

bool ComputerRepository::removeComputer(ComputerModel model)
{
    // For some reason if I do not do this again here I get database connection error
    _db = QSqlDatabase::database();

    QSqlQuery query(_db);
    query.prepare("DELETE FROM Computers WHERE id = :id");
    query.bindValue(":id", model.getId());

    return query.exec();
}

bool ComputerRepository::updateComputer(ComputerModel model)
{
    // For some reason if I do not do this again here I get database connection error
    _db = QSqlDatabase::database();

    QSqlQuery query(_db);

    query.prepare("UPDATE Computers \
                   SET ModelName = :modelName \
                   SET MakeYear  = :makeYear \
                   SET Type      = :type \
                   SET Built     = :built \
                   WHERE ComputerID = :id");

    query.bindValue(":modelName", QString::fromStdString(model.getModelName()));
    query.bindValue(":makeYear", model.getMakeYear());
    query.bindValue(":type", QString::fromStdString(model.getType()));
    query.bindValue(":built", model.getBuilt());
    query.bindValue(":id", model.getId());

    return query.exec();
}

vector<ComputerModel> ComputerRepository::extractQueryToVector(QSqlQuery query)
{
    vector<ComputerModel> computers;

    while(query.next()){
        bool built;
        unsigned int id = query.value("ComputerID").toUInt();
        string modelName = query.value("ModelName").toString().toStdString();
        unsigned int makeYear = query.value("MakeYear").toUInt();
        string type = query.value("Type").toString().toStdString();
        string builtStr = query.value("Built").toString().toStdString();

        if (builtStr == "Y")
        {
            built = true;
        }
        else
        {
            built = false;
        }

        computers.push_back(ComputerModel(id, modelName, makeYear, type, built));
    }

    return computers;
}

string ComputerRepository::toLowerCase(string s) const
{
    string lowercaseName = s;
    for (unsigned int i = 0; i < s.length(); i++)
    {
        lowercaseName[i] = tolower(lowercaseName[i]);
    }
    return lowercaseName;
}
