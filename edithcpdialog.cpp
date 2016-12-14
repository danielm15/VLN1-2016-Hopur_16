#include "edithcpdialog.h"
#include "ui_edithcpdialog.h"

edithCpDialog::edithCpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edithCpDialog)
{
    ui->setupUi(this);
}

edithCpDialog::~edithCpDialog()
{
    delete ui;
}
