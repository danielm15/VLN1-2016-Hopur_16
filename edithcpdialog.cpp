#include "edithcpdialog.h"
#include "ui_edithcpdialog.h"

edithCpDialog::edithCpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edithCpDialog)
{
    ui->setupUi(this);

    QString name = QString::fromStdString(_genius.getName());
    ui->lineEditGeniusName->setText(name);
}

edithCpDialog::~edithCpDialog()
{
    delete ui;
}

void edithCpDialog::setGenius(GeniusModel selectedGenius)
{
   _genius = selectedGenius;
}

void edithCpDialog::setComputer(ComputerModel selectedComputer)
{
    _computer = selectedComputer;
}

void edithCpDialog::on_pushButton_clicked()
{
    QString name = ui->lineEditGeniusName->text();
    string gender = ui->comboBoxGeniusGender->currentText().toStdString();
    QString birthYearStr = ui->lineEditBirthYear->text();
    QString deathYearStr = ui->lineEditDeathYear->text();

    bool hasError = false;
    bool saved;

    unsigned int birthYear;
    unsigned int deathYear;

    ui->labelGeniusNameError->setText("");
    ui->labelGeniusBirthYearError->setText("");
    ui->labelGeniusDeathYearError->setText("");

    if (name.isEmpty())
    {
        ui->labelGeniusNameError->setText("<span style='color:red'>Genius needs a name!</span>");
        hasError = true;
    }

    if (!checkIfYearIsValid(birthYearStr))
    {
        ui->labelGeniusBirthYearError->setText("<span style='color:red'>Please enter a valid year!</span>");
        hasError = true;
    }

    if (!deathYearStr.isEmpty() && !checkIfYearIsValid(deathYearStr))
    {
        ui->labelGeniusDeathYearError->setText("<span style='color:red'>Please enter a valid year!</span>");
        hasError = true;
    }

    birthYear = birthYearStr.toUInt();
    deathYear = deathYearStr.toUInt();

    if (birthYear < deathYear)
    {
        ui->labelGeniusDeathYearError->setText("<span style='color:red'>Nobody can die before he is born!</span>");
        hasError = true;
    }

    if (hasError)
        return;

    name[0] = name[0].toUpper();
    _genius.update(name.toStdString(), gender, birthYear, deathYear);
    saved = _geniusService.update(_genius);

    if (saved)
        this->done(1);
    else
        this->done(0);
}

bool edithCpDialog::checkIfYearIsValid(QString year)
{
    unsigned int currentYear = QDate::currentDate().year();

    if (year.length() != 4)
        return false;

    for (int i = 0; i < year.length(); i++)
    {
        if(!year[i].isDigit())
            return false;
        else if (i == 0 && year[i] == '0')
            return false;
    }

    if (year.toUInt() > currentYear)
        return false;

    return true;
}
