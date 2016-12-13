#include "addcomputer.h"
#include "ui_addcomputer.h"

AddComputer::AddComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputer)
{
    ui->setupUi(this);

    ui->comboBoxComputerType->addItem("Mechanical");
    ui->comboBoxComputerType->addItem("Electromechanical");
    ui->comboBoxComputerType->addItem("Electronic");
    ui->comboBoxComputerType->addItem("Integrated circuit");
}

AddComputer::~AddComputer()
{
    delete ui;
}
