#ifndef EDITRELATION_H
#define EDITRELATION_H

#include <QDialog>
#include <mainwindow.h>

namespace Ui {
class EditRelation;
}

class EditRelation : public QDialog
{
    Q_OBJECT

public:
    explicit EditRelation(QWidget *parent = 0);
    ~EditRelation();

    void setGenius(GeniusModel selectedGenius);

private slots:
    void on_allComputersComboBox_currentIndexChanged(int index);

    void on_pushButtonRemoveComputer_clicked();

    void on_pushButtonSaveRelation_clicked();

    void on_linkedComputersListWidget_clicked();

private:
    void displaySelectedGenius();
    void displayLinkedComputers();

    void updateComputerComboBox(vector<ComputerModel> computers);
    void updateComputerList(vector<ComputerModel> computers);

    Ui::EditRelation *ui;
    GeniusModel _genius;
    ComputerModel _computer;

    GeniusService _geniusService;
    ComputerService _computerService;
    ComputerGeniusService _relationships;

    vector<ComputerModel> _computers;
    vector<ComputerModel> _geniusComputers;
};

#endif // EDITRELATION_H
