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
    displayAllRelationsGC();
    displayAllRelationsCG();
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
    currentlyDisplayedComputers = computers;
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
   currentlyDisplayedGeniuses = geniuses;
   displayGeniusDetails(geniuses);
}

void MainWindow::displayGeniusDetails(vector<GeniusModel> geniuses)
{
    ui->geniusDetailsTable->clearContents();

    //Couldn't find a way to get rid of this warning since setRowCount() returns an integer value;
    ui->geniusDetailsTable->setRowCount(static_cast<int>(geniuses.size()));

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

    currentlyDisplayedGeniusDetails = geniuses;
}

void MainWindow::displayAllComputerDetails()
{
    vector<ComputerModel> computers = _computerService.getComputer();
    displayComputerDetails(computers);
}

void MainWindow::displayComputerDetails(vector<ComputerModel> computers)
{
    ui->computerDetailsTable->clearContents();

    //Couldn't find a way to get rid of this warning since setRowCount() returns an integer value;
    ui->computerDetailsTable->setRowCount(static_cast<int>(computers.size()));

    for(unsigned int row = 0; row < computers.size(); row++)
    {
        ComputerModel computer = computers.at(row);

        QString ModelName = QString::fromStdString(computer.getModelName());
        QString MakeYear = QString::number(computer.getMakeYear());
        QString type = QString::fromStdString(computer.getType());
        QString built = QString::number(computer.getBuilt());

        if (MakeYear == "0")
            MakeYear = "";

        if(built == "0")
            built = "N";
        else
            built = "Y";

        ui->computerDetailsTable->setItem(row, 0, new QTableWidgetItem(ModelName));
        ui->computerDetailsTable->setItem(row, 1, new QTableWidgetItem(MakeYear));
        ui->computerDetailsTable->setItem(row, 2, new QTableWidgetItem(type));
        ui->computerDetailsTable->setItem(row, 3, new QTableWidgetItem(built));
    }

    currentlyDisplayedComputerDetails = computers;
}

void MainWindow::displayAllRelationsGC()
{
    vector<GeniusModel> geniuses = _geniusService.getGenius();
    displayRelationsGC(geniuses);
}

void MainWindow::displayRelationsGC(vector<GeniusModel> geniuses)
{
    ui->geniusComputerRelationWidget->clear();
    ui->geniusComputerRelationWidget->setColumnCount(1);
    ui->geniusComputerRelationWidget->setHeaderLabels(QStringList() << "Geniuses");
    vector<ComputerModel> computers;

    for(unsigned int i = 0; i < geniuses.size(); i++)
    {
        GeniusModel genius = geniuses.at(i);

        QTreeWidgetItem *treeGenius = new QTreeWidgetItem(ui->geniusComputerRelationWidget);
        QString name = QString::fromStdString(genius.getName());
        treeGenius->setText(0, name);

        computers = _geniusService.getAllComputersGeniusBuilt(genius);

        if(computers.empty())
        {

        }
        else
        {
            for(unsigned int i = 0; i < computers.size(); i++)
            {
                ComputerModel computer = computers.at(i);
                QTreeWidgetItem *treeComputer = new QTreeWidgetItem();

                QString ModelName = QString::fromStdString(computer.getModelName());
                treeComputer->setText(0, ModelName);
                treeGenius->addChild(treeComputer);
            }
        }
    }
    currentlyDisplayedGeniusRelations = geniuses;
}

void MainWindow::displayAllRelationsCG()
{
    vector<ComputerModel> computers = _computerService.getComputer();
    displayRelationsCG(computers);
}

void MainWindow::displayRelationsCG(vector<ComputerModel> computers)
{
    ui->computerGeniusRelationWidget->clear();
    ui->computerGeniusRelationWidget->setColumnCount(1);
    ui->computerGeniusRelationWidget->setHeaderLabels(QStringList() << "Computers");
    vector<GeniusModel> geniuses;

    for(unsigned int i = 0; i < computers.size(); i++)
    {
        ComputerModel computer = computers.at(i);

        QTreeWidgetItem *treeComputer = new QTreeWidgetItem(ui->computerGeniusRelationWidget);
        QString name = QString::fromStdString(computer.getModelName());
        treeComputer->setText(0, name);

        geniuses = _computerService.getAllGeniusesWhoBuiltComputer(computer);

        if(geniuses.empty())
        {

        }
        else
        {
            for(unsigned int i = 0; i < geniuses.size(); i++)
            {
                GeniusModel genius = geniuses.at(i);
                QTreeWidgetItem *treeGenius = new QTreeWidgetItem();

                QString Name = QString::fromStdString(genius.getName());
                treeGenius->setText(0, Name);
                treeComputer->addChild(treeGenius);
            }
        }
    }
    currentlyDisplayedComputerRelations = computers;
}

