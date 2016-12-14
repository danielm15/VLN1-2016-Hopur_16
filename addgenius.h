#ifndef ADDGENIUS_H
#define ADDGENIUS_H

#include <QDialog>
#include <QDate>

#include "services/geniusservice.h"

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

private:
    Ui::AddGenius *ui;
    bool checkIfYearIsValid(QString year);
};

#endif // ADDGENIUS_H
