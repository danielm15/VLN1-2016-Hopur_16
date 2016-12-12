#include "mainwindow.h"
#include <repositories/databasemanager.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DatabaseManager db;
    MainWindow w;
    w.show();

    return a.exec();
}
