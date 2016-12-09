#include "computervalidation.h"

using namespace std;

ComputerValidation::ComputerValidation()
{

}

string ComputerValidation::promptForModelName()
{
    ConsoleUI c;
    bool check = true;
    bool rejected = false;

    string modelName;

    while(check)
    {
        cout << "Model name: ";
        getline(cin,modelName);

        if(modelName == "q" || modelName == "Q")
            leave();

        modelName[0] = toupper(modelName[0]);

        rejected = validateModelName(modelName);

        if(rejected == true)
        {
            system("cls");
            cout << "Name is invalid" << endl;
        }
        else
        {
            system("cls");
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
    if(modelName.length() > 30)
        rejected = true;

    for(unsigned int i = 0; i < modelName.length() && !rejected; i++)
    {
        if(ispunct(modelName[i]))
            rejected = true;
        if(isdigit(modelName[0]))
            rejected = true;
        if(modelName[0] == ' ')
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
    ConsoleUI c;

    while (check)
    {
        cout << "Make year: ";
        getline(cin,makeYearString);

        if(makeYearString == "q" || makeYearString == "Q")
            leave();

        rejected = validateMakeYear(makeYearString);

        if(!rejected && makeYearString.length() == 4)
        {
            makeYear = atoi(makeYearString.c_str());

            if(makeYear > 999 && makeYear < 2017)
            {
                system("cls");
                check = false;
                cout << "Make Year successfully entered" << endl;
            }
            else
            {
                system("cls");
                check = true;
                cout << "Please enter a valid year" << endl;
            }
        }
        else
        {
            system("cls");
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
    ConsoleUI c;

    while(check)
    {
        cout << endl;
        cout << "1 = Mechanical, 2 = Electronic" << endl;
        cout << "3 = Electromechanical, 4 = Integrated circuit" << endl;
        cout << endl;
        cout << "Type: ";
        getline(cin,type);

        if(type == "q" || type == "Q")
            leave();

        rejected = validateType(type);

        if(rejected == true)
        {
            system("cls");
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

            system("cls");
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

    if(type != "1" && type != "2" && type != "3" && type != "4")
    {
        rejected = true;
    }

    return rejected;
}

int ComputerValidation::promptForBuilt()
{
    bool check = true;
    bool rejected = false;
    string strBuilt;
    int built;
    ConsoleUI c;

    while(check)
    {
        cout << "Built(y/n): ";
        getline(cin,strBuilt);

        if(strBuilt == "q" || strBuilt == "Q")
            leave();

        rejected = validateBuilt(strBuilt);

        if(rejected == true)
        {
            system("cls");
            cout << "Please enter y or n!" << endl;
            check = true;
        }
        else
        {
            if(strBuilt == "Y" || strBuilt == "y")
            {
                built = 1;
            }
            else if (strBuilt == "N" || strBuilt == "n")
            {
                built = 0;
            }
            check = false;
            cout << "Built successfully entered!" << endl;
        }
    }
    return built;
}

bool ComputerValidation::validateBuilt(string strBuilt)
{
    bool rejected = false;

    if(strBuilt.empty())
        rejected = true;
    if(strBuilt.length() != 1)
        rejected = true;
    if(strBuilt != "Y" && strBuilt != "y" && strBuilt != "N" && strBuilt != "n")
    {
        rejected = true;
    }
    return rejected;
}

void ComputerValidation::leave()
{
    ConsoleUI c;
    system("cls");
    c.run();
}
