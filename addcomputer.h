#ifndef ADDCOMPUTER_H
#define ADDCOMPUTER_H

#include <QDialog>
#include <QDate>
#include <vector>

#include "services/computerservice.h"
#include "services/geniusservice.h"
#include "services/computergeniusservice.h"

#include "models/computermodel.h"
#include "models/geniusmodel.h"

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

    void on_comboBoxGeniuses_currentIndexChanged(int index);

    void on_listWidgetGeniuses_clicked(const QModelIndex &index);

    void on_buttonRemoveGeniuses_clicked();

private:
    Ui::AddComputer *ui;
    ComputerService _computerService;
    GeniusService _geniusService;
    ComputerGeniusService _relationships;

    vector<GeniusModel> _geniuses;
    vector<GeniusModel> _computerGeniuses;

    void updateGeniusComboBox(vector<GeniusModel> geniuses);
    void updateGeniusList(vector<GeniusModel> geniuses);


    bool checkIfYearIsValid(QString);
};

#endif // ADDCOMPUTER_H
