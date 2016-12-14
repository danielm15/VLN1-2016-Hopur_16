#ifndef EDITHCPDIALOG_H
#define EDITHCPDIALOG_H

#include <QDialog>

namespace Ui {
class edithCpDialog;
}

class edithCpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit edithCpDialog(QWidget *parent = 0);
    ~edithCpDialog();

private:
    Ui::edithCpDialog *ui;
};

#endif // EDITHCPDIALOG_H
