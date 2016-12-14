#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    displayAllGeniuses();
    displayAllComputers();
    displayAllGeniusDetails();
    displayAllComputerDetails();
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

    currentlyDisplayedGeniuses = geniuses;
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

    currentlyDisplayedComputers = computers;

}

void MainWindow::displayAllGeniusDetails()
{
   vector<GeniusModel> geniuses = _geniusService.getGenius();
   displayGeniusDetails(geniuses);
}

void MainWindow::displayGeniusDetails(vector<GeniusModel> geniuses)
{
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

    currentlyDisplayedGeniuses = geniuses;
}

void MainWindow::displayAllComputerDetails()
{
    vector<ComputerModel> computers = _computerService.getComputer();
    displayComputerDetails(computers);
}

void MainWindow::displayComputerDetails(vector<ComputerModel> computers)
{
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

    currentlyDisplayedComputers = computers;
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

    currentlyDisplayedComputers = _computerService.find(input);
    displayComputers(currentlyDisplayedComputers);
    displayComputerDetails(currentlyDisplayedComputers);
}

void MainWindow::on_lineEditGeniusFilter_textChanged(const QString &arg1)
{
    string input = ui->lineEditGeniusFilter->text().toStdString();

    currentlyDisplayedGeniuses = _geniusService.find(input);
    displayGeniuses(currentlyDisplayedGeniuses);
    displayGeniusDetails(currentlyDisplayedGeniuses);
}

bool MainWindow::on_listGeniuses_clicked(const QModelIndex &index)
{
    ui->pushButtonDeleteGenius->setEnabled(true);

    int clicked = ui->listGeniuses->currentIndex().row();

    vector<GeniusModel> geniuses = currentlyDisplayedGeniuses;

    GeniusModel genius = geniuses.at(clicked);

    QString name = QString::fromStdString(genius.getName());
    QString gender = QString::fromStdString(genius.getGender());
    QString BirthYear = QString::number(genius.getBirthYear());
    QString DeathYear = QString::number(genius.getDeathYear());

    if(DeathYear == "0")
        DeathYear = "N/A";

    ui->geniusDetailsTable->clearContents();
    ui->geniusDetailsTable->setItem(0, 0, new QTableWidgetItem(name));
    ui->geniusDetailsTable->setItem(0, 1, new QTableWidgetItem(gender));
    ui->geniusDetailsTable->setItem(0, 2, new QTableWidgetItem(BirthYear));
    ui->geniusDetailsTable->setItem(0, 3, new QTableWidgetItem(DeathYear));

    currentlyDisplayedGeniuses = geniuses;
}

void MainWindow::on_listComputers_clicked(const QModelIndex &index)
{
    ui->pushButtonDeleteComputer->setEnabled(true);

    int clicked = ui->listComputers->currentIndex().row();

    vector<ComputerModel> computers = currentlyDisplayedComputers;

    ComputerModel computer = computers.at(clicked);

    QString ModelName = QString::fromStdString(computer.getModelName());
    QString MakeYear = QString::number(computer.getMakeYear());
    QString type = QString::fromStdString(computer.getType());
    QString built = QString::number(computer.getBuilt());

    if(built == "0")
        built = "N";
    else
        built = "Y";

    ui->computerDetailsTable->clearContents();
    ui->computerDetailsTable->setItem(0, 0, new QTableWidgetItem(ModelName));
    ui->computerDetailsTable->setItem(0, 1, new QTableWidgetItem(MakeYear));
    ui->computerDetailsTable->setItem(0, 2, new QTableWidgetItem(type));
    ui->computerDetailsTable->setItem(0, 3, new QTableWidgetItem(built));

    currentlyDisplayedComputers = computers;
}

void MainWindow::on_clearGeniusSelection_clicked()
{
    ui->lineEditGeniusFilter->clear();
    displayAllGeniusDetails();
}

void MainWindow::on_clearComputerSelection_clicked()
{
    ui->lineEditComputerFilter->clear();
    displayAllComputerDetails();
}

void MainWindow::on_geniusDetailsTable_cellChanged(int row, int column)
{
    GeniusModel genius = currentlyDisplayedGeniuses.at(row);
    bool hasError = false;

    string name = genius.getName();
    string gender = genius.getGender();
    unsigned int birthYear = genius.getBirthYear();
    unsigned int deathYear = genius.getDeathYear();

    QString changedCell = ui->geniusDetailsTable->item(row, column)->text();

    if (changedCell.isEmpty())
        hasError = true;

    if (column == 0 && !hasError)
    {
        name = changedCell.toStdString();
    }
    else if (column == 1 && !hasError)
    {
        gender = changedCell.toStdString();
    }
    else if (column == 2 && !hasError && checkIfYearIsValid(changedCell))
    {

        birthYear = changedCell.toUInt();
    }
    else if (column == 3 && !hasError && checkIfYearIsValid(changedCell))
    {
        deathYear = changedCell.toUInt();
    }
    else
    {
        hasError = true;
    }

    if (hasError)
    {
        ui->statusBar->showMessage("Couldn't update model, check your input!", 3000);
        return;
    }

    genius.update(name, gender, birthYear, deathYear);

    if(_geniusService.update(genius))
        ui->statusBar->showMessage("Update success", 3000);
}

/**
 * @brief AddGenius::checkIfYearIsValid Validates if year string is 4 digits and does not have zero as a first digit, Year cannot be higher than current year
 * @param year
 * @return true if year is valid, else false
 */
bool MainWindow::checkIfYearIsValid(QString year)
{
    unsigned int currentYear = QDate::currentDate().year();

    if (year.length() != 4)
        return false;

    for (int i = 0; i < year.length(); i++)
    {
        if(!year[i].isDigit())
            return false;
        else if (i == 0 && year[i] == '0')
            return false;
    }

    if (year.toUInt() > currentYear)
        return false;

    return true;

void MainWindow::on_pushButtonDeleteGenius_clicked()
{
    int currentlySelectedGeniusIndex = ui->listGeniuses->currentIndex().row();
    GeniusModel currentlySelectedGenius = currentlyDisplayedGeniuses.at(currentlySelectedGeniusIndex);
    bool success = _geniusService.remove(currentlySelectedGenius);

    if (success)
    {
        ui->statusBar->showMessage("Successfully deleted the selected Genius", 2000);

        ui->pushButtonDeleteGenius->setEnabled(false);

        displayAllGeniuses();

        displayGeniusDetails(currentlyDisplayedGeniuses);
    }
    else
    {
        ui->statusBar->showMessage("Error: Selected Genius was not deleted", 2000);
    }
}

void MainWindow::on_pushButtonDeleteComputer_clicked()
{
    int currentlySelectedComputerIndex = ui->listComputers->currentIndex().row();
    ComputerModel currentlySelectedComputer = currentlyDisplayedComputers.at(currentlySelectedComputerIndex);
    bool success = _computerService.remove(currentlySelectedComputer);

    if (success)
    {
        ui->statusBar->showMessage("Successfully deleted the selected Computer", 2000);

        ui->pushButtonDeleteComputer->setEnabled(false);

        displayAllComputers();

        displayComputerDetails(currentlyDisplayedComputers);
    }
    else
    {
        ui->statusBar->showMessage("Error: Selected Computer was not deleted", 2000);
    }
}
