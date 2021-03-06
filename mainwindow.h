#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QListWidget>
#include <QMouseEvent>
#include <QItemSelectionModel>
#include <QTableWidgetItem>
#include <services/geniusservice.h>
#include <services/computerservice.h>
#include <edithcpdialog.h>
#include "editcomputer.h"
#include <services/computergeniusservice.h>

#include <vector>

using namespace std;

#include "addgenius.h"
#include "addcomputer.h"
#include "editrelation.h"
#include "editrelationcg.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void displayAllRelationsGC();

    void displayAllRelationsCG();

private slots:
    void on_pushButtonAddGenius_clicked();

    void on_pushButtonAddComputer_clicked();

    void on_actionAddGenius_triggered();

    void on_actionAddComputer_triggered();

    void on_lineEditComputerFilter_textChanged();

    void on_lineEditGeniusFilter_textChanged();

    void on_listGeniuses_clicked();

    void on_listComputers_clicked();

    void on_clearGeniusSelection_clicked();

    void on_clearComputerSelection_clicked();

    void on_listGeniuses_doubleClicked();

    void on_listComputers_doubleClicked();

    //void on_geniusDetailsTable_cellChanged(int row, int column);

    void on_pushButtonDeleteGenius_clicked();

    void on_pushButtonDeleteComputer_clicked();

    //void on_computerDetailsTable_itemChanged(QTableWidgetItem *item);

    void on_pushButtonEditRelationGC_clicked();

    void on_pushButtonEditRelationCG_clicked();

    void on_geniusComputerRelationWidget_itemClicked(QTreeWidgetItem *item);

    void on_computerGeniusRelationWidget_itemClicked(QTreeWidgetItem *item);

    void on_editButtonGenius_clicked();

    void on_editbuttoncomputer_clicked();

    void on_geniusDetails_tabBarClicked();

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

    void displayRelationsGC(vector<GeniusModel> geniuses);
    void displayRelationsCG(vector<ComputerModel> computers);
    bool checkIfYearIsValid(QString year);

    GeniusService _geniusService;
    ComputerService _computerService;

    vector<GeniusModel> currentlyDisplayedGeniuses;
    vector<GeniusModel> currentlyDisplayedGeniusDetails;
    vector<GeniusModel> currentlyDisplayedGeniusRelations;
    vector<ComputerModel> currentlyDisplayedComputers;
    vector<ComputerModel> currentlyDisplayedComputerDetails;
    vector<ComputerModel> currentlyDisplayedComputerRelations;
};

#endif // MAINWINDOW_H
