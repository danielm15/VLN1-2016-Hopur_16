#ifndef EDITHCPDIALOG_H
#define EDITHCPDIALOG_H

#include <QDialog>
#include <models/geniusmodel.h>
#include <models/computermodel.h>
#include <mainwindow.h>

namespace Ui {
class edithCpDialog;
}

class edithCpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit edithCpDialog(QWidget *parent = 0);
    ~edithCpDialog();

    void setGenius(GeniusModel selectedGenius);

    void setComputer(ComputerModel selectedComputer);

private slots:
    void on_pushButton_clicked();

    void on_buttonEditRelationship_clicked();

private:
    Ui::edithCpDialog *ui;
    GeniusModel _genius;
    ComputerModel _computer;
    GeniusService _geniusService;
    bool checkIfYearIsValid(QString year);

};

#endif // EDITHCPDIALOG_H
