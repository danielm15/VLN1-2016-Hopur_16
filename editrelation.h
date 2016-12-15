#ifndef EDITRELATION_H
#define EDITRELATION_H

#include <QDialog>

namespace Ui {
class EditRelation;
}

class EditRelation : public QDialog
{
    Q_OBJECT

public:
    explicit EditRelation(QWidget *parent = 0);
    ~EditRelation();

private:
    Ui::EditRelation *ui;
};

#endif // EDITRELATION_H
