#include "consoleui.h"

using namespace std;

ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{
    char input = ' ';
    char sortby = ' ';

    do
    {
        cout << "============================" << endl;
        cout << "Enter 1 for Unsorted list" << endl;
        cout << "Enter 2 for Sorted list" << endl;
        cout << "Enter 3 to Add entry" << endl;
        cout << "Enter 4 to Search for entry" << endl;
        cout << "Enter q to Quit" << endl;
        cout << "============================" << endl;
        cin >> input;


        switch (input)
        {
        case '1':
        {
            clearscreen ();
            cout << "=============| Unsorted list |==============" << endl;
            ServiceLayer s;
            vector<Genius> GVector = s.getGenius();

            for(unsigned int i = 0; i < GVector.size(); i++)
            {
                cout << GVector[i] << endl;
            }
            cout << endl;
            break;
        }
        case '2':
        {
            cout << "============================" << endl;
            cout << "Enter D for order by decending" << endl;
            cout << "Enter A for order by ascending" << endl;
            cout << "============================" << endl;
            cin >> sortby;

            if ('D' == sortby)
            {
           clearscreen ();
            cout << "==============| Sorted list by Descending order |===============" << endl;
            ServiceLayer s;
            vector<Genius> GVector = s.sortVector();

            for(unsigned int i = 0; i < GVector.size(); i++)
                {
                    cout << GVector[i] << endl;
                }
            cout << endl;
            }

            else if ('A' == sortby)
            {
           clearscreen ();
            cout << "==============| Sorted list by Ascending order |===============" << endl;
            ServiceLayer s;
            vector<Genius> GVector = s.sortVector();

            for(int i = GVector.size()-2; i >= 0; i--)
                {
                    cout << GVector[i] << endl;
                }
            cout << endl;
            }
            break;
        }
        case '3':
        {
            clearscreen ();
            bool saved = false;

            string name;
            char gender;
            size_t dateOfBirth;
            size_t dateOfDeath;
            bool rejected = false;
            bool check = true;
            ServiceLayer s;

            cout << "===============| Add entry |================" << endl;

            while(check)
            {
                cout << "Name: ";
                cin.ignore();
                getline(cin,name,'\n');
                name[0] = toupper(name[0]);

                for(size_t i = 0; i < name.length() && !rejected; i++)
                {
                    if(isalpha(name[i]))
                        continue;
                    if(name[i] == ' ')
                        continue;

                    rejected = true;
                }
                if(rejected == true)
                {
                    cout << "Name can only contain alphabetic characters and spaces" << endl;
                    check = true;
                }
                else
                {
                    check = false;
                }
            }

            cout << "Gender (m/f): ";
            cin >> gender;
            cout << "Year of birth: ";
            cin >> dateOfBirth;
            cout << "Year of death: ";
            cin >> dateOfDeath;

            saved = s.addEntry(name,gender,dateOfBirth,dateOfDeath);

            if(saved == true)
            {
                cout << "Entry saved" << endl;
            }
            else
            {
                cout << "Entry failed" << endl;
            }
            cout << endl;
            break;
        }
        case '4':
        {
            clearscreen ();
            string name;

            cout << "===============| Search for entry |================" << endl;
            cin.ignore();
            getline(cin,name,'\n');
            ServiceLayer s;

            try
            {
                Genius g = s.find(name);
                cout << g << endl;
            }
            catch(int)
            {
                cout << "Did not find anything" << endl;
            }
            cout << endl;
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
            cout << "Please enter a number between 1-4" << endl;
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

