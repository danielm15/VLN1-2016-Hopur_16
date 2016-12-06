#include "geniusvalidation.h"

using namespace std;

GeniusValidation::GeniusValidation()
{

}

string GeniusValidation::promptForName()
{
    bool check = true;
    bool rejected = false;
    string name = "";

    while(check)
    {

        cout << "Name: ";
        cin.ignore();
        getline(cin,name,'\n');
        name[0] = toupper(name[0]);

        rejected = validateName(name);

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
    return name;
}

// Returns a bool value that is false if the name
// has no invalid characters i.e. is only alphabetic
// characters or spaces
bool GeniusValidation::validateName(string name)
{
    bool rejected = false;
    for(unsigned int i = 0; i < name.length() && !rejected; i++)
    {
        if(ispunct(name[i]))
            rejected = true;
        if(isalpha(name[i]))
            continue;
        if(name[i] == ' ')
            continue;

        rejected = true;
    }
    return rejected;
}

char GeniusValidation::promptForGender()
{
    // Gender check fall
    bool check = true;
    bool rejected = false;
    string strgender;
    char gender;

    while(check)
    {
        cout << "Gender (m/f): ";
        getline(cin,strgender,'\n');

        rejected = validateGender(strgender);

        if(rejected == true)
        {
            cout << "Please enter m for male or f for female" << endl;
            check = true;
        }
        else
        {
            gender = strgender[0];
            check = false;
            cout << "Gender successfully entered" << endl;
        }
    }
    return gender;
}

// Returns a bool value that is false only if the
// gender input is m or f non-case sensitive
bool GeniusValidation::validateGender(string strgender)
{
    bool rejected;
    char gender = ' ';
    if(strgender.size() == 1)
    {
        rejected = false;
        gender = strgender[0];
    }
    else
    {
        rejected = true;
    }

    if(gender == 'm' || gender == 'M' || gender == 'f' || gender == 'F')
    {
        rejected = false;
    }
    else
    {
        rejected = true;
    }

    return rejected;
}

unsigned int GeniusValidation::promptForDateOfBirth()
{
    //Year of birth check fall
    bool rejected = false;
    bool check = true;
    string strdateOfBirth;
    unsigned int dateOfBirth;

    while(check)
    {
        cout << "Year of birth: ";
        getline(cin,strdateOfBirth,'\n');

        rejected = validateDateOfBirth(strdateOfBirth);

        if(!rejected && strdateOfBirth.length() == 4)
        {
            dateOfBirth = atoi(strdateOfBirth.c_str());

            if(dateOfBirth > 999 && dateOfBirth < 2017)
            {
                check = false;
                cout << "Year of birth successfully entered" << endl;
            }
            else
            {
                check = true;
                cout << "Please enter a valid date of birth" << endl;
            }
        }
        else
        {
            check = true;
            cout << "Please enter a valid date of birth" << endl;
        }
    }
    return dateOfBirth;
}

// returns false if every letter in string is a number
bool GeniusValidation::validateDateOfBirth(string date)
{
    bool rejected = false;
    for(unsigned int i = 0; i < date.length() && !rejected; i++)
    {
        if(isdigit(date[i]))
            continue;
        rejected = true;
    }
    return rejected;
}

unsigned int GeniusValidation::promptForDateOfDeath(string name)
{
    //Year of death check fall
    bool rejected = false;
    bool check = true;
    string strdateOfDeath;
    unsigned int dateOfDeath;

    while(check)
    {
        cout << " ~ Enter 0 if person is alive ~ " << endl;
        cout << "Year of death: ";
        getline(cin,strdateOfDeath,'\n');

        if(!rejected && strdateOfDeath.length() == 1)
        {
            dateOfDeath = atoi(strdateOfDeath.c_str());

            if(dateOfDeath == 0)
            {
                check = false;
                cout << "Yay" << " " <<  name << " is still alive" << endl;
            }
        }
        else if(!rejected && strdateOfDeath.length() == 4)
        {
            dateOfDeath = atoi(strdateOfDeath.c_str());

            if(dateOfDeath > 999 && dateOfDeath < 2017)
            {
                check = false;
                cout << "Year of death successfully entered" << endl;
            }
            else
            {
                check = true;
                cout << "Please enter a valid date of death" << endl;
            }
        }
        else
        {
            check = true;
            cout << "Please enter a valid date of death" << endl;
        }
    }
    return dateOfDeath;
}

// returns false if every letter in string is a number
bool GeniusValidation::validateDateOfDeath(string date)
{
    bool rejected = false;
    for(unsigned int i = 0; i < date.length() && !rejected; i++)
    {
        if(isdigit(date[i]))
            continue;
        rejected = true;
    }
    return rejected;
}
