#include "repositories/computerrepository.h"
#include "repositories/computergeniusrepository.h"

ComputerRepository::ComputerRepository()
{
    _db = QSqlDatabase::database();
}

vector<ComputerModel> ComputerRepository::getAllComputers()
{
    QSqlQuery query(_db);
    vector<ComputerModel> computers;

    query.exec("SELECT * FROM Computers");
    computers = extractQueryToVector(query);

    return computers;
}

vector<ComputerModel> ComputerRepository::searchForComputer(string name)
{
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
    QSqlQuery query(_db);
    vector<ComputerModel> computers;
    string sortBy = "ASC";

    if (!asc)
    {
        sortBy = "DESC";
    }

    string queryString = "SELECT * FROM Computers ORDER BY :name " + sortBy;

    query.prepare(QString::fromStdString(queryString));
    query.bindValue(":name", QString::fromStdString(field));
    query.exec();

    computers = extractQueryToVector(query);

    return computers;
}

bool ComputerRepository::saveComputer(ComputerModel model)
{
    QString QmodelName = QString::fromStdString(model.getModelName());
    QString Qtype = QString::fromStdString(model.getType());
    unsigned int makeYear = model.getMakeYear();
    bool built = model.getBuilt();

    QSqlQuery query(_db);
    query.prepare("INSERT INTO Computers(ModelName, MakeYear, Type, Built) VALUES(:ModelName,:MakeYear,:Type,:Built)");
    query.bindValue(":ModelName", QmodelName);
    query.bindValue(":MakeYear", Qtype);
    query.bindValue(":Type", makeYear);
    query.bindValue(":Built", built);

    return query.exec();
}

bool ComputerRepository::removeComputer(ComputerModel model)
{
    QSqlQuery query(_db);
    query.prepare("DELETE FROM Computers WHERE id = :id");
    query.bindValue(":id", model.getId());

    return query.exec();
}

vector<ComputerModel> ComputerRepository::extractQueryToVector(QSqlQuery query)
{
    vector<ComputerModel> computers;

    while(query.next()){
        bool built;
        unsigned int id = query.value("MakeYear").toUInt();
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