void MainWindow::on_pushButtonAddGenius_clicked()
{
   AddGenius geniusDialog;
   int returnValueFromAddGenius = geniusDialog.exec();
   if (returnValueFromAddGenius == 1)
   {
       displayAllGeniuses();
       displayGeniusDetails(currentlyDisplayedGeniuses);

       ui->pushButtonDeleteGenius->setEnabled(false);
       ui->editButtonGenius->setEnabled(false);
       ui->statusBar->showMessage("Successfully added new genius", 2000);
   }
}

void MainWindow::on_pushButtonAddComputer_clicked()
{
    AddComputer computerDialog;
    int returnValueFromAddComputer = computerDialog.exec();
    if (returnValueFromAddComputer == 1)
    {
        displayAllComputers();
        displayComputerDetails(currentlyDisplayedComputers);

        ui->pushButtonDeleteComputer->setEnabled(false);
        ui->editbuttoncomputer->setEnabled(false);
        ui->statusBar->showMessage("Successfully added new computer", 2000);
    }
}

void MainWindow::on_actionAddGenius_triggered()
{
    on_pushButtonAddGenius_clicked();
}

void MainWindow::on_actionAddComputer_triggered()
{
    on_pushButtonAddComputer_clicked();
}

void MainWindow::on_lineEditComputerFilter_textChanged()
{
    ui->pushButtonDeleteComputer->setEnabled(false);
    ui->editbuttoncomputer->setEnabled(false);

    string input = ui->lineEditComputerFilter->text().toStdString();

    currentlyDisplayedComputers = _computerService.find(input);
    displayComputers(currentlyDisplayedComputers);
    displayComputerDetails(currentlyDisplayedComputers);
}

void MainWindow::on_lineEditGeniusFilter_textChanged()
{
    ui->pushButtonDeleteGenius->setEnabled(false);
    ui->editButtonGenius->setEnabled(false);

    string input = ui->lineEditGeniusFilter->text().toStdString();

    currentlyDisplayedGeniuses = _geniusService.find(input);
    displayGeniuses(currentlyDisplayedGeniuses);
    displayGeniusDetails(currentlyDisplayedGeniuses);
}

void MainWindow::on_listGeniuses_clicked()
{
    ui->pushButtonDeleteGenius->setEnabled(true);
    ui->editButtonGenius->setEnabled(true);

    int clicked = ui->listGeniuses->currentIndex().row();

    vector<GeniusModel> geniuses;
    geniuses.push_back(currentlyDisplayedGeniuses.at(clicked));

    currentlyDisplayedGeniusDetails = geniuses;

    displayGeniusDetails(geniuses);
}

void MainWindow::on_listComputers_clicked()
{
    ui->pushButtonDeleteComputer->setEnabled(true);
    ui->editbuttoncomputer->setEnabled(true);

    int clicked = ui->listComputers->currentIndex().row();

    vector<ComputerModel> computers;
    computers.push_back(currentlyDisplayedComputers.at(clicked));

    currentlyDisplayedComputerDetails = computers;

    displayComputerDetails(computers);
}

void MainWindow::on_clearGeniusSelection_clicked()
{
    ui->lineEditGeniusFilter->clear();
    ui->geniusDetailsTable->setSortingEnabled(false);
    displayAllGeniusDetails();
    ui->geniusDetailsTable->setSortingEnabled(true);

    ui->pushButtonDeleteGenius->setEnabled(false);
    ui->editButtonGenius->setEnabled(false);
    ui->listGeniuses->clearSelection();
}

void MainWindow::on_clearComputerSelection_clicked()
{
    ui->lineEditComputerFilter->clear();
    ui->computerDetailsTable->setSortingEnabled(false);
    displayAllComputerDetails();
    ui->computerDetailsTable->setSortingEnabled(true);

    ui->pushButtonDeleteComputer->setEnabled(false);
    ui->editbuttoncomputer->setEnabled(false);
    ui->listComputers->clearSelection();
}

/*
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
*/

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
}

void MainWindow::on_pushButtonDeleteGenius_clicked()
{
    int currentlySelectedGeniusIndex = ui->listGeniuses->currentIndex().row();
    GeniusModel currentlySelectedGenius = currentlyDisplayedGeniuses.at(currentlySelectedGeniusIndex);
    bool success = _geniusService.remove(currentlySelectedGenius);

    if (success)
    {
        ui->statusBar->showMessage("Successfully deleted the selected Genius", 2000);
        ui->pushButtonDeleteGenius->setEnabled(false);
        ui->editButtonGenius->setEnabled(false);
        ui->lineEditGeniusFilter->clear();

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
        ui->editbuttoncomputer->setEnabled(false);
        ui->lineEditComputerFilter->clear();

        displayAllComputers();
        displayComputerDetails(currentlyDisplayedComputers);
    }
    else
    {
        ui->statusBar->showMessage("Error: Selected Computer was not deleted", 2000);
    }
}

