#ifndef VIEWCOMPUTER_H
#define VIEWCOMPUTER_H

#include <QDialog>

namespace Ui {
class ViewComputer;
}

class ViewComputer : public QDialog
{
    Q_OBJECT

public:
    explicit ViewComputer(QWidget *parent = 0);
    ~ViewComputer();

private:
    Ui::ViewComputer *ui;
};

#endif // VIEWCOMPUTER_H
