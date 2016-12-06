#include "repositories/computerrepository.h"

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
    ComputerModel g;
    vector<ComputerModel> filtered;
    vector<ComputerModel> computers = getAllComputers();

    string lowercaseName = toLowerCase(name);

    for(unsigned int i = 0; i < computers.size(); i++)
    {
        string geniusName = toLowerCase(computers[i].getModelName());

        // http://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c
        if (geniusName.find(lowercaseName) != std::string::npos)
        {
            filtered.push_back(computers[i]);
        }
    }

    return filtered;
}

vector<ComputerModel> ComputerRepository::sortByName(bool asc)
{
    QSqlQuery query(_db);
    vector<ComputerModel> computers;
    string sortBy = "ASC";

    if (!asc)
    {
        sortBy = "DESC";
    }

    string queryString = "SELECT * FROM Computers SORT BY name " + sortBy;

    query.exec(QString::fromStdString(queryString));

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
        unsigned int id = query.value("MakeYear").toUInt();
        string modelName = query.value("ModelName").toString().toStdString();
        unsigned int makeYear = query.value("MakeYear").toUInt();
        string type = query.value("Type").toString().toStdString();
        bool built = query.value("Built").toUInt();

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
