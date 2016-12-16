#include "editrelationcg.h"
#include "ui_editrelationcg.h"
#include <QDebug>

EditRelationCG::EditRelationCG(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditRelationCG)
{
    ui->setupUi(this);

    _geniuses = _geniusService.getGenius();
    updateGeniusComboBox(_geniuses);
}

EditRelationCG::~EditRelationCG()
{
    delete ui;
}

void EditRelationCG::setComputer(ComputerModel selectedComputer)
{
    _computer = selectedComputer;

    displaySelectedComputer();
    displayLinkedGeniuses();
}

void EditRelationCG::displaySelectedComputer()
{
    ui->selectedComputerListWidget->clear();

    QString name = QString::fromStdString(_computer.getModelName());

    ui->selectedComputerListWidget->addItem(name);
}

void EditRelationCG::displayLinkedGeniuses()
{
    ui->linkedGeniusesListWidget->clear();

    vector<GeniusModel> geniuses = _computerService.getAllGeniusesWhoBuiltComputer(_computer);

    for(unsigned int i = 0; i < geniuses.size(); i++)
    {
        GeniusModel genius = geniuses.at(i);
        QString Name = QString::fromStdString(genius.getName());

        ui->linkedGeniusesListWidget->addItem(Name);
    }
    _computerGeniuses = geniuses;
}

void EditRelationCG::updateGeniusComboBox(vector<GeniusModel> geniuses)
{
    ui->allGeniusComboBox->addItem("- Add genius -");
    for (size_t i = 0; i < geniuses.size(); i++)
    {
        GeniusModel genius = geniuses.at(i);
        QString name = QString::fromStdString(genius.getName());
        ui->allGeniusComboBox->addItem(name);
    }
}

void EditRelationCG::updateGeniusList(vector<GeniusModel> geniuses)
{
    ui->linkedGeniusesListWidget->clear();

    for (size_t i = 0; i < geniuses.size(); i++)
    {
        GeniusModel genius = geniuses.at(i);
        QString name = QString::fromStdString(genius.getName());
        ui->linkedGeniusesListWidget->addItem(name);
    }
}

void EditRelationCG::on_allGeniusComboBox_currentIndexChanged(int index)
{
    if (index == 0)
        return;

    GeniusModel genius = _geniuses.at(index - 1);
    _geniuses.erase(_geniuses.begin() + index - 1);
    ui->allGeniusComboBox->setCurrentIndex(0);
    ui->allGeniusComboBox->removeItem(index);

    _computerGeniuses.push_back(genius);
    updateGeniusList(_computerGeniuses);
}

void EditRelationCG::on_pushButtonRemoveGenius_clicked()
{
    MainWindow main;
    int index = ui->linkedGeniusesListWidget->currentIndex().row();

    GeniusModel genius = _computerGeniuses.at(index);
    QString name = QString::fromStdString(genius.getName());

    _relationships.removeRelationship(_computer, genius);

    _computerGeniuses.erase(_computerGeniuses.begin() + index);
    _geniuses.push_back(genius);
    ui->allGeniusComboBox->addItem(name);

    updateGeniusList(_computerGeniuses);
    ui->pushButtonRemoveGenius->setEnabled(false);
}

void EditRelationCG::on_pushButtonSaveRelationCG_clicked()
{
    MainWindow main;
    bool saved;
    for (size_t i = 0; i < _computerGeniuses.size(); i++)
    {
        GeniusModel genius = _computerGeniuses.at(i);
        saved = _relationships.getRelationship(_computer, genius);
    }
    main.displayAllRelationsCG();

    this->done(1);

}

void EditRelationCG::on_linkedGeniusesListWidget_clicked()
{
    ui->pushButtonRemoveGenius->setEnabled(true);
}
