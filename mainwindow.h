#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <services/geniusservice.h>
#include <services/computerservice.h>
#include <QMouseEvent>
#include <QTableWidgetItem>

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

    void on_actionAddComputer_triggered();

    void on_lineEditComputerFilter_textChanged(const QString &arg1);

    void on_lineEditGeniusFilter_textChanged(const QString &arg1);

    void on_listGeniuses_clicked();

    void on_listComputers_clicked();

    void on_clearGeniusSelection_clicked();

    void on_clearComputerSelection_clicked();

    void on_geniusDetailsTable_cellChanged(int row, int column);

    void on_pushButtonDeleteGenius_clicked();

    void on_pushButtonDeleteComputer_clicked();

    void on_computerDetailsTable_itemChanged(QTableWidgetItem *item);

private:
    Ui::MainWindow *ui;

    void displayAllGeniuses();
    void displayGeniuses(vector<GeniusModel> geniuses);
    void displayAllComputers();
    void displayComputers(vector<ComputerModel> computers);
    void displayAllGeniusDetails();
    void displayGeniusDetails(vector<GeniusModel> geniuses);
    void displayAllComputerDetails();
    void displayComputerDetails(vector<ComputerModel> computers);
    bool checkIfYearIsValid(QString year);

    GeniusService _geniusService;
    ComputerService _computerService;

    vector<GeniusModel> currentlyDisplayedGeniuses;
    vector<GeniusModel> currentlyDisplayedGeniusDetails;
    vector<ComputerModel> currentlyDisplayedComputers;
    vector<ComputerModel> currentlyDisplayedComputerDetails;
};

#endif // MAINWINDOW_H
