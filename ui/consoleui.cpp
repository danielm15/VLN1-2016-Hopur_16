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
    string strInput;

    while(!(input == 'q' || input == 'Q') && check == true)
    {
        cout << "================= Unsorted list ==================" << endl;
        cout << "| Enter 1 for unsorted Genius list               |" << endl;
        cout << "| Enter 2 for unsorted Computer list             |" << endl;
        cout << "| Enter 3 for unsorted Geniuses & Computers list |" << endl;
        cout << "| Enter 4 for unsorted Computers & Geniuses list |" << endl;
        cout << "| Enter q to quit                                |" << endl;
        cout << "==================================================" << endl;

        getline(cin, strInput);

        if(strInput.length() != 1 || (strInput != "1" && strInput != "2" && strInput != "3" && strInput != "4" && strInput != "q" && strInput != "Q"))
        {
            clearscreen();
            printError();
        }
        else
        {
            input = strInput[0];

            switch(input)
            {
                case '1':
                {
                    clearscreen();
                    cout << "========================================================"<< endl;
                    cout << "================== Unsorted Genius list ================" << endl;
                    cout << "========================================================"<< endl;
                    cout << setw(26) << left << " Name" << setw(6) << "Gender" << "  " << " BirthYear" << " - " << "DeathYear" << endl;
                    cout << "========================================================"<< endl;
                    vector<GeniusModel> GVector = _geniusservice.getGenius();

                    for(unsigned int i = 0; i < GVector.size(); i++)
                    {
                        cout << GVector[i] << endl;
                        cout << "|------------------------------------------------------|" << endl;
                    }
                    check = false;
                    cout << "========================================================" << endl;
                    cout << endl;
                    break;
                }
                case '2':
                {
                    clearscreen();
                    cout << "========================================================================" << endl;
                    cout << "======================== Unsorted Computer list ========================" << endl;
                    cout << "========================================================================" << endl;
                    cout << setw(26)<< left << " Model Name" << setw(2) << " " << "Make Year" << "   " << setw(21) << "Type" << " " << "Built(Y/N)" << endl;
                    cout << "========================================================================" << endl;
                    vector<ComputerModel> CVector = _computerservice.getComputer();

                    for(unsigned int i = 0; i < CVector.size(); i++)
                    {
                        cout << CVector[i] << endl;
                        cout << "|----------------------------------------------------------------------|" << endl;
                    }
                    check = false;
                    cout << "========================================================================" << endl;
                    cout << endl;
                    break;
                }
                case '3':
                {
                    clearscreen();
                    cout << "========================================================" << endl;
                    cout << "========== Unsorted Geniuses & Computers list ==========" << endl;
                    cout << "========================================================" << endl;
                    cout << setw(26) << left << " Name" << setw(6) << "Gender" << "  " << " BirthYear" << " - " << "DeathYear" << endl;
                    cout << "========================================================" << endl;
                    vector<GeniusModel> GVector = _geniusservice.getGenius();

                    for(unsigned int i = 0; i < GVector.size(); i++)
                    {
                        cout << GVector[i] << endl;

                        vector<ComputerModel> computers = _geniusservice.getAllComputersGeniusBuilt(GVector[i]);

                        cout << "|   " << "- Linked computers" << endl;
                        for (unsigned int i= 0; i < computers.size(); i++)
                        {
                            cout << "|" << "\t" << computers[i].getModelName() << endl;
                        }
                        cout << "|-------------------------------------------------------" << endl;
                    }
                    check = false;
                    cout << "========================================================" << endl;
                    break;
                }
                case '4':
                {
                    clearscreen();
                    cout << "========================================================================" << endl;
                    cout << "================== Unsorted Computers & Geniuses list ==================" << endl;
                    cout << "========================================================================" << endl;
                    cout << setw(26)<< left << " Model Name" << setw(2) << " " << "Make Year" << "   " << setw(21) << "Type" << " " << "Built(Y/N)" << endl;
                    cout << "========================================================================" << endl;
                    vector<ComputerModel> CVector = _computerservice.getComputer();

                    for(unsigned int i = 0; i < CVector.size(); i++)
                    {
                        cout << CVector[i] << endl;

                        vector<GeniusModel> geno = _computerservice.getAllGeniusesWhoBuiltComputer(CVector[i]);

                        cout << "|   " << "- Made by" << endl;
                        for (unsigned int i= 0; i < geno.size(); i++)
                        {
                            cout << "|" << "\t" << geno[i].getName() << endl;

                        }
                        cout << "|-----------------------------------------------------------------------" << endl;
                    }
                    check = false;
                        cout << "========================================================================" << endl;
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
    vector<GeniusModel> GVector;
    vector<ComputerModel> CVector;
    string sortedInput, selectSort, sortBy;
    bool isValid = false;
    bool doubleCheck = true;
    bool check = true;

    while(check || (selectSort != "q" && selectSort != "Q"))
    {
        cout << "============== Sort list ===============" << endl;
        cout << "| Enter 1 to sort Geniuses             |" << endl;
        cout << "| Enter 2 to sort Computers            |" << endl;
        cout << "| Enter 3 to sort Geniuses & Computers |" << endl;
        cout << "| Enter 4 to sort Computers & Geniuses |" << endl;
        cout << "| Enter q to quit                      |" << endl;
        cout << "========================================" << endl;

        getline(cin, selectSort);

        if(selectSort.length() != 1 || (selectSort != "1" && selectSort != "2" && selectSort != "3" && selectSort != "4" && selectSort != "q" && selectSort != "Q"))
        {
            clearscreen();
            printError();
            check = true;
        }
        else if(selectSort == "q" || selectSort == "Q")
        {
            clearscreen();
            check = false;
            break;
        }
        else
        {
            clearscreen();
            while(!isValid || sortedInput != "q" || sortedInput != "Q")
            {
                selectSort = selectSort[0];

                if(selectSort == "1" || selectSort == "3")
                {
                    printGeniusSort();
                }
                else if(selectSort == "2" || selectSort == "4")
                {
                    printComputerSort();
                }
                else
                {
                    clearscreen();
                    printError();
                    break;
                }
                getline(cin, sortedInput);

                if(sortedInput.length() != 1 || (sortedInput != "a" && sortedInput != "A"
                                                 && sortedInput != "b" && sortedInput != "B"
                                                 && sortedInput != "c" && sortedInput != "C"
                                                 && sortedInput != "d" && sortedInput != "D"
                                                 && sortedInput != "q" && sortedInput != "Q"))
                {
                    clearscreen();
                    printError();
                    isValid = false;
                }
                else if(sortedInput == "q" || sortedInput == "Q")
                {
                    isValid = true;
                    clearscreen();
                    break;
                }
                else
                {
                    sortedInput = sortedInput[0];
                    doubleCheck = true;
                    clearscreen();
                    while(doubleCheck)
                    {
                        cout << "=========== ASC & DESC ? ==========" << endl;
                        cout << "| Enter A for order by ascending  |" << endl;
                        cout << "| Enter D for order by descending |" << endl;
                        cout << "| Enter Q to quit                 |" << endl;
                        cout << "===================================" << endl;
                        getline(cin, sortBy);

                        if(sortBy.length() != 1 || (sortBy != "A" && sortBy != "a" && sortBy != "D" && sortBy != "d"))
                        {
                            clearscreen();
                            printError();
                            doubleCheck = true;
                        }
                        else if(sortBy == "a" || sortBy == "A" || sortBy == "d" || sortBy == "D")
                        {
                            sortBy = sortBy[0];

                            if(selectSort == "1")
                            {
                                GVector = _geniusservice.sortGenius(sortedInput, sortBy);

                                clearscreen();
                                printGVector(GVector);
                                check = false;
                            }
                            else if(selectSort == "2")
                            {
                                CVector = _computerservice.sortComputer(sortedInput, sortBy);

                                clearscreen();
                                printCVector(CVector);
                                check = false;
                            }
                            else if(selectSort == "3")
                            {
                                clearscreen();
                                cout << "========================================================" << endl;
                                cout << "========== Sorted Geniuses & Computers list ==========" << endl;
                                cout << "========================================================" << endl;
                                cout << setw(26) << left << " Name" << setw(6) << "Gender" << "  " << " BirthYear" << " - " << "DeathYear" << endl;
                                cout << "========================================================" << endl;
                                vector<GeniusModel> GVector = _geniusservice.sortGenius(sortedInput, sortBy);

                                for(unsigned int i = 0; i < GVector.size(); i++)
                                {
                                    cout << GVector[i] << endl;

                                    vector<ComputerModel> computers = _geniusservice.getAllComputersGeniusBuilt(GVector[i]);

                                    cout << "|   " << "- Linked computers" << endl;
                                    for (unsigned int i= 0; i < computers.size(); i++)
                                    {
                                        cout << "|" << "\t" << computers[i].getModelName() << endl;
                                    }
                                    cout << "|-------------------------------------------------------" << endl;
                                }
                                check = false;
                                cout << "========================================================" << endl;
                                break;
                            }
                            else if(selectSort == "4")
                            {
                                clearscreen();
                                cout << "========================================================================" << endl;
                                cout << "================== Sorted Computers & Geniuses list ==================" << endl;
                                cout << "========================================================================" << endl;
                                cout << setw(26)<< left << " Model Name" << setw(2) << " " << "Make Year" << "   " << setw(21) << "Type" << " " << "Built(Y/N)" << endl;
                                cout << "========================================================================" << endl;
                                CVector = _computerservice.sortComputer(sortedInput, sortBy);

                                for(unsigned int i = 0; i < CVector.size(); i++)
                                {
                                    cout << CVector[i] << endl;

                                    vector<GeniusModel> geno = _computerservice.getAllGeniusesWhoBuiltComputer(CVector[i]);

                                    cout << "|   " << "- Made by" << endl;
                                    for (unsigned int i= 0; i < geno.size(); i++)
                                    {
                                        cout << "|" << "\t" << geno[i].getName() << endl;

                                    }
                                    cout << "|-----------------------------------------------------------------------" << endl;
                                }
                                check = false;
                                cout << "========================================================================" << endl;
                                break;
                            }
                            doubleCheck = false;
                        }
                        else if(sortBy == "q" || sortBy == "Q")
                        {
                            clearscreen();
                            doubleCheck = false;
                            break;
                        }
                        else
                        {
                            clearscreen();
                            printError();
                        }
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
    string name, modelName, type, strInput;
    unsigned int dateOfDeath, dateOfBirth, makeYear;

    GeniusValidation v;
    ComputerValidation c;

    while(!(strInput == "q" || strInput == "Q") && check)
    {
        cout << "============ Add entry =============" << endl;
        cout << "| Enter 1 to add a Genius          |" << endl;
        cout << "| Enter 2 to add a Computer        |" << endl;
        cout << "| Enter Q to quit                  |" << endl;
        cout << "====================================" << endl;
        getline(cin, strInput);

        if(strInput.length() != 1 || (strInput != "1" && strInput != "2" && strInput != "q" && strInput != "Q"))
        {
            clearscreen();
            printError();
        }
        else if(strInput == "q" || strInput == "Q")
        {
            clearscreen();
            break;
        }
        else
        {
            input = strInput[0];

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
                    break;
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
                    break;
                }
                default:
                {
                }
            }

            if(saved == true && check == false)
            {
                cout << "Entry saved" << endl;
            }
            else if(saved == false)
            {
                cerr << "Entry failed!" << endl;
            }
            cout << endl;
        }

    }
}

// Finds every instance of the searched term
void ConsoleUI::searchForEntries()
{
    string name;
    string inputString;

    while(!(inputString == "q" || inputString == "Q"))
    {
        cout << "========= Search for entry =========" << endl;
        cout << "| Enter 1 to search for a Genius   |" << endl;
        cout << "| Enter 2 to search for a Computer |" << endl;
        cout << "| Enter Q to quit                  |" << endl;
        cout << "====================================" << endl;
        getline(cin,inputString);

        if(inputString.length() != 1 || (inputString != "1" && inputString != "2" && inputString != "q" && inputString != "Q"))
        {
            clearscreen();
            printError();
            return searchForEntries();
        }
        else if(inputString == "1")
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
        else if(inputString == "2")
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
        else if(inputString == "q" || inputString == "Q")
        {
            clearscreen();
            break;
        }
        else
        {
            clearscreen();
            printError();
            return searchForEntries();
        }
    }
}

void ConsoleUI::deleteAnEntry()
{
    string name;
    string inputString;
    string YorNString;

    while(!(inputString == "q" || inputString == "Q"))
    {
        cout << "========== Delete entry ==========" << endl;
        cout << "| Enter 1 to delete a Genius     |" << endl;
        cout << "| Enter 2 to delete a Computer   |" << endl;
        cout << "| Enter Q to quit                |" << endl;
        cout << "==================================" << endl;
        getline(cin,inputString,'\n');

        if(inputString.length() != 1 || (inputString != "1" && inputString != "2" && inputString != "q" && inputString != "Q"))
        {
            clearscreen();
            printError();
            return deleteAnEntry();
        }
        else if(inputString == "1")
        {
            cout << "Enter name of Genius: ";
            getline(cin,name,'\n');

            try
            {
                bool check = true;
                do
                {
                    vector<GeniusModel> g = _geniusservice.find(name);
                    unsigned int option;
                    string optionString;

                    if (g.size() > 1)
                    {
                        check = false;
                        for(size_t i = 0; i < g.size(); i++)
                        {
                            cout << "Option " << i+1 << "  " << g[i] << endl;
                        }
                        cout << "Please enter the option you would like to delete: " << endl;
                        getline(cin,optionString,'\n');                        
                        bool validOption = false;
                        do
                        {
                            option = atoi(optionString.c_str());
                            if (option > 0 && option < g.size()+1)
                            {
                                validOption = true;
                                cout << g[option-1] << endl;
                                cout << "Are you sure you want to delete this entry? (y/n): ";
                                getline(cin,YorNString,'\n');

                                if(YorNString == "y" || YorNString == "Y")
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
                                printError();
                                cout << "Please enter the option you would like to delete: " << endl;
                                getline(cin,optionString,'\n');
                            }
                        }while (validOption == false);
                    }
                    else if (g.size() == 1)
                    {
                        check = false;
                        cout << g[0] << endl;
                        cout << "Would you like to delete this entry? (y/n): ";
                        getline(cin,YorNString,'\n');

                        if(YorNString == "y" || YorNString == "Y")
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
                        printError();
                        cout << "Enter name of Genius: " << endl;
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

        else if(inputString == "2")
        {
            cout << "Enter name of Computer: ";
            getline(cin,name,'\n');

            try
            {
                bool check = true;
                do
                {
                    vector<ComputerModel> c = _computerservice.find(name);
                    unsigned int option;
                    string optionString;

                    if (c.size() > 1)
                    {
                        check = true;
                        for(size_t i = 0; i < c.size(); i++)
                        {
                            cout << "Option " << i+1 << "  " << c[i] << endl;
                        }
                        cout << "Please enter the option you would like to delete: " << endl;
                        getline(cin,optionString,'\n');
                        bool validOption = false;
                        do
                        {
                            option = atoi(optionString.c_str());
                            if (option > 0 && option < c.size()+1)
                            {
                                validOption = true;
                                check = false;
                                cout << c[option-1] << endl;
                                cout << "Are you sure you want to delete this entry? (y/n): ";
                                getline(cin,YorNString,'\n');

                                if(YorNString == "y" || YorNString == "Y")
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
                                printError();
                                cout << "Please enter the option you would like to delete: " << endl;
                                getline(cin,optionString,'\n');
                            }
                        }while (!validOption);
                    }
                    else if (c.size() == 1)
                    {
                        check = false;
                        cout << c[0] << endl;
                        cout << "Would you like to delete this entry? (y/n): ";
                        getline(cin,YorNString,'\n');

                        if(YorNString == "y" || YorNString == "Y")
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
                        check = true;
                        printError();
                        cout << "Enter name of Computer: " << endl;
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

        else if (inputString == "q" || inputString == "Q")
        {
            clearscreen();
            break;
        }
        else
        {
            clearscreen();
            printError();
            return deleteAnEntry();
        }
    }
}
void ConsoleUI::modifyAnEntry()
{
    bool built = false;
    char gender;
    string name, genderString;
    string modelName, type;
    string inputString, YorNString;
    unsigned int dateOfDeath, dateOfBirth, makeYear;
    GeniusValidation vg;
    ComputerValidation vc;

    while(!(inputString == "q" || inputString == "Q"))
    {
        cout << "========== Modify entry ==========" << endl;
        cout << "| Enter 1 to modify a Genius     |" << endl;
        cout << "| Enter 2 to modify a Computer   |" << endl;
        cout << "| Enter Q to quit                |" << endl;
        cout << "==================================" << endl;
        getline(cin,inputString,'\n');

        if(inputString.length() != 1 || (inputString != "1" && inputString != "2" && inputString != "q" && inputString != "Q"))
        {
            clearscreen();
            printError();
            return modifyAnEntry();
        }

        else if (inputString == "1")
        {
            cout << "Enter name of Genius: " << endl;
            getline(cin,name,'\n');
            try
            {
                bool check = true;
                do
                {
                    vector<GeniusModel> g = _geniusservice.find(name);
                    int option;
                    string optionString;

                    if (g.size() > 1)
                    {
                        check = false;
                        for(size_t i = 0; i < g.size(); i++)
                        {
                            cout << "Option " << i+1 << "  " << g[i] << endl;
                        }
                        cout << "Please enter the option you would like to modify: " << endl;
                        getline(cin,optionString,'\n');
                        bool validOption = false;
                        do
                        {
                            option = atoi(optionString.c_str());
                            if (option > 0 && option < g.size()+1)
                            {
                                validOption = true;
                                clearscreen();
                                cout << g[option-1] << endl;
                                cout << "Would you like to change the Genius name? (y/n): ";
                                getline(cin,YorNString,'\n');
                                if(YorNString == "y" || YorNString == "Y")
                                {
                                    name = vg.promptForName();
                                }
                                else
                                {
                                    name = g[option-1].getName();
                                }
                                cout << "Would you like to change the Genius gender? (y/n): ";
                                getline(cin,YorNString,'\n');
                                if(YorNString == "y" || YorNString == "Y")
                                {
                                    gender = vg.promptForGender();
                                    string fullGender = "";
                                    if (gender == 'm' || gender == 'M')
                                    {
                                        genderString = "Male";
                                    }
                                    else if (gender == 'f' || gender == 'F')
                                    {
                                        genderString = "Female";
                                    }
                                    else
                                    {
                                        genderString = "N/A";
                                    }
                                }
                                else
                                {
                                    genderString = g[option-1].getGender();
                                }
                                cout << "Would you like to change the Genius birth year? (y/n): ";
                                getline(cin,YorNString,'\n');
                                if(YorNString == "y" || YorNString == "Y")
                                {
                                    dateOfBirth = vg.promptForDateOfBirth();
                                }
                                else
                                {
                                    dateOfBirth = g[option-1].getBirthYear();
                                }
                                cout << "Would you like to change the Genius death year? (y/n): ";
                                getline(cin,YorNString,'\n');
                                if(YorNString == "y" || YorNString == "Y")
                                {
                                    dateOfDeath = vg.promptForDateOfDeath(name, dateOfBirth);
                                }
                                else
                                {
                                    dateOfDeath = g[option-1].getDeathYear();
                                }

                                g[option-1].update(name, genderString, dateOfBirth, dateOfDeath);

                                _geniusservice.update(g[option-1]);

                            }
                            else
                            {
                                printError();
                                cout << "Please enter the option you would like to modify: " << endl;
                                getline(cin,optionString,'\n');
                            }
                        }while (validOption == false);
                    }
                    else if (g.size() == 1)
                    {
                        check = false;
                        clearscreen();
                        cout << g[0] << endl;
                        cout << "Would you like to change the Genius name? (y/n): ";
                        getline(cin,YorNString,'\n');
                        if(YorNString == "y" || YorNString == "Y")
                        {
                            name = vg.promptForName();
                        }
                        else
                        {
                            name = g[0].getName();
                        }
                        cout << "Would you like to change the Genius gender? (y/n): ";
                        getline(cin,YorNString,'\n');
                        if(YorNString == "y" || YorNString == "Y")
                        {
                            gender = vg.promptForGender();
                            if (gender == 'm' || gender == 'M')
                            {
                                genderString = "Male";
                            }
                            else if (gender == 'f' || gender == 'F')
                            {
                                genderString = "Female";
                            }
                            else
                            {
                                genderString = "N/A";
                            }
                        }
                        else
                        {
                            genderString = g[0].getGender();
                        }
                        cout << "Would you like to change the Genius birth year? (y/n): ";
                        getline(cin,YorNString,'\n');
                        if(YorNString == "y" || YorNString == "Y")
                        {
                            dateOfBirth = vg.promptForDateOfBirth();
                        }
                        else
                        {
                            dateOfBirth = g[0].getBirthYear();
                        }
                        cout << "Would you like to change the Genius death year? (y/n): ";
                        getline(cin,YorNString,'\n');
                        if(YorNString == "y" || YorNString == "Y")
                        {
                            dateOfDeath = vg.promptForDateOfDeath(name, dateOfBirth);
                        }
                        else
                        {
                            dateOfDeath = g[0].getDeathYear();
                        }

                        g[0].update(name, genderString, dateOfBirth, dateOfDeath);

                        _geniusservice.update(g[0]);
                    }
                    else
                    {
                        check = true;
                        printError();
                        cout << "Enter name of Genius: " << endl;
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
        else if (inputString == "2")
        {
            cout << "Enter name of Computer: " << endl;
            getline(cin,modelName,'\n');
            try
            {
                bool check = true;
                do
                {
                    vector<ComputerModel> c = _computerservice.find(modelName);
                    int option = 0;
                    string optionString;

                    if (c.size() > 1)
                    {
                        check = false;
                        for(size_t i = 0; i < c.size(); i++)
                        {
                            cout << "Option " << i+1 << "  " << c[i] << endl;
                        }
                        cout << "Please enter the option you would like to modify: " << endl;
                        getline(cin,optionString,'\n');
                        bool validOption = false;
                        do
                        {
                            option = atoi(optionString.c_str());
                            if (option > 0 && option < c.size()+1)
                            {
                                validOption = true;
                                clearscreen();
                                cout << c[option-1] << endl;
                                cout << "Would you like to change the Computer ModelName? (y/n): ";
                                getline(cin,YorNString,'\n');
                                if(YorNString == "y" || YorNString == "Y")
                                {
                                    modelName = vc.promptForModelName();
                                }
                                else
                                {
                                    modelName = c[option-1].getModelName();
                                }
                                cout << "Would you like to change the Computer MakeYear? (y/n): ";
                                getline(cin,YorNString,'\n');
                                if(YorNString == "y" || YorNString == "Y")
                                {
                                    makeYear = vc.promptForMakeYear();
                                }
                                else
                                {
                                    makeYear = c[option-1].getMakeYear();
                                }
                                cout << "Would you like to change the Computer Type? (y/n): ";
                                getline(cin,YorNString,'\n');
                                if(YorNString == "y" || YorNString == "Y")
                                {
                                    type = vc.promptForType();
                                }
                                else
                                {
                                    type = c[option-1].getType();
                                }
                                cout << "Would you like to change the Genius Built? (y/n): ";
                                getline(cin,YorNString,'\n');
                                if(YorNString == "y" || YorNString == "Y")
                                {
                                    built = vc.promptForBuilt();
                                }
                                else
                                {
                                    built = c[option-1].getBuilt();
                                }

                                c[option-1].update(modelName, makeYear, type, built);

                                _computerservice.update(c[option-1]);

                            }
                            else
                            {
                                printError();
                                cout << "Please enter the option you would like to modify: " << endl;
                                getline(cin,optionString,'\n');
                            }
                        }while (validOption == false);
                    }
                    else if (c.size() == 1)
                    {
                        check = false;
                        clearscreen();
                        cout << c[0] << endl;
                        cout << "Would you like to change the Computer ModelName? (y/n): ";
                        getline(cin,YorNString,'\n');
                        if(YorNString == "y" || YorNString == "Y")
                        {
                            modelName = vc.promptForModelName();
                        }
                        else
                        {
                            modelName = c[0].getModelName();
                        }
                        cout << "Would you like to change the Computer MakeYear? (y/n): ";
                        getline(cin,YorNString,'\n');
                        if(YorNString == "y" || YorNString == "Y")
                        {
                            makeYear = vc.promptForMakeYear();
                        }
                        else
                        {
                            makeYear = c[0].getMakeYear();
                        }
                        cout << "Would you like to change the Computer Type? (y/n): ";
                        getline(cin,YorNString,'\n');
                        if(YorNString == "y" || YorNString == "Y")
                        {
                            type = vc.promptForType();
                        }
                        else
                        {
                            type = c[0].getType();
                        }
                        cout << "Would you like to change the Genius Built? (y/n): ";
                        getline(cin,YorNString,'\n');
                        if(YorNString == "y" || YorNString == "Y")
                        {
                            built = vc.promptForBuilt();
                        }
                        else
                        {
                            built = c[0].getBuilt();
                        }

                        c[0].update(modelName, makeYear, type, built);

                        _computerservice.update(c[0]);

                    }
                    else
                    {
                        check = true;
                        printError();
                        cout << "Enter name of Genius: " << endl;
                        getline(cin, modelName,'\n');
                    }
                }while(check == true);
            }
            catch(int)
            {
                cerr << "Did not find anything" << endl;
            }
            cout << endl;

        }
        else if (inputString == "q" || inputString == "Q")
        {
            clearscreen();
            break;
        }
        else
        {
            clearscreen();
            printError();
            return modifyAnEntry();
        }
    }
}
void ConsoleUI::run()
{
    string input;

    do
    {
        printMenu();
        getline(cin, input);

        if (input.size() == 0 || input.size() > 1)
        {
            clearscreen();
            printError();
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
                case '6':
                {
                    clearscreen();
                    modifyAnEntry();
                    break;
                }
                case '7':
                {
                    clearscreen ();
                    game();

                }
                case 'q':
                case 'Q':
                {
                    cout << "=======================" << endl;
                    cout << "| Program terminated. |" << endl;
                    cout << "=======================" << endl;
                    exit(0);
                }
                default:
                {
                    clearscreen();
                    printError();
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
    cout << "============================================================="<< endl;
    cout << "===================== Sorted Genius list ====================" << endl;
    cout << "============================================================="<< endl;
    cout << setw(24)<< "Name" << setw(9) << "Gender" << "  " << "Birth Year" << "  -  " << "Death Year" << endl;
    cout << "============================================================="<< endl;
    for(unsigned int i = 0; i < GVector.size(); i++)
    {
        cout << GVector[i] << endl;
    }
    cout << "============================================================="<< endl;
    cout << endl;
}

void ConsoleUI::printCVector(vector<ComputerModel> CVector)
{
    cout << "=========================================================================="<< endl;
    cout << "========================= Sorted Computer list ===========================" << endl;
    cout << "=========================================================================="<< endl;
    cout << setw(26)<< "Model Name" << setw(3) << " " << "Make Year" << setw(23) << "Type" << "   " << "Built(Y/N)" << endl;
    cout << "=========================================================================="<< endl;
    for(unsigned int i = 0; i < CVector.size(); i++)
    {
        cout << CVector[i] << endl;
    }
    cout << "=========================================================================="<< endl;
    cout << endl;
}

void ConsoleUI::printGeniusSort()
{
    cout << "============== Sort Genius ==============" << endl;
    cout << "| Enter A for list sorted by Name       |" << endl;
    cout << "| Enter B for list sorted by Gender     |" << endl;
    cout << "| Enter C for list sorted by Birth year |" << endl;
    cout << "| Enter D for list sorted by Death year |" << endl;
    cout << "| Enter Q to quit                       |" << endl;
    cout << "=========================================" << endl;
}
void ConsoleUI::printComputerSort()
{
    cout << "============= Sort Computer =============" << endl;
    cout << "| Enter a for list sorted by Model name |" << endl;
    cout << "| Enter b for list sorted by Make year  |" << endl;
    cout << "| Enter c for list sorted by Type       |" << endl;
    cout << "| Enter d for list sorted by Year built |" << endl;
    cout << "| Enter q to quit                       |" << endl;
    cout << "=========================================" << endl;
}

void ConsoleUI::printError()
{
    cout << "============ ERROR ============" << endl;
    cout << "| Please enter a valid choice |" << endl;
    cout << "===============================" << endl;
    cout << endl;
}

void ConsoleUI::printMenu()
{
    cout << "========== Main Menu ==========" << endl;
    cout << "| Enter 1 for Unsorted list   |" << endl;
    cout << "| Enter 2 for Sorted list     |" << endl;
    cout << "| Enter 3 to Add entry        |" << endl;
    cout << "| Enter 4 to Search for entry |" << endl;
    cout << "| Enter 5 to Delete an entry  |" << endl;
    cout << "| Enter 6 to Modify an entry  |" << endl;
    cout << "| Enter 7 to Play a game      |" << endl;
    cout << "| Enter q to Quit             |" << endl;
    cout << "===============================" << endl;
}

void ConsoleUI::game()
{
    cout << "777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777 777777777" << endl;
    cout << "777777777777777777777777777777777............................................7777777777777 777777777" << endl;
    cout << "7777777777777777777777777................7777777777777777777777777777777777.....7777777777 777777777" << endl;
    cout << "7777777777777777777...........7777777777.....777777777777777..7777777777777777...777777777 777777777" << endl;
    cout << "77777777777777777....77777777777777777777777777777777777777777777..7777777777777...7777777 777777777" << endl;
    cout << "77777777777777....7777.77......777777777777...77777777777777..777777.777777777777...777777 777777777" << endl;
    cout << "777777777777....7777777777777777777777777777777777777777777777777..7777.7777777777...77777 777777777" << endl;
    cout << "77777777777...777777777777.....77777777777777777777.7777777777...777.7777.777777777...7777 777777777" << endl;
    cout << "7777777777..77777777777.7777777777777777777777777.7777777777777777..777.7777.7777777...777 777777777" << endl;
    cout << "7777777777..777777777.777777777777.7777777777777777777777777777777777.77.7777.7777777..777 777777777" << endl;
    cout << "7777777777..77777777.77777777777777777777777777777777777777777777777777.77.77777777777..77 777777777" << endl;
    cout << "777777777..777777777777777777777777777777777777777777..............7777777777777777777...7 777777777" << endl;
    cout << "77777777...777777777777........7777777777777777777.....777............77777777777777777... 777777777" << endl;
    cout << "7777....77777777777..............7777777777777....777777........77...777777777777777777... 7777777" << endl;
    cout << "777...777.....7...7...............77777777777...77777.................7777.7777........7.. ..77777" << endl;
    cout << "77..777.777777777777777777.............7777777.........77777777777..777.777777777777777777 ...7777" << endl;
    cout << "7..77.777..777777777777777777777....77777777777.....777777...77777777777777..........77777 77..777" << endl;
    cout << "7..7.77.777......7777777777777777..7777777777777777777777777....7777777......777777....777 7.7..77" << endl;
    cout << "7...77777..........7777.777777777..777777777777777777777777777...........77777..77777...77 7.77..." << endl;
    cout << "7...77777.7777777........77777777..7777777777777777777777777777777777777777777..777777..77 7.77..." << endl;
    cout << "7...77.7777777..77....77777777....77777777777777777777777777777777777777777.....7777777..7 7.777.." << endl;
    cout << "7..7777.777777..77777777777....7777777777777777........7777777777777777.....777......77..7 7.777.." << endl;
    cout << "7....777..77....7777777777.....77777777777777777777..77777777777777......77777...7...7...7 7.77..." << endl;
    cout << "77..7..77777....7777777..77.....777777777.......777..7777777777.......77777777..777777..77 7777..." << endl;
    cout << "77...7777.77..7...777.77777777...77777777777777.7...777777........7..7777777....77777..777 .77...7" << endl;
    cout << "777...77777.........777777777777......777777777777777........777777..7777......777777777.. 77..777" << endl;
    cout << "7777...7777..7..7......77777777777...77777777777........7777777777...7........7777777.7777 7...777" << endl;
    cout << "77777..7777....77..77........77777777..............77..7777777777.......77...7777777777... ..77777" << endl;
    cout << "77777..7777....77..7777....................7777777777..777777........7777...777777777777.. .777777" << endl;
    cout << "77777..7777....77..777...7777777..7777777..7777777777...7.........7..777...77777777777...7 7777777" << endl;
    cout << "77777..7777........777..77777777..7777777..777777777...........7777..77...77777777777...77 7777777" << endl;
    cout << "77777..7777.................................................7777777......777777777777..777 7777777" << endl;
    cout << "77777..7777...........................................7..77777777777...7777777777777...777 7777777" << endl;
    cout << "77777..77777....................................7777777..777777777...77777777777777...7777 7777777" << endl;
    cout << "77777..77777..7...........................7..7777777777...77777....777777777777777...77777 7777777" << endl;
    cout << "77777..777777..7..77..777..77777...77777777..77777777777..777....777777777777777...7777777 7777777" << endl;
    cout << "77777..777777......7...777..77777..77777777..777777777777......7777777777777777...77777777 7777777" << endl;
    cout << "77777..7777777....777...77...7777..77777777..777777777......7777777.77777.777...7777777777 7777777" << endl;
    cout << "77777..777777777.........77..7777...7777777..77.........77777777.77777..777....77777777777 7777777" << endl;
    cout << "77777..77777777777777...............................777777777..7777..7777.... 777777777777777" << endl;
    cout << "7777...77777777.777777777777777777777777777777777777777777.77777..7777.....77 77777777777777" << endl;
    cout << "7777..7777777777.777777777777777777777777777777777777..777777.77777.....77777 77777777777777" << endl;
    cout << "7777..777777777777.777777777777777777777777777777..777777..77777.....77777777 77777777777777" << endl;
    cout << "77..77777..77777777...77777777777..........777777..7777777......7777777 777777777777" << endl;
    cout << "7..777777777.7777777777777777777777777...777777777777.....777777 77777777" << endl;
    cout << "7...7777777777...............777777777777777777777.....777777 7777" << endl;
    cout << "7...777777777777777777777777777777777777777777.....777777 77" << endl;
    cout << "77...77777777777777777777777777777777777..7.....7777777" << endl;
    cout << "777....7777777777777777777777777777..........77777777" << endl;
    cout << "7777.....7777777777777777777.........77777777777777" << endl;
    cout << "7777777........................77777777777777777777" << endl;
    cout << "        YOU JUST GOT TROLLED, TROLOLOLOLO" << endl;
    cout << "                No game for you          " << endl;
}
