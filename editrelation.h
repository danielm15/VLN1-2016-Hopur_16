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

private:
    void displaySelectedGenius();
    void displayLinkedComputers();

    Ui::EditRelation *ui;
    GeniusModel _genius;
    ComputerModel _computer;
    GeniusService _geniusService;
};

#endif // EDITRELATION_H
