#include "repositories/databasemanager.h"

DatabaseManager::DatabaseManager()
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    if (!_db.isOpen())
    {
        QString dbName = "/Users/siggigunn/Documents/HR/gitveislan/build-GeniusList-Desktop_Qt_5_7_0_clang_64bit-Debug/db.sqlite";
        //QString dbName = "db.sqlite";
        _db.setDatabaseName(dbName);
        _db.open();
    }
}

void DatabaseManager::close()
{
    _db.close();
}
