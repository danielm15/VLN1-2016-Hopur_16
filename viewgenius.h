#ifndef VIEWGENIUS_H
#define VIEWGENIUS_H

#include <QDialog>

namespace Ui {
class ViewGenius;
}

class ViewGenius : public QDialog
{
    Q_OBJECT

public:
    explicit ViewGenius(QWidget *parent = 0);
    ~ViewGenius();

private:
    Ui::ViewGenius *ui;
};

#endif // VIEWGENIUS_H
