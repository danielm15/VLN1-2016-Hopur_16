#include "addgenius.h"
#include "ui_addgenius.h"

AddGenius::AddGenius(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddGenius)
{
    ui->setupUi(this);

    ui->comboBoxGeniusGender->addItem("Male");
    ui->comboBoxGeniusGender->addItem("Female");

    _computers = _computerService.getComputer();
    updateComputerComboBox(_computers);
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
    {
        GeniusModel genius;

        vector<GeniusModel> geniuses = _geniusService.find(name.toStdString());
        for (size_t i = 0; i < geniuses.size(); i++)
        {
            genius = geniuses.at(i);
            if (genius.getName() == name.toStdString() && genius.getGender() == gender && genius.getBirthYear() == birthYear && genius.getDeathYear() == deathYear)
                break;
        }

        for (size_t i = 0; i < _geniusComputers.size(); i++)
        {
            ComputerModel computer = _geniusComputers.at(i);
            _relationships.getRelationship(computer, genius);
        }
    }

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

void AddGenius::updateComputerComboBox(vector<ComputerModel> computers)
{
    ui->comboBoxComputers->addItem("");
    for (size_t i = 0; i < computers.size(); i++)
    {
        ComputerModel computer = computers.at(i);
        QString name = QString::fromStdString(computer.getModelName());
        ui->comboBoxComputers->addItem(name);
    }
}

void AddGenius::updateComputerList(vector<ComputerModel> computers)
{
    ui->listWidgetComputers->clear();

    for (size_t i = 0; i < computers.size(); i++)
    {
        ComputerModel computer = computers.at(i);
        QString name = QString::fromStdString(computer.getModelName());
        ui->listWidgetComputers->addItem(name);
    }
}

void AddGenius::on_comboBoxComputers_currentIndexChanged(int index)
{
    if (index == 0)
        return;

    ComputerModel computer = _computers.at(index - 1);
    _computers.erase(_computers.begin() + index - 1);
    ui->comboBoxComputers->setCurrentIndex(0);
    ui->comboBoxComputers->removeItem(index);

    _geniusComputers.push_back(computer);
    updateComputerList(_geniusComputers);
}

void AddGenius::on_listWidgetComputers_clicked()
{
    ui->buttonRemoveSelectedComputer->setEnabled(true);
}

void AddGenius::on_buttonRemoveSelectedComputer_clicked()
{
    int index = ui->listWidgetComputers->currentIndex().row();

    ComputerModel computer = _geniusComputers.at(index);
    QString name = QString::fromStdString(computer.getModelName());

    _geniusComputers.erase(_geniusComputers.begin() + index);

    _computers.push_back(computer);
    ui->comboBoxComputers->addItem(name);

    updateComputerList(_geniusComputers);
    ui->buttonRemoveSelectedComputer->setEnabled(false);
}
