#ifndef ADDCOMPUTER_H
#define ADDCOMPUTER_H

#include <QDialog>

namespace Ui {
class AddComputer;
}

class AddComputer : public QDialog
{
    Q_OBJECT

public:
    explicit AddComputer(QWidget *parent = 0);
    ~AddComputer();

private:
    Ui::AddComputer *ui;
};

#endif // ADDCOMPUTER_H
