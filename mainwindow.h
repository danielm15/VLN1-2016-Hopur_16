#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <services/geniusservice.h>
#include <services/computerservice.h>

#include <vector>

using namespace std;

#include "addgenius.h"
#include "addcomputer.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonAddGenius_clicked();

    void on_pushButtonAddComputer_clicked();

    void on_actionAddGenius_triggered();

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
