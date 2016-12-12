#include "addgenius.h"
#include "ui_addgenius.h"

AddGenius::AddGenius(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddGenius)
{
    ui->setupUi(this);
}

AddGenius::~AddGenius()
{
    delete ui;
}
