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
    displayGeniuses(geniuses);
}

void MainWindow::displayGeniuses(vector<GeniusModel> geniuses)
{
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
    displayComputers(computers);
}

void MainWindow::displayComputers(vector<ComputerModel> computers)
{
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
   int returnValueFromAddGenius = geniusDialog.exec();
   if (returnValueFromAddGenius == 1)
       ui->statusBar->showMessage("Successfully added new genius", 2000);
}

void MainWindow::on_pushButtonAddComputer_clicked()
{
    AddComputer computerDialog;
    int returnValueFromAddComputer = computerDialog.exec();
    if (returnValueFromAddComputer == 1)
        ui->statusBar->showMessage("Successfully added new computer", 2000);
}

void MainWindow::on_actionAddGenius_triggered()
{
    on_pushButtonAddGenius_clicked();
}

void MainWindow::on_actionAddComputer_triggered()
{
    on_pushButtonAddComputer_clicked();
}

void MainWindow::on_lineEditComputerFilter_textChanged(const QString &arg1)
{
    string input = ui->lineEditComputerFilter->text().toStdString();

    vector<ComputerModel> computers = _computerService.find(input);
    displayComputers(computers);
}

void MainWindow::on_lineEditGeniusFilter_textChanged(const QString &arg1)
{
    string input = ui->lineEditGeniusFilter->text().toStdString();

    vector<GeniusModel> geniuses = _geniusService.find(input);
    displayGeniuses(geniuses);
}
