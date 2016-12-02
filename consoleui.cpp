#include "consoleui.h"

using namespace std;

ConsoleUI::ConsoleUI()
{

}

void wait()
{
  //  Sleep(1000);
}

void ConsoleUI::displayUnsortedList()
{
    cout << "=============| Unsorted list |==============" << endl;
    vector<Genius> GVector = _service.getGenius();

    for(unsigned int i = 0; i < GVector.size(); i++)
    {
        cout << GVector[i] << endl;
    }
    cout << endl;
}

void ConsoleUI::displaySortedList()
{
    cout << "==============| Sorted list |===============" << endl;
    ServiceLayer s;
    vector<Genius> GVector;
    char sortedInput;

    cout << "============================" << endl;
    cout << "Enter a for list sorted by name" << endl;
    cout << "Enter b for list sorted by gender" << endl;
    cout << "Enter c for list sorted by birth year" << endl;
    cout << "Enter d for list sorted by death year" << endl;
    cout << "============================" << endl;
    cin >> sortedInput;

    if(sortedInput == 'a' || sortedInput == 'A')
    {
        GVector = s.sortVector();
    }
    else if(sortedInput == 'b' || sortedInput == 'B')
    {
        GVector = s.sortByGenderVector();
    }
    else if(sortedInput == 'c' || sortedInput == 'C')
    {
        GVector = s.sortByBirthYearVector();
    }
    else if(sortedInput == 'd' || sortedInput == 'D')
    {
        GVector = s.sortByDeathYearVector();
    }
    else
    {

    }
    char sortby = ' ';
    cout << "============================" << endl;
    cout << "Enter D for order by decending" << endl;
    cout << "Enter A for order by ascending" << endl;
    cout << "============================" << endl;
    cin >> sortby;

    if ('D' == sortby || 'd' == sortby)
    {
        clearscreen ();
        cout << "==============| Sorted list by Descending order |===============" << endl;
        for(unsigned int i = 0; i < GVector.size(); i++)
        {
            cout << GVector[i] << endl;
        }
        cout << endl;
    }

    else if ('A' == sortby || 'a' == sortby)
    {
        clearscreen ();
        cout << "==============| Sorted list by Ascending order |===============" << endl;

        for(int i = GVector.size()-1; i >= 0; i--)
        {
            cout << GVector[i] << endl;
        }
        cout << endl;
    }
}

void ConsoleUI::addNewEntryToDataSet()
{
    bool saved = false;
    char gender;
    string name;
    unsigned int dateOfDeath, dateOfBirth;;

    ServiceLayer s;

    cout << "===============| Add entry |================" << endl;

    name = promptForName();
    gender = promptForGender();
    dateOfBirth = promptForDateOfBirth();
    dateOfDeath = promptForDateOfDeath(name);

    saved = _service.addEntry(name,gender,dateOfBirth,dateOfDeath);

    if(saved == true)
    {
        cout << "Entry saved" << endl;
    }
    else
    {
        cerr << "Entry failed" << endl;
    }
    cout << endl;
}

void ConsoleUI::searchForEntries()
{
    string name;

    cout << "===============| Search for entry |================" << endl;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin,name,'\n');

    vector<Genius> filtered = _service.filter(name);
    for(size_t i = 0; i < filtered.size(); i++)
    {
        cout << filtered[i] << endl;
    }

    if (filtered.size() == 0)
    {
        cout << "No results found" << endl;
    }
    cout << endl;
}

void ConsoleUI::deleteAnEntry()
{
    string name;
    char YorN;

    cout << "===============| Delete entry |================" << endl;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin,name,'\n');

    try
    {
        Genius g = _service.find(name);
        cout << g << endl;
        cout << "Would you like to delete this entry? (y/n): ";
        cin >> YorN;
        if(YorN == 'y' || YorN == 'Y')
        {
            _service.removeEntry(g);
        }
        else
        {
            cout << "Entry was not deleted" << endl;
        }

    }
    catch(int)
    {
        cerr << "Did not find anything" << endl;
    }
    cout << endl;
}

void ConsoleUI::run()
{
    char input = ' ';

    do
    {
        cout << "============================" << endl;
        cout << "Enter 1 for Unsorted list" << endl;
        cout << "Enter 2 for Sorted list" << endl;
        cout << "Enter 3 to Add entry" << endl;
        cout << "Enter 4 to Search for entry" << endl;
        cout << "Enter 5 to Delete an entry" << endl;
        cout << "Enter q to Quit" << endl;
        cout << "============================" << endl;
        cin >> input;


        switch (input)
        {
        case '1':
        {
            clearscreen ();
            displayUnsortedList();
            break;
        }
        case '2':
        {
           clearscreen ();
           displaySortedList();

            break;
        }
        case '3':
        {
            clearscreen ();
            addNewEntryToDataSet();
            break;
        }
        case '4':
        {
            clearscreen ();
            searchForEntries();
            break;
        }
        case '5':
        {
            clearscreen ();
            deleteAnEntry();
            break;
        }
        case 'q':
        {
            clearscreen ();
            break;
        }
        default:
        {
            cout << "*" << input << "*" << " is not valid as an input!" << endl;
            cout << "Please enter a number between 1-5" << endl;
            cout << "or q to quit the application" << endl;
            break;
        }

    }

    }while(!(input == 'q' || input == 'Q'));

}

void ConsoleUI::clearscreen ()
{
    system("cls");
}

string ConsoleUI::promptForName()
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
            wait();
        }
        else
        {
            check = false;
            cout << "Name successfully entered" << endl;
            wait();
        }
        clearscreen();
    }
    return name;
}

bool ConsoleUI::validateName(string name)
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

char ConsoleUI::promptForGender()
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
            wait();
        }
        else
        {
            gender = strgender[0];
            check = false;
            cout << "Gender successfully entered" << endl;
            wait();
        }
        clearscreen();
    }
    return gender;
}

bool ConsoleUI::validateGender(string strgender)
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

unsigned int ConsoleUI::promptForDateOfBirth()
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

            if(dateOfBirth > 999 || dateOfBirth < 2017)
            {
                check = false;
                cout << "Year of birth successfully entered" << endl;
                wait();
            }
        }
        else
        {
            check = true;
            cout << "Please enter a valid date of birth" << endl;
            wait();
        }
        clearscreen();
    }
    return dateOfBirth;
}

bool ConsoleUI::validateDateOfBirth(string date)
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

unsigned int ConsoleUI::promptForDateOfDeath(string name)
{
    //Year of death check fall
    bool rejected = false;
    bool check = true;
    string strdateOfDeath;
    unsigned int dateOfDeath;

    while(check)
    {
        cout << "Enter 0 if person is alive" << endl;
        cout << "Year of death: ";
        getline(cin,strdateOfDeath,'\n');


        if(!rejected && strdateOfDeath.length() == 1)
        {
            dateOfDeath = atoi(strdateOfDeath.c_str());

            if(dateOfDeath == 0)
            {
                check = false;
                cout << "Yay" << " " <<  name << " is still alive" << endl;
                wait();
            }
        }
        else if(!rejected && strdateOfDeath.length() == 4)
        {
            dateOfDeath = atoi(strdateOfDeath.c_str());

            if(dateOfDeath > 999 && dateOfDeath < 2017)
            {
                check = false;
                cout << "Year of death successfully entered" << endl;
                wait();
            }
        }
        else
        {
            check = true;
            cout << "Please enter a valid date of death" << endl;
            wait();
        }
        clearscreen();
    }
    return dateOfDeath;
}

bool ConsoleUI::validateDateOfDeath(string date)
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

