#include "ui/consoleui.h"

using namespace std;

ConsoleUI::ConsoleUI()
{

}
// Displays the unsorted list like it is stored in the data file
void ConsoleUI::displayUnsortedList()
{
    bool check = true;
    char input = ' ';
    string strinput;

    while(!(input == 'q' || input == 'Q') && check == true)
    {
        clearscreen();
        cout << "=============| Unsorted list |==============" << endl;
        cout << "Enter 1 for unsorted Genius list" << endl;
        cout << "Enter 2 for unsorted Computer list" << endl;
        cout << "Enter q to quit" << endl;
        getline(cin, strinput);

        if(strinput.length() != 1)
        {
            cout << "Please enter a valid choice" << endl;
        }
        else
        {
            input = strinput[0];

            switch(input)
            {
                case '1':
                {
                    clearscreen();
                    cout << "====================| Unsorted Genius list |=================" << endl;
                    vector<GeniusModel> GVector = _geniusservice.getGenius();

                    for(unsigned int i = 0; i < GVector.size(); i++)
                    {
                        cout << GVector[i] << endl;
                    }
                    check = false;
                    cout << endl;
                    break;
                }
                case '2':
                {
                    clearscreen();
                    cout << "====================| Unsorted Computer list |=================" << endl;
                    vector<ComputerModel> CVector = _computerservice.getComputer();

                    for(unsigned int i = 0; i < CVector.size(); i++)
                    {
                        cout << CVector[i] << endl;
                    }
                    check = false;
                    cout << endl;
                    break;
                }
                case 'q':
                case 'Q':
                {
                    clearscreen();
                }
                default:
                {

                }
            }
        }
    }

}
// Asks the user what variable he would like to sort by and
// then fetches the data with the appropriate sort function for that
// variable, then you have a choice to display the sorted list
// in ascending or descending order
void ConsoleUI::displaySortedList()
{
    cout << "==============| Sorted list |===============" << endl;
    vector<GeniusModel> GVector;
    string sortedInput;
    bool isValid = false;

    cout << "======================================" << endl;
    cout << "Enter a for list sorted by name" << endl;
    cout << "Enter b for list sorted by gender" << endl;
    cout << "Enter c for list sorted by birth year" << endl;
    cout << "Enter d for list sorted by death year" << endl;
    cout << "Enter q to quit" << endl;
    cout << "======================================" << endl;

    getline(cin, sortedInput);


    if(sortedInput.length() != 1)
    {
        clearscreen();
        cout << "Incorrect input, try again" << endl;
        return displaySortedList();
    }
    else
    {
        sortedInput = sortedInput[0];

        if(sortedInput == "a" || sortedInput == "A")
        {
            GVector = _service.sortVector();
        }
        else if(sortedInput == "b" || sortedInput == "B")
        {
            GVector = _service.sortByGenderVector();
        }
        else if(sortedInput == "c" || sortedInput == "C")
        {
            GVector = _service.sortByBirthYearVector();
        }
        else if(sortedInput == "d" || sortedInput == "D")
        {
            GVector = _service.sortByDeathYearVector();
        }
        else if(sortedInput == "q" || sortedInput == "Q")
        {
            clearscreen();
            return run();
        }
        else
        {
            clearscreen();
            cout << "Incorrect input, try again" << endl;
            return displaySortedList();
        }
    }


    do
    {
        string sortby;
        clearscreen();
        cout << "============================" << endl;
        cout << "Enter D for order by descending" << endl;
        cout << "Enter A for order by ascending" << endl;
        cout << "Enter Q to quit" << endl;
        cout << "============================" << endl;
        getline(cin, sortby);

        if(sortby.length() != 1)
        {
            clearscreen();
            cout << "Incorrect input, try again" << endl;
        }
        else
        {
            sortby = sortby[0];

            if (sortby == "D" || sortby == "d")
            {
                isValid = true;
                clearscreen ();
                cout << "==============| Sorted list by Descending order |===============" << endl;

                printVector(GVector);
            }

            else if (sortby == "A" || sortby == "a")
            {
                isValid = true;
                clearscreen ();
                cout << "==============| Sorted list by Ascending order |===============" << endl;

                for(size_t i = GVector.size(); i > 0; i--)
                {
                    cout << GVector[i - 1] << endl;
                }
                cout << endl;
            }
            else if(sortby == "Q" || sortby == "q")
            {
                isValid = true;
                clearscreen();
                return run();
            }
            else
            {
                cout << "Incorrect input, try again" << endl;
            }
        }

    }
    while(!isValid);
}

