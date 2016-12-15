#include "editrelation.h"
#include "ui_editrelation.h"

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
