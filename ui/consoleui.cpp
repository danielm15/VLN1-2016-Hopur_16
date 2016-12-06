#include "ui/consoleui.h"

using namespace std;

ConsoleUI::ConsoleUI()
{

}
// Displays the unsorted list like it is stored in the data file
void ConsoleUI::displayUnsortedList()
{
    cout << "=============| Unsorted list |==============" << endl;
    vector<GeniusModel> GVector = _geniusservice.getGenius();

    for(unsigned int i = 0; i < GVector.size(); i++)
    {
        cout << GVector[i] << endl;
    }
    cout << endl;
}
// Asks the user what variable he would like to sort by and
// then fetches the data with the appropriate sort function for that
// variable, then you have a choice to display the sorted list
// in ascending or descending order
void ConsoleUI::displaySortedList()
{
    cout << "==============| Sorted list |===============" << endl;
    ServiceLayer s;
    vector<GeniusModel> GVector;
    char sortedInput;

    cout << "============================" << endl;
    cout << "Enter a for list sorted by name" << endl;
    cout << "Enter b for list sorted by gender" << endl;
    cout << "Enter c for list sorted by birth year" << endl;
    cout << "Enter d for list sorted by death year" << endl;
    cout << "Enter q to quit" << endl;
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
    else if(sortedInput == 'q' || sortedInput == 'Q')
    {
        clearscreen();
        run();
    }
    else
    {

    }
    char sortby = ' ';
    cout << "============================" << endl;
    cout << "Enter D for order by decending" << endl;
    cout << "Enter A for order by ascending" << endl;
    cout << "Enter Q to quit" << endl;
    cout << "============================" << endl;
    cin >> sortby;

    if (sortby == 'D' || sortby == 'd')
    {
        clearscreen ();
        cout << "==============| Sorted list by Descending order |===============" << endl;

        printVector(GVector);
    }

    else if (sortby == 'A' || sortby == 'a')
    {
        clearscreen ();
        cout << "==============| Sorted list by Ascending order |===============" << endl;

        for(size_t i = GVector.size(); i > 0; i--)
        {
            cout << GVector[i - 1] << endl;
        }
        cout << endl;
    }
    else if(sortby == 'Q' || sortby == 'q')
    {
        clearscreen();
        run();
    }
}

// Puts some restrictions on what kind of data you can input
// with each of the validate functions within the prompt functions
// then saves the input data into the data file
void ConsoleUI::addNewEntryToDataSet()
{
    bool saved = false;
    char gender;
    char input = ' ';
    string name;
    unsigned int dateOfDeath, dateOfBirth;

    GeniusService s;

    while(1)
    {
        clearscreen();
        cout << "===============| Add entry |================" << endl;
        cout << "Enter 1 to add a Genius" << endl;
        cout << "Enter 2 to add a Computer" << endl;
        cin >> input;

        if(input = '1')
        {
            clearscreen();
            name = promptForName();
            gender = promptForGender();
            dateOfBirth = promptForDateOfBirth();
            dateOfDeath = promptForDateOfDeath(name);

            saved = _geniusservice.addGenius(name,gender,dateOfBirth,dateOfDeath);
            break;
        }
        else if(input = '2')
        {
            clearscreen();
            // ///////////////////////// //
            // input Computer validation //
            // ///////////////////////// //
            break;
        }
        else
        {
            cout << "Please enter a valid choice" << endl;
        }
    }

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

// Finds every instance of the searched term
void ConsoleUI::searchForEntries()
{
    string name;

    cout << "===============| Search for entry |================" << endl;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin,name,'\n');

    vector<GeniusModel> filtered = _service.filter(name);
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
        GeniusModel g = _service.find(name);
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

//Clears the console screen
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

void ConsoleUI::printVector(vector<GeniusModel> GVector)
{
    for(unsigned int i = 0; i < GVector.size(); i++)
    {
        cout << GVector[i] << endl;
    }
    cout << endl;
}

