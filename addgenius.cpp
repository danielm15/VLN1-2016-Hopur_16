#include "addgenius.h"
#include "ui_addgenius.h"

AddGenius::AddGenius(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddGenius)
{
    ui->setupUi(this);

    ui->comboBoxGeniusGender->addItem("Male");
    ui->comboBoxGeniusGender->addItem("Female");
}

AddGenius::~AddGenius()
{
    delete ui;
}

/**
 * @brief AddGenius::on_pushButtonSaveGenius_clicked Validates and calls save method on genius service layer. Delivers status code to be used in the status bar on main ui
 */
void AddGenius::on_pushButtonSaveGenius_clicked()
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

    if (birthYear > deathYear && deathYear != 0)
    {
        ui->labelGeniusDeathYearError->setText("<span style='color:red'>Nobody can die before he is born!</span>");
        hasError = true;
    }

    if (hasError)
        return;

    name[0] = name[0].toUpper();

    saved = _geniusService.addGenius(name.toStdString(), gender[0], birthYear, deathYear);

    if (saved)
        this->done(1);
    else
        this->done(0);
}

/**
 * @brief AddGenius::checkIfYearIsValid Validates if year string is 4 digits and does not have zero as a first digit, Year cannot be higher than current year
 * @param year
 * @return true if year is valid, else false
 */
bool AddGenius::checkIfYearIsValid(QString year)
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
