#include "editcomputer.h"
#include "ui_editcomputer.h"

EditComputer::EditComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditComputer)
{
    ui->setupUi(this);

    ui->comboBoxType->addItem("Mechanical");
    ui->comboBoxType->addItem("Electromechanical");
    ui->comboBoxType->addItem("Electronic");
    ui->comboBoxType->addItem("Integrated circuit");
}

EditComputer::~EditComputer()
{
    delete ui;
}

void EditComputer::setComputer(ComputerModel model)
{
    _computer = model;
    QString modelName = QString::fromStdString(model.getModelName());
    QString makeYear = QString::number(model.getMakeYear());
    QString type = QString::fromStdString(model.getType());
    bool built = model.getBuilt();

    ui->lineEditModelName->setText(modelName);
    if (makeYear != "0")
        ui->lineEditMakeYear->setText(makeYear);

    if (type == "Mechanical")
        ui->comboBoxType->setCurrentIndex(0);
    else if (type == "Electromechanical")
        ui->comboBoxType->setCurrentIndex(1);
    else if (type == "Electronic")
        ui->comboBoxType->setCurrentIndex(2);
    else if (type == "Integrated circuit")
        ui->comboBoxType->setCurrentIndex(3);

    if (built)
        ui->checkBoxBuilt->setChecked(true);
}

void EditComputer::on_pushButtonSave_clicked()
{
    ui->labelModelNameError->setText("");
    ui->labelMakeYearError->setText("");

    QString modelName = ui->lineEditModelName->text();
    QString makeYearStr = ui->lineEditMakeYear->text();
    QString type = ui->comboBoxType->currentText();
    bool builtBool = ui->checkBoxBuilt->isChecked();
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
        if (ui->checkBoxBuilt->checkState())
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

    _computer.update(modelName.toStdString(), makeYear, type.toStdString(), built);

    saved = _computerService.update(_computer);

    if (saved)
        this->done(1);
    else
        this->done(0);
}

void EditComputer::on_checkBoxBuilt_toggled(bool checked)
{
    if (!checked)
    {
        ui->lineEditMakeYear->setText("");
    }
}

void EditComputer::on_lineEditMakeYear_editingFinished()
{
    QString makeYear = ui->lineEditMakeYear->text();

    if (makeYear.isEmpty())
        ui->checkBoxBuilt->setChecked(false);
    else
        ui->checkBoxBuilt->setChecked(true);
}

/**
 * @brief EditComputer::checkIfYearIsValid Validates if
 *        year string is 4 digits and does not have
 *        zero as a first digit, Year cannot be
 *        higher than current year
 * @param year
 * @return true if year is valid, else false
 */
bool EditComputer::checkIfYearIsValid(QString year)
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

void EditComputer::on_buttonGeniusRelationship_clicked()
{
    EditRelationCG editDialog;

    ComputerModel selectedComputer = _computer;
    editDialog.setComputer(selectedComputer);

    editDialog.exec();
}
