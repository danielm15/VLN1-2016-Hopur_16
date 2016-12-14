#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    displayAllGeniuses();
    displayAllComputers();
    displayGeniusDetails();
    displayComputerDetails();
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

void MainWindow::displayGeniusDetails()
{
    vector<GeniusModel> geniuses = _geniusService.getGenius();

    ui->geniusDetailsTable->clearContents();

    ui->geniusDetailsTable->setRowCount(geniuses.size());

    for(unsigned int row = 0; row < geniuses.size(); row++)
    {
        GeniusModel genius = geniuses.at(row);

        QString name = QString::fromStdString(genius.getName());
        QString gender = QString::fromStdString(genius.getGender());
        QString BirthYear = QString::number(genius.getBirthYear());
        QString DeathYear = QString::number(genius.getDeathYear());

        if(DeathYear == "0")
            DeathYear = "N/A";

        ui->geniusDetailsTable->setItem(row, 0, new QTableWidgetItem(name));
        ui->geniusDetailsTable->setItem(row, 1, new QTableWidgetItem(gender));
        ui->geniusDetailsTable->setItem(row, 2, new QTableWidgetItem(BirthYear));
        ui->geniusDetailsTable->setItem(row, 3, new QTableWidgetItem(DeathYear));
    }
}

void MainWindow::displayComputerDetails()
{
    vector<ComputerModel> computers = _computerService.getComputer();

    ui->computerDetailsTable->clearContents();

    ui->computerDetailsTable->setRowCount(computers.size());

    for(unsigned int row = 0; row < computers.size(); row++)
    {
        ComputerModel computer = computers.at(row);

        QString ModelName = QString::fromStdString(computer.getModelName());
        QString MakeYear = QString::number(computer.getMakeYear());
        QString type = QString::fromStdString(computer.getType());
        QString built = QString::number(computer.getBuilt());

        if(built == "0")
            built = "N";
        else
            built = "Y";

        ui->computerDetailsTable->setItem(row, 0, new QTableWidgetItem(ModelName));
        ui->computerDetailsTable->setItem(row, 1, new QTableWidgetItem(MakeYear));
        ui->computerDetailsTable->setItem(row, 2, new QTableWidgetItem(type));
        ui->computerDetailsTable->setItem(row, 3, new QTableWidgetItem(built));
    }
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

void MainWindow::on_listGeniuses_clicked(const QModelIndex &index)
{

}

void MainWindow::on_listComputers_clicked(const QModelIndex &index)
{

}
