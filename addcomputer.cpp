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

    _geniuses = _geniusService.getGenius();
    updateGeniusComboBox(_geniuses);
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
    {
        ComputerModel computer;

        vector<ComputerModel> computers = _computerService.find(modelName.toStdString());

        for (size_t i = 0; i < computers.size(); i++)
        {
            computer = computers.at(i);
            if (computer.getModelName() == modelName.toStdString() && computer.getMakeYear() == makeYear && computer.getType() == type.toStdString() && computer.getBuilt() == built)
                break;
        }

        for (size_t i = 0; i < _computerGeniuses.size(); i++)
        {
            GeniusModel genius = _computerGeniuses.at(i);
            _relationships.getRelationship(computer, genius);
        }
    }

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

void AddComputer::updateGeniusComboBox(vector<GeniusModel> geniuses)
{
    ui->comboBoxGeniuses->addItem("");
    for (size_t i = 0; i < geniuses.size(); i++)
    {
        GeniusModel genius = geniuses.at(i);
        QString name = QString::fromStdString(genius.getName());
        ui->comboBoxGeniuses->addItem(name);
    }
}

void AddComputer::updateGeniusList(vector<GeniusModel> geniuses)
{
    ui->listWidgetGeniuses->clear();

    for (size_t i = 0; i < geniuses.size(); i++)
    {
        GeniusModel genius = geniuses.at(i);
        QString name = QString::fromStdString(genius.getName());
        ui->listWidgetGeniuses->addItem(name);
    }
}

void AddComputer::on_comboBoxGeniuses_currentIndexChanged(int index)
{
    if (index == 0)
        return;

    GeniusModel genius = _geniuses.at(index - 1);
    _geniuses.erase(_geniuses.begin() + index - 1);
    ui->comboBoxGeniuses->setCurrentIndex(0);
    ui->comboBoxGeniuses->removeItem(index);

    _computerGeniuses.push_back(genius);
    updateGeniusList(_computerGeniuses);
    ui->buttonRemoveGeniuses->setEnabled(false);
}

void AddComputer::on_listWidgetGeniuses_clicked()
{
    ui->buttonRemoveGeniuses->setEnabled(true);
}

void AddComputer::on_buttonRemoveGeniuses_clicked()
{
    int index = ui->listWidgetGeniuses->currentIndex().row();

    GeniusModel genius = _computerGeniuses.at(index);
    QString name = QString::fromStdString(genius.getName());

    _computerGeniuses.erase(_computerGeniuses.begin() + index);

    _geniuses.push_back(genius);
    ui->comboBoxGeniuses->addItem(name);

    updateGeniusList(_computerGeniuses);
    ui->buttonRemoveGeniuses->setEnabled(false);
}
