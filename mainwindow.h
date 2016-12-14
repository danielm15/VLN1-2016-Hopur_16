#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
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

    void on_actionAddComputer_triggered();

    void on_lineEditComputerFilter_textChanged(const QString &arg1);

    void on_lineEditGeniusFilter_textChanged(const QString &arg1);

    void on_listGeniuses_clicked(const QModelIndex &index);

    void on_listComputers_clicked(const QModelIndex &index);

    void on_pushButtonDeleteComputer_clicked();

private:
    Ui::MainWindow *ui;

    void displayAllGeniuses();
    void displayGeniuses(vector<GeniusModel> geniuses);
    void displayAllComputers();
    void displayComputers(vector<ComputerModel> computers);
    void displayGeniusDetails();
    void displayComputerDetails();

    GeniusService _geniusService;
    ComputerService _computerService;
};

#endif // MAINWINDOW_H
