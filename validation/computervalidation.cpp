#include "computervalidation.h"

using namespace std;

ComputerValidation::ComputerValidation()
{

}

string ComputerValidation::promptForModelName()
{
    bool check = true;
    bool rejected = false;

    string modelName = "";

    while(check)
    {

        cout << "Modelname: ";
        cin.ignore();
        getline(cin,modelName,'\n');
        modelName[0] = toupper(modelName[0]);

       // rejected = validateName(name);

        if(rejected == true)
        {
            cout << "Name can only contain alphabetic characters and spaces!" << endl;
        }
        else
        {
            check = false;
            cout << "Name successfully entered" << endl;
        }
    }
    return modelName;
}

bool ComputerValidation::validateModelName(string modelName)
{
    return true;
}

unsigned int ComputerValidation::promptForMakeYear()
{
    unsigned int makeYear;
    return makeYear;
}

bool ComputerValidation::validateMakeYear(unsigned int makeYear)
{
    return true;
}

string ComputerValidation::promptForType()
{
    string type;
    return type;
}

bool ComputerValidation::validateType(string type)
{
    return true;
}

bool ComputerValidation::promptForBuilt()
{
    bool built;
    return built;
}

bool ComputerValidation::validateBuilt(bool built)
{
    return true;
}
