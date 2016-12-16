#include "repositories/databasemanager.h"

DatabaseManager::DatabaseManager()
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    if (!_db.isOpen())
    {
        QString dbName = "db.sqlite";

        _db.setDatabaseName(dbName);
        _db.open();
    }
}

void DatabaseManager::close()
{
    _db.close();
}
