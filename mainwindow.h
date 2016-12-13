#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <services/geniusservice.h>
#include <services/computerservice.h>

#include <vector>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void displayAllGeniuses();
    void displayGeniuses(vector<GeniusModel> geniuses);
    void displayAllComputers();
    void displayComputers(vector<ComputerModel> computers);
    GeniusService _geniusService;
    ComputerService _computerService;
};

#endif // MAINWINDOW_H
