#include "computervalidation.h"

using namespace std;

ComputerValidation::ComputerValidation()
{

}

string ComputerValidation::promptForModelName()
{
    bool check = true;
    bool rejected = false;

    string modelName;

    while(check)
    {

        cout << "Model name: ";
        getline(cin,modelName);
        modelName[0] = toupper(modelName[0]);

        rejected = validateModelName(modelName);

        if(rejected == true)
        {
            cout << "Name is invalid" << endl;
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
    if(modelName.length() > 40)
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
        getline(cin,makeYearString);

        rejected = validateMakeYear(makeYearString);

        if(!rejected && makeYearString.length() == 4)
        {
            makeYear = atoi(makeYearString.c_str());

            if(makeYear > 999 && makeYear < 2017)
            {
                check = false;
                cout << "Make Year successfully entered" << endl;
            }
            else
            {
                check = true;
                cout << "Please enter a valid year" << endl;
            }
        }
        else
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

    return rejected;
}

string ComputerValidation::promptForType()
{
    string type;
    bool check = true;
    bool rejected = false;

    while(check)
    {
        cout << endl;
        cout << "1 = Mechanical, 2 = Electronic, 3 = Electromechanical, 4 = Integrated circuit" << endl;
        cout << "Type: ";
        getline(cin,type);

        rejected = validateType(type);

        if(rejected == true)
        {
            cout << "Please enter 1,2,3 or 4 to specify type" << endl;
        }
        else
        {
            if(type == "1")
                type = "Mechanical";
            else if(type == "2")
                type = "Electronic";
            else if(type == "3")
                type = "Electromechanical";
            else if(type == "4")
                type = "Integrated circuit";

            check = false;
            break;
            cout << "Type successfully entered" << endl;
        }
    }

    return type;
}

bool ComputerValidation::validateType(string type)
{
    bool rejected = false;

    if(type.empty())
    {
        rejected = true;
    }

    if(type != "1" || type != "2" || type != "3" || type != "4")
    {
        rejected = true;
    }

    return rejected;
}

bool ComputerValidation::promptForBuilt()
{
    bool check = true;
    bool rejected = false;
    string strBuilt;
    bool built = true;

    while(check)
    {
        cout << "Built(y/n): ";
        getline(cin,strBuilt,'\n');

        rejected = validateBuilt(strBuilt);

        if(rejected == true)
        {
            cout << "Please enter y or n!" << endl;
            check = true;
        }
        else
        {
            if(strBuilt[0] == 'Y' || strBuilt[0] == 'y')
            {
                built = true;
            }
            else if (strBuilt[0] == 'N' || strBuilt[0] == 'n')
            {
                built = false;
            }
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
    if((built[0] != 'Y' && built[0] != 'y') && (built[0] != 'N' && built[0] != 'n'))
    {
        rejected = true;
    }

    return rejected;
}