// Puts some restrictions on what kind of data you can input
// with each of the validate functions within the prompt functions
// then saves the input data into the data file
void ConsoleUI::addNewEntryToDataSet()
{
    bool saved = false;
    bool built = false;
    bool check = true;
    char gender;
    char input = ' ';
    string name, modelName, type, strinput;
    unsigned int dateOfDeath, dateOfBirth, makeYear;

    GeniusValidation v;
    ComputerValidation c;

    while(!(input == 'q' || input == 'Q') && check)
    {
        clearscreen();
        cout << "===============| Add entry |================" << endl;
        cout << "Enter 1 to add a Genius" << endl;
        cout << "Enter 2 to add a Computer" << endl;
        cout << "Enter q to quit" << endl;
        getline(cin, strinput);

        if(strinput.length() != 1)
        {
            cout << "Please enter a valid choice" << endl;
        }
        else
        {
            input = strinput[0];

            switch(input)
            {
                case '1':
                {
                    clearscreen();
                    name = v.promptForName();
                    gender = v.promptForGender();
                    dateOfBirth = v.promptForDateOfBirth();
                    dateOfDeath = v.promptForDateOfDeath(name, dateOfBirth);

                    saved = _geniusservice.addGenius(name,gender,dateOfBirth,dateOfDeath);
                    check = false;
                }
                case '2':
                {

                    clearscreen();
                    modelName = c.promptForModelName();
                    makeYear = c.promptForMakeYear();
                    type = c.promptForType();
                    built = c.promptForBuilt();

                    saved = _computerservice.addComputer(modelName,makeYear,type,built);

                    check = false;
                }
                default:
                {
                }
            }
        }

        if(saved == true && check == false)
        {
            cout << "Entry saved" << endl;
        }
        else if(saved == false)
        {
            cerr << "Entry failed" << endl;
        }
        cout << endl;
    }
}

