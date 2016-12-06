#include "ui/consoleui.h"
#include "databasemanager.h"

int main()
{
    DatabaseManager db;
    ConsoleUI ui;

    ui.run();

    return 0;
}
