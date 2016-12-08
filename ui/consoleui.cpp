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
    vector<ComputerModel> CVector;
    string sortedInput, selectSort, sortBy;
    bool isValid = false;
    bool check = true;

    cout << "============================" << endl;
    cout << "Enter 1 to sort Geniuses" << endl;
    cout << "Enter 2 to sort Computers" << endl;
    cout << "Enter q to quit" << endl;
    cout << "============================" << endl;
    getline(cin, selectSort);

    if(selectSort.length() != 1 || (selectSort != "1" && selectSort != "2" && selectSort != "q" && selectSort != "Q"))
    {
        clearscreen();
        cout << "Incorrect input, try again" << endl;
        return displaySortedList();
    }
    else
    {
        selectSort = selectSort[0];

        if(selectSort == "1")
        {
            clearscreen();
            printGeniusSort();
        }
        else if(selectSort == "2")
        {
            clearscreen();
            printComputerSort();
        }
        else
        {
            clearscreen();
            return run();
        }


        while(!isValid)
        {
            getline(cin, sortedInput);

            if(sortedInput.length() != 1 || (sortedInput != "a" && sortedInput != "A"
                                             && sortedInput != "b" && sortedInput != "B"
                                             && sortedInput != "c" && sortedInput != "C"
                                             && sortedInput != "d" && sortedInput != "D"
                                             && sortedInput != "q" && sortedInput != "Q"))
            {
                clearscreen();
                cout << "Incorrect input, try again" << endl;
                isValid = false;
            }
            else
            {
                sortedInput = sortedInput[0];
                isValid = true;

                while(check)
                {
                    clearscreen();
                    cout << "============================" << endl;
                    cout << "Enter A for order by ascending" << endl;
                    cout << "Enter D for order by descending" << endl;
                    cout << "Enter Q to quit" << endl;
                    cout << "============================" << endl;
                    getline(cin, sortBy);

                    if(sortBy.length() != 1)
                    {
                        clearscreen();
                        cout << "Incorrect input, try again" << endl;
                        check = true;
                    }
                    else if(sortBy[0] == 'a' || sortBy[0] == 'A' || sortBy[0] == 'd' || sortBy[0] == 'D')
                    {
                        sortBy = sortBy[0];

                        if(selectSort == "1")
                        {
                            GVector = _geniusservice.sortGenius(sortedInput, sortBy);

                            clearscreen();
                            cout << "==============| Sorted list |===============" << endl;
                            printGVector(GVector);
                            check = false;
                        }
                        else if(selectSort == "2")
                        {
                            CVector = _computerservice.sortComputer(sortedInput, sortBy);

                            clearscreen();
                            cout << "==============| Sorted list |===============" << endl;
                            printCVector(CVector);
                            check = false;
                        }
                    }
                    else
                    {
                        return run();
                    }
                }
            }
        }
    }
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
<<<<<<< HEAD

=======
>>>>>>> b6020f26d91ce2b3f7a67eab1b08b6da7c2429eb
                    clearscreen();
                    modelName = c.promptForModelName();
                    makeYear = c.promptForMakeYear();
                    type = c.promptForType();
                    built = c.promptForBuilt();

                    saved = _computerservice.addComputer(modelName,makeYear,type,built);
<<<<<<< HEAD

=======
>>>>>>> b6020f26d91ce2b3f7a67eab1b08b6da7c2429eb
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
    string inputString;

    cout << "===============| Search for entry |================" << endl;
    cout << "Enter 1 to add a Genius" << endl;
    cout << "Enter 2 to add a Computer" << endl;
    cout << "====================================" << endl;
    getline(cin,inputString,'\n');

    if(inputString.length() != 1)
    {
        cout << "Please enter a valid choice" << endl;
    }
    else
    {
    if(input == '1')
    {
        cout << "Enter name of Genius: ";
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
}

void ConsoleUI::deleteAnEntry()
{
    string name;
    char YorN;
    char input = ' ';
    string inputString;

    cout << "===============| Delete entry |================" << endl;
    cout << "Enter 1 to delete a Genius" << endl;
    cout << "Enter 2 to delete a Computer" << endl;
    cout << "===================================" << endl;
    getline(cin,inputString,'\n');

    if(inputString.length() != 1)
    {
        cout << "Please enter a valid choice" << endl;
    }
    else
    {
        input = inputString[0];
        if(input == '1')
        {
         cout << "Enter name of Genius: ";
         getline(cin,name,'\n');


        try
        {
             bool check = true;
             do
             {
                vector<GeniusModel> g = _geniusservice.find(name);
                int option;
                //TODO: Breyta í string til þess að villutékka option


                if (g.size() > 1)
                {
                    check = false;
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
                    check = false;
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
                    check = true;
                    cout << "Please enter a valid choice!" << endl;
                    cout << "Enter name of Genius" << endl;
                    getline(cin, name,'\n');
                }
            }while(check == true);
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

void ConsoleUI::printGVector(vector<GeniusModel> GVector)
{
    for(unsigned int i = 0; i < GVector.size(); i++)
    {
        cout << GVector[i] << endl;
    }
    cout << endl;
}

void ConsoleUI::printCVector(vector<ComputerModel> CVector)
{
    for(unsigned int i = 0; i < CVector.size(); i++)
    {
        cout << CVector[i] << endl;
    }
    cout << endl;
}

void ConsoleUI::printGeniusSort()
{
    cout << "============= Sort Genius ============" << endl;
    cout << "Enter a for list sorted by Name" << endl;
    cout << "Enter b for list sorted by Gender" << endl;
    cout << "Enter c for list sorted by Birth year" << endl;
    cout << "Enter d for list sorted by Death year" << endl;
    cout << "Enter q to quit" << endl;
    cout << "======================================" << endl;
}
void ConsoleUI::printComputerSort()
{
    cout << "=========== Sort Computer ============" << endl;
    cout << "Enter a for list sorted by Model name" << endl;
    cout << "Enter b for list sorted by Make year" << endl;
    cout << "Enter c for list sorted by Type" << endl;
    cout << "Enter d for list sorted by Built" << endl;
    cout << "Enter q to quit" << endl;
    cout << "======================================" << endl;
}

