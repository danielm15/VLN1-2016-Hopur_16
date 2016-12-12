#ifndef ADDGENIUS_H
#define ADDGENIUS_H

#include <QDialog>

namespace Ui {
class AddGenius;
}

class AddGenius : public QDialog
{
    Q_OBJECT

public:
    explicit AddGenius(QWidget *parent = 0);
    ~AddGenius();

private:
    Ui::AddGenius *ui;
};

#endif // ADDGENIUS_H
