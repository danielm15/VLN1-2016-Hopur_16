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
    bool rejected = false;
    bool check = true;
    unsigned int makeYear;
    string makeYearString;

    while (check)
    {
        cout << "Make year: ";
        getline(cin,makeYearString,'\n');

        rejected = validateMakeYear(makeYearString);

        if(!rejected && makeYearString.length() == 1)
        {
            makeYear = atoi(makeYearString.c_str());
        }

        if(check = true)
        {
            cout << "Please enter a valid year" << endl;
        }
    }

    return makeYear;
}

bool ComputerValidation::validateMakeYear(string makeYearString)
{
    bool rejected = false;
    unsigned int makeYear;


    for(unsigned int i = 0; i < makeYearString.length() && !rejected; i++)
    {
        if(isdigit(makeYearString[i]))
            continue;
        rejected = true;
    }

    makeYear = atoi(makeYearString.c_str());

    if(makeYear < 0)
    {
        rejected = true;
    }

    return rejected;
}

string ComputerValidation::promptForType()
{
    string type = "";
    bool check = true;
    bool rejected = false;

    while(check)
    {
        cout << "Type: ";
        cin.ignore();
        getline(cin,type,'\n');
        type[0] = toupper(type[0]);

        rejected = validateType(type);

        if(rejected == true)
        {
            cout << "Type can only contain alphabetic characters and spaces!" << endl;
        }
        else
        {
            check = false;
            cout << "Type successfully entered" << endl;
        }
    }

    return type;
}

bool ComputerValidation::validateType(string type)
{
    bool rejected = false;

    if(type.empty())
        rejected = true;

    for(unsigned int i = 0; i < type.length() && !rejected; i++)
    {
        if(ispunct(type[i]))
            rejected = true;
        if(isalpha(type[i]))
            continue;
        if(type[i] == ' ')
            continue;

        rejected = true;
    }

    return rejected;
}

bool ComputerValidation::promptForBuilt()
{
    bool check = true;
    bool rejected = false;
    string strBuilt;
    char built;

    while(check)
    {
        cout << "Built: ";
        getline(cin,strBuilt,'\n');

        rejected = validateBuilt(strBuilt);

        if(rejected == true)
        {
            cout << "Please enter yes or no!" << endl;
            check = true;
        }
        else
        {
            built = strBuilt[0];
            check = false;
            cout << "Built successfully entered!" << endl;
        }
    }

    return built;
}

bool ComputerValidation::validateBuilt(string built)
{
    bool rejected = false;

    if(built.empty())
        rejected = true;
    if(built.length() != 1)
        rejected = true;
    if((built[0] != 'Y' || built[0] != 'y') && (built[0] != 'N' || built[0] != 'n'))
    {
        rejected = true;
    }

    return rejected;
}
