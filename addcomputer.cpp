#include "addcomputer.h"
#include "ui_addcomputer.h"

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

void AddComputer::on_pushButtonSaveComputer_clicked()
{
    ComputerService computerService;

    ui->labelMakeYearError->setText("");
    ui->labelModelNameError->setText("");

    QString modelName = ui->lineEditComputerName->text();
    QString makeYearStr = ui->lineEditMakeYear->text();
    QString type = ui->comboBoxComputerType->currentText();
    bool builtBool = ui->checkBoxComputerBuilt->isChecked();
    bool built;

    bool hasError = false;

    if (modelName.isEmpty())
    {
        ui->labelModelNameError->setText("<span style='color:red'>Enter the name of the model</span>");
        hasError = true;
    }

    if (!checkIfYearIsValid(makeYearStr))
    {
        ui->labelMakeYearError->setText("<span style='color:red'>Enter valid year!</span>");
        hasError = true;
    }

    if (hasError)
        return;

    if (builtBool)
        built = 1;
    else
        built = 0;

    unsigned int makeYear = makeYearStr.toUInt();

    computerService.addComputer(modelName.toStdString(), makeYear, type.toStdString(), built);

    this->done(1);
}

/**
 * @brief AddComputer::checkIfYearIsValid Validates if year string is 4 digits and does not have zero as a first digit, Year cannot be higher than current year
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