// Finds every instance of the searched term
void ConsoleUI::searchForEntries()
{
    string name;
    char input = ' ';

    cout << "===============| Search for entry |================" << endl;
    cout << "Enter 1 to add a Genius" << endl;
    cout << "Enter 2 to add a Computer" << endl;
    cout << "====================================" << endl;
    cin >> input;

    if(input == '1')
    {
        cout << "Enter name of Genius: ";
        cin.ignore();
        getline(cin,name,'\n');

        vector<GeniusModel> filtered = _geniusservice.find(name);
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
    else if(input == '2')
    {
        cout << "Enter name of computer: ";
        cin.ignore();
        getline(cin,name,'\n');

        vector<ComputerModel> filtered = _computerservice.find(name);
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
    else
    {
        cout << "Please enter a valid choice" << endl;
    }
}

void ConsoleUI::deleteAnEntry()
{
    string name;
    char YorN;
    char input = ' ';

    cout << "===============| Delete entry |================" << endl;
    cout << "Enter 1 to delete a Genius" << endl;
    cout << "Enter 2 to delete a Computer" << endl;
    cout << "===================================" << endl;
    cin >> input;

    if(input == '1')
    {
        cout << "Enter name of Genius: ";
        cin.ignore();
        getline(cin,name,'\n');

        try
        {
            vector<GeniusModel> g = _geniusservice.find(name);
            int option;
            //TODO: Breyta í string til þess að villutékka option

            if (g.size() > 1)
            {
                for(size_t i = 0; i < g.size(); i++)
                {
                    cout << "Option " << i+1 << "  " << g[i] << endl;
                }
                cout << "Please enter the option you would like to delete: " << endl;
                cin >> option;
                if (option > 0 && option < g.size()+1)
                {
                    cout << g[option-1] << endl;
                    cout << "Are you sure you want to delete this entry? (y/n): ";
                    cin >> YorN;
                    if(YorN == 'y' || YorN == 'Y')
                    {
                        _geniusservice.remove(g[option-1]);
                        cout << "Entry was deleted" << endl;
                    }
                    else
                    {
                        cout << "Entry was not deleted" << endl;
                    }
                }
                else
                {
                    cout << "You seem to have entered an unsigned option" << endl;
                }
            }
            else if (g.size() == 1)
            {
                cout << g[0] << endl;
                cout << "Would you like to delete this entry? (y/n): ";
                cin >> YorN;
                if(YorN == 'y' || YorN == 'Y')
                {
                    _geniusservice.remove(g[0]);
                    cout << "Entry was deleted" << endl;
                }
                else
                {
                    cout << "Entry was not deleted" << endl;
                }
            }
            else
            {
                cout << "Please enter a valid choice!" << endl;
            }
        }
        catch(int)
        {
            cerr << "Did not find anything" << endl;
        }
        cout << endl;
    }
    else if(input == '2')
    {
        cout << "Enter name of Computer: ";
        cin.ignore();
        getline(cin,name,'\n');

        try
        {
            vector<ComputerModel> c = _computerservice.find(name);
            int option;
            //TODO: Breyta í string til þess að villutékka option

            if (c.size() > 1)
            {
                for(size_t i = 0; i < c.size(); i++)
                {
                    cout << "Option " << i+1 << "  " << c[i] << endl;
                }
                cout << "Please enter the option you would like to delete: " << endl;
                cin >> option;
                if (option > 0 && option < c.size()+1)
                {
                    cout << c[option-1] << endl;
                    cout << "Are you sure you want to delete this entry? (y/n): ";
                    cin >> YorN;
                    if(YorN == 'y' || YorN == 'Y')
                    {
                        _computerservice.remove(c[option-1]);
                        cout << "Entry was deleted" << endl;
                    }
                    else
                    {
                        cout << "Entry was not deleted" << endl;
                    }
                }
                else
                {
                    cout << "You seem to have entered an unsigned option" << endl;
                }
            }
            else if (c.size() == 1)
            {
                cout << c[0] << endl;
                cout << "Would you like to delete this entry? (y/n): ";
                cin >> YorN;
                if(YorN == 'y' || YorN == 'Y')
                {
                    _computerservice.remove(c[0]);
                    cout << "Entry was deleted" << endl;
                }
                else
                {
                    cout << "Entry was not deleted" << endl;
                }
            }
            else
            {
                cout << "Please enter a valid choice!" << endl;
            }
        }
        catch(int)
        {
            cerr << "Did not find anything" << endl;
        }
        cout << endl;
    }
    else
    {
        cout << "It's rather simple, enter 1 or 2" << endl;
    }
}

void ConsoleUI::run()
{
    string input;

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
        getline(cin, input);

        if (input.size() == 0 || input.size() > 1)
        {
            cout << "*" << input << "*" << " is not valid as an input!" << endl;
            cout << "Please enter a number between 1-5" << endl;
            cout << "or q to quit the application" << endl;
        }
        else if (input.size() == 1)
        {
            switch (input[0])
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
            }
        }
    }while(!(input == "q" || input == "Q"));
}

//Clears the console screen
void ConsoleUI::clearscreen()
{
    system("cls");
}

void ConsoleUI::printVector(vector<GeniusModel> GVector)
{
    for(unsigned int i = 0; i < GVector.size(); i++)
    {
        cout << GVector[i] << endl;
    }
    cout << endl;
}

