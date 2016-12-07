#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql>

class DatabaseManager
{
public:
    DatabaseManager();
private:
    QSqlDatabase _db;
    void close();
};

#endif // DATABASEMANAGER_H