/*
void MainWindow::on_computerDetailsTable_itemChanged(QTableWidgetItem *item)
{
    ComputerModel computer = currentlyDisplayedComputers.at(item->row());
    bool hasError = false;

    string modelName = computer.getModelName();
    string type = computer.getType();
    unsigned int makeYear = computer.getMakeYear();
    bool built = computer.getBuilt();
    int column = item->column();

    QString changedCell = ui->computerDetailsTable->item(item->row(), item->column())->text();

    if (changedCell.isEmpty())
        hasError = true;

    if (column == 0 && !hasError)
    {
        modelName = changedCell.toStdString();
    }
    else if (column == 1 && !hasError && checkIfYearIsValid(changedCell))
    {
        makeYear = changedCell.toUInt();
    }
    else if (column == 2 && !hasError )
    {
        type = changedCell.toStdString();
    }
    else if (column == 3 && !hasError)
    {

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

    computer.update(modelName, makeYear, type, built);

    if(_computerService.update(computer))
        ui->statusBar->showMessage("Update success", 3000);
}
*/

void MainWindow::on_pushButtonEditRelationGC_clicked()
{
    EditRelation editDialog;
    int clicked = ui->geniusComputerRelationWidget->currentIndex().row();

    GeniusModel selectedGenius = currentlyDisplayedGeniusRelations.at(clicked);
    editDialog.setGenius(selectedGenius);

    int returnValueFromEditRelation = editDialog.exec();

    if(returnValueFromEditRelation == 1)
    {
        ui->statusBar->showMessage("Succesfully updated relation", 2000);
        ui->pushButtonEditRelationGC->setEnabled(false);
    }
    displayAllRelationsGC();
    displayAllRelationsCG();
}

void MainWindow::on_pushButtonEditRelationCG_clicked()
{
    EditRelationCG editDialog;
    int clicked = ui->computerGeniusRelationWidget->currentIndex().row();

    ComputerModel selectedComputer = currentlyDisplayedComputerRelations.at(clicked);
    editDialog.setComputer(selectedComputer);

    int returnValueFromEditRelation = editDialog.exec();

    if(returnValueFromEditRelation == 1)
    {
        ui->statusBar->showMessage("Succesfully updated relation", 2000);
        ui->pushButtonEditRelationCG->setEnabled(false);
    }
    displayAllRelationsGC();
    displayAllRelationsCG();
}

void MainWindow::on_listGeniuses_doubleClicked()
{
    edithCpDialog edit;
    int doubleClicked = ui->listGeniuses->currentIndex().row();
    GeniusModel selectedGenius = currentlyDisplayedGeniuses[doubleClicked];
    edit.setGenius(selectedGenius);

    int returnValueFromEditGenius = edit.exec();

    if(returnValueFromEditGenius == 1)
    {
        ui->lineEditGeniusFilter->clear();
        displayAllGeniuses();
        displayGeniusDetails(currentlyDisplayedGeniuses);
        displayAllRelationsGC();
        displayAllRelationsCG();
        ui->statusBar->showMessage("Succesfully updated Genius", 2000);
        ui->editButtonGenius->setEnabled(false);
        ui->pushButtonDeleteGenius->setEnabled(false);
    }
}

void MainWindow::on_listComputers_doubleClicked()
{
    EditComputer edit;
    int doubleClicked = ui->listComputers->currentIndex().row();
    ComputerModel selectedComputer = currentlyDisplayedComputers[doubleClicked];
    edit.setComputer(selectedComputer);

    int returnValueFromEditDialog = edit.exec();

    if(returnValueFromEditDialog == 1)
    {
        ui->lineEditComputerFilter->clear();
        displayAllComputers();
        displayComputerDetails(currentlyDisplayedComputers);
        displayAllRelationsGC();
        displayAllRelationsCG();
        ui->statusBar->showMessage("Succesfully updated Computer", 2000);
        ui->editbuttoncomputer->setEnabled(false);
        ui->pushButtonDeleteComputer->setEnabled(false);
    }
}

void MainWindow::on_editButtonGenius_clicked()
{
    on_listGeniuses_doubleClicked();
}

void MainWindow::on_editbuttoncomputer_clicked()
{
    on_listComputers_doubleClicked();
}

void MainWindow::on_geniusComputerRelationWidget_itemClicked(QTreeWidgetItem *item)
{
    if(!item->parent())
        ui->pushButtonEditRelationGC->setEnabled(true);
    else
        ui->pushButtonEditRelationGC->setEnabled(false);
}

void MainWindow::on_computerGeniusRelationWidget_itemClicked(QTreeWidgetItem *item)
{
    if(!item->parent())
        ui->pushButtonEditRelationCG->setEnabled(true);
    else
        ui->pushButtonEditRelationCG->setEnabled(false);
}


void MainWindow::on_geniusDetails_tabBarClicked()
{
    ui->pushButtonDeleteComputer->setEnabled(false);
    ui->editbuttoncomputer->setEnabled(false);
    ui->listGeniuses->clearSelection();
}

