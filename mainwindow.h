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

    void onListGeniusesItemClicked(QListWidgetItem* item);
    void onListComputersItemClicked(QListWidgetItem* item);

private:
    Ui::MainWindow *ui;

    void displayAllGeniuses();
    void displayAllComputers();


    GeniusService _geniusService;
    ComputerService _computerService;
};

#endif // MAINWINDOW_H
