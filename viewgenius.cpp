#include "viewgenius.h"
#include "ui_viewgenius.h"

ViewGenius::ViewGenius(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewGenius)
{
    ui->setupUi(this);
}

ViewGenius::~ViewGenius()
{
    delete ui;
}
