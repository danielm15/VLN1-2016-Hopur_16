#include "editrelation.h"
#include "ui_editrelation.h"
#include <QDebug>

EditRelation::EditRelation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditRelation)
{
    ui->setupUi(this);

    _computers = _computerService.getComputer();
    updateComputerComboBox(_computers);
}

EditRelation::~EditRelation()
{
    delete ui;
}

void EditRelation::setGenius(GeniusModel selectedGenius)
{
    _genius = selectedGenius;

    displaySelectedGenius();
    displayLinkedComputers();
}

void EditRelation::displaySelectedGenius()
{
    ui->selectedGeniusListWidget->clear();

    QString name = QString::fromStdString(_genius.getName());

    ui->selectedGeniusListWidget->addItem(name);
}

void EditRelation::displayLinkedComputers()
{
    ui->linkedComputersListWidget->clear();

    vector<ComputerModel> computers = _geniusService.getAllComputersGeniusBuilt(_genius);

    for(unsigned int i = 0; i < computers.size(); i++)
    {
        ComputerModel computer = computers.at(i);
        QString modelName = QString::fromStdString(computer.getModelName());

        ui->linkedComputersListWidget->addItem(modelName);
    }
    _geniusComputers = computers;
}

void EditRelation::updateComputerComboBox(vector<ComputerModel> computers)
{
    ui->allComputersComboBox->addItem("- Add computer -");
    for (size_t i = 0; i < computers.size(); i++)
    {
        ComputerModel computer = computers.at(i);
        QString name = QString::fromStdString(computer.getModelName());
        ui->allComputersComboBox->addItem(name);
    }
}

void EditRelation::updateComputerList(vector<ComputerModel> computers)
{
    ui->linkedComputersListWidget->clear();

    for (size_t i = 0; i < computers.size(); i++)
    {
        ComputerModel computer = computers.at(i);
        QString name = QString::fromStdString(computer.getModelName());
        ui->linkedComputersListWidget->addItem(name);
    }
}

void EditRelation::on_allComputersComboBox_currentIndexChanged(int index)
{
    if (index == 0)
        return;

    ComputerModel computer = _computers.at(index - 1);
    _computers.erase(_computers.begin() + index - 1);
    ui->allComputersComboBox->setCurrentIndex(0);
    ui->allComputersComboBox->removeItem(index);

    _geniusComputers.push_back(computer);
    updateComputerList(_geniusComputers);
}

void EditRelation::on_pushButtonRemoveComputer_clicked()
{
    MainWindow main;
    int index = ui->linkedComputersListWidget->currentIndex().row();

    ComputerModel computer = _geniusComputers.at(index);
    QString name = QString::fromStdString(computer.getModelName());

    _relationships.removeRelationship(computer, _genius);

    _geniusComputers.erase(_geniusComputers.begin() + index);
    _computers.push_back(computer);
    ui->allComputersComboBox->addItem(name);

    updateComputerList(_geniusComputers);
    ui->pushButtonRemoveComputer->setEnabled(false);
}

void EditRelation::on_pushButtonSaveRelation_clicked()
{
    MainWindow main;
    bool saved;
    for (size_t i = 0; i < _geniusComputers.size(); i++)
    {
        ComputerModel computer = _geniusComputers.at(i);
        saved = _relationships.getRelationship(computer, _genius);
    }
    main.displayAllRelationsGC();

    this->done(1);

}

void EditRelation::on_linkedComputersListWidget_clicked()
{
    ui->pushButtonRemoveComputer->setEnabled(true);
}
