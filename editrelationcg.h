#ifndef EDITRELATIONCG_H
#define EDITRELATIONCG_H

#include <QDialog>
#include <mainwindow.h>
#include <vector>

namespace Ui {
class EditRelationCG;
}

class EditRelationCG : public QDialog
{
    Q_OBJECT

public:
    explicit EditRelationCG(QWidget *parent = 0);
    ~EditRelationCG();

    void setComputer(ComputerModel selectedComputer);

private slots:
    void on_allGeniusComboBox_currentIndexChanged(int index);

    void on_pushButtonRemoveGenius_clicked();

    void on_pushButtonSaveRelationCG_clicked();

    void on_linkedGeniusesListWidget_clicked();

private:
    void displaySelectedComputer();
    void displayLinkedGeniuses();

    void updateGeniusComboBox(vector<GeniusModel> geniuses);
    void updateGeniusList(vector<GeniusModel> geniuses);

    Ui::EditRelationCG *ui;
    ComputerModel _computer;
    GeniusModel _genius;

    ComputerService _computerService;
    GeniusService _geniusService;
    ComputerGeniusService _relationships;

    vector<GeniusModel> _geniuses;
    vector<GeniusModel> _computerGeniuses;
};

#endif // EDITRELATIONCG_H
