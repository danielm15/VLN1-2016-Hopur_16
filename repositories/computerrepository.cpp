#include "repositories/computerrepository.h"

ComputerRepository::ComputerRepository()
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "db.sqlite";
    _db.setDatabaseName(dbName);
    _db.open();
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

<<<<<<< HEAD
    // Search kóði TODO
=======
    string lowercaseName = toLowerCase(name);
>>>>>>> dd162a8004d41a2115d507a558cd95468bc12f61

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

bool ComputerRepository::addComputer(ComputerModel model)
{
    return true;
}

vector<ComputerModel> ComputerRepository::extractQueryToVector(QSqlQuery query)
{
    vector<ComputerModel> computers;

    while(query.next()){
        unsigned int id = query.value("MakeYear").toUInt();
        string modelName = query.value("ModelName").toString().toStdString();
        unsigned int makeYear = query.value("MakeYear").toUInt();
        string type = query.value("Type").toString().toStdString();
        bool build = query.value("Build").toUInt();

        computers.push_back(ComputerModel(id, modelName, makeYear, type, build));
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
