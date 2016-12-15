#include "editrelation.h"
#include "ui_editrelation.h"
#include <QDebug>

EditRelation::EditRelation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditRelation)
{
    ui->setupUi(this);
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
    qDebug() << name;
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
        qDebug() << modelName << endl;
    }
}


