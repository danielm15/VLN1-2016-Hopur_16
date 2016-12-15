#ifndef ADDGENIUS_H
#define ADDGENIUS_H

#include <QDialog>
#include <QDate>
#include <vector>

#include "services/geniusservice.h"
#include "services/computerservice.h"
#include "services/computergeniusservice.h"
#include "models/computermodel.h"

namespace Ui {
class AddGenius;
}

class AddGenius : public QDialog
{
    Q_OBJECT

public:
    explicit AddGenius(QWidget *parent = 0);
    ~AddGenius();

private slots:
    void on_pushButtonSaveGenius_clicked();

    void on_comboBoxComputers_currentIndexChanged(int index);

    void on_listWidgetComputers_clicked();

    void on_buttonRemoveSelectedComputer_clicked();

private:
    Ui::AddGenius *ui;
    vector<ComputerModel> _computers;
    vector<ComputerModel> _geniusComputers;

    GeniusService _geniusService;
    ComputerService _computerService;
    ComputerGeniusService _relationships;

    bool checkIfYearIsValid(QString year);
    void updateComputerComboBox(vector<ComputerModel> computers);
    void updateComputerList(vector<ComputerModel> computers);

};

#endif // ADDGENIUS_H
