#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    displayAllGeniuses();
    displayAllComputers();

    connect(ui->listGeniuses, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(onListGeniusesItemClicked(QListWidgetItem*)));

    connect(ui->listComputers, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(onListComputersItemClicked(QListWidgetItem*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAllGeniuses()
{
    vector<GeniusModel> geniuses = _geniusService.getGenius();

    ui->listGeniuses->clear();

    for(unsigned int i = 0; i < geniuses.size(); i++)
    {
        GeniusModel genius = geniuses.at(i);
        ui->listGeniuses->addItem(QString::fromStdString(genius.getName()));
    }
}

void MainWindow::displayAllComputers()
{
    vector<ComputerModel> computers = _computerService.getComputer();

    ui->listComputers->clear();

    for(unsigned int i = 0; i < computers.size(); i++)
    {
        ComputerModel computer = computers.at(i);
        ui->listComputers->addItem(QString::fromStdString(computer.getModelName()));
    }
}

void MainWindow::onListGeniusesItemClicked(QListWidgetItem* item)
{

}

void MainWindow::onListComputersItemClicked(QListWidgetItem *item)
{

}

void MainWindow::on_pushButtonAddGenius_clicked()
{
   AddGenius geniusDialog;
   geniusDialog.exec();
}

void MainWindow::on_pushButtonAddComputer_clicked()
{
    AddComputer computerDialog;
    computerDialog.exec();
}
