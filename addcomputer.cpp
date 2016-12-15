#include "addcomputer.h"
#include "ui_addcomputer.h"
#include <QDebug>

AddComputer::AddComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputer)
{
    ui->setupUi(this);

    ui->comboBoxComputerType->addItem("Mechanical");
    ui->comboBoxComputerType->addItem("Electromechanical");
    ui->comboBoxComputerType->addItem("Electronic");
    ui->comboBoxComputerType->addItem("Integrated circuit");
}

AddComputer::~AddComputer()
{
    delete ui;
}

/**
 * @brief AddComputer::on_pushButtonSaveComputer_clicked
 *      Validates parameters for computer and calls save
 *      method on computer service. If save is success
 *      a status code 1 is sent down to ui, else 0
 */
void AddComputer::on_pushButtonSaveComputer_clicked()
{
    ui->labelMakeYearError->setText("");
    ui->labelModelNameError->setText("");

    QString modelName = ui->lineEditComputerName->text();
    QString makeYearStr = ui->lineEditMakeYear->text();
    QString type = ui->comboBoxComputerType->currentText();
    bool builtBool = ui->checkBoxComputerBuilt->isChecked();
    int built;

    bool hasError = false;
    bool saved;
    unsigned int makeYear;

    if (modelName.isEmpty())
    {
        ui->labelModelNameError->setText("<span style='color:red'>Enter the name of the model</span>");
        hasError = true;
    }

    if (!checkIfYearIsValid(makeYearStr))
    {
        if (ui->checkBoxComputerBuilt->checkState())
        {
            ui->labelMakeYearError->setText("<span style='color:red'>Enter valid year!</span>");
            hasError = true;
        }
    }

    if (makeYearStr.isEmpty() && builtBool)
    {
        ui->labelMakeYearError->setText("<span style='color:red'>This is a required field for built computers</span>");
        hasError = true;
    }

    if (!makeYearStr.isEmpty() && !builtBool)
    {
        ui->labelMakeYearError->setText("<span style='color:red'>This fields need's to be empty!</span>");
        hasError = true;
    }

    if (hasError)
        return;

    if (builtBool)
        built = 1;
    else
        built = 0;

    makeYear = makeYearStr.toUInt();

    saved = _computerService.addComputer(modelName.toStdString(), makeYear, type.toStdString(), built);

    if (saved)
        this->done(1);
    else
        this->done(0);
}

/**
 * @brief AddComputer::checkIfYearIsValid Validates if
 *        year string is 4 digits and does not have
 *        zero as a first digit, Year cannot be
 *        higher than current year
 * @param year
 * @return true if year is valid, else false
 */
bool AddComputer::checkIfYearIsValid(QString year)
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

void AddComputer::on_lineEditMakeYear_editingFinished()
{
    QString makeYear = ui->lineEditMakeYear->text();

    if (makeYear.isEmpty())
        ui->checkBoxComputerBuilt->setChecked(false);
    else
        ui->checkBoxComputerBuilt->setChecked(true);
}

void AddComputer::on_checkBoxComputerBuilt_toggled(bool checked)
{
    if (!checked)
    {
        ui->lineEditMakeYear->setText("");
    }
}
