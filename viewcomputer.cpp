#include "viewcomputer.h"
#include "ui_viewcomputer.h"

ViewComputer::ViewComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewComputer)
{
    ui->setupUi(this);
}

ViewComputer::~ViewComputer()
{
    delete ui;
}
