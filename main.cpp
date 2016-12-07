#include "ui/consoleui.h"
#include <repositories/databasemanager.h>

int main()
{
    DatabaseManager db;
    ConsoleUI ui;

    ui.run();

    return 0;
}
