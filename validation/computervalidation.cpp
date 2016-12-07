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

        cout << "Model name: ";
        cin.ignore();
        getline(cin,modelName,'\n');
        modelName[0] = toupper(modelName[0]);

        rejected = validateModelName(modelName);

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
    bool rejected = false;

    if(modelName.empty())
        rejected = true;

    for(unsigned int i = 0; i < modelName.length() && !rejected; i++)
    {
        if(ispunct(modelName[i]))
            rejected = true;
        if(isdigit(modelName[0]))
            rejected = true;
        if(isalnum(modelName[i]))
            continue;
        if(modelName[i] == ' ')
            continue;

        rejected = true;
    }
    return rejected;
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
