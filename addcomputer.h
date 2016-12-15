#ifndef ADDCOMPUTER_H
#define ADDCOMPUTER_H

#include <QDialog>
#include <QDate>

#include "services/computerservice.h"

namespace Ui {
class AddComputer;
}

class AddComputer : public QDialog
{
    Q_OBJECT

public:
    explicit AddComputer(QWidget *parent = 0);
    ~AddComputer();

private slots:
    void on_pushButtonSaveComputer_clicked();

    void on_lineEditMakeYear_editingFinished();

    void on_checkBoxComputerBuilt_toggled(bool checked);

private:
    Ui::AddComputer *ui;
    ComputerService _computerService;

    bool checkIfYearIsValid(QString);
};

#endif // ADDCOMPUTER_H
