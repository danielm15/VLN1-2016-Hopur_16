#ifndef EDITCOMPUTER_H
#define EDITCOMPUTER_H

#include <QDialog>
#include <models/computermodel.h>
#include <services/computerservice.h>
#include <mainwindow.h>

namespace Ui {
class EditComputer;
}

class EditComputer : public QDialog
{
    Q_OBJECT

public:
    explicit EditComputer(QWidget *parent = 0);
    ~EditComputer();

    void setComputer(ComputerModel model);

private slots:
    void on_pushButtonSave_clicked();

    void on_checkBoxBuilt_toggled(bool checked);

    void on_lineEditMakeYear_editingFinished();

    void on_buttonGeniusRelationship_clicked();

private:
    Ui::EditComputer *ui;

    bool checkIfYearIsValid(QString year);

    ComputerService _computerService;
    ComputerModel _computer;


};

#endif // EDITCOMPUTER_H
