#include "consoleui.h"
#include "datalayer.h"

using namespace std;

ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{
    char input = '1';

    do
    {
        cout << "Enter *1* to view original list" << endl;
        cout << "Enter *2* to view list in alphabetical order" << endl;
        cout << "Enter *3* to add entry to list" << endl;
        cout << "Enter *4* to search for entry in the list" << endl;
        cout << "Enter *q* to quit application" << endl;
        cin >> input;

        if(input == '1')
        {
            ServiceLayer s;
            vector<Genius> GVector = s.getGenius();

            cout << GVector.size() << endl;

            for(unsigned int i = 0; i < GVector.size(); i++)
            {
                cout << GVector[i] << endl;
            }
        }
        else if(input == '2')
        {
            cout << "Sorted list" << endl;
        }
        else if(input == '3')
        {
            ServiceLayer s;
            string name;
            char gender;
            unsigned int date_of_birth, date_of_death;
            //Error check TODO

            cout << "Add entry" << endl;

            // Get name
            cout << "Name: ";
            cin.ignore();
            getline(cin, name, '\n');

            // Get gender
            cout << "Gender (m/f): ";
            cin >> gender;

            // Get date of birth
            cout << "Birth: ";
            cin >> date_of_birth;

            // get date of death
            cout << "Death (0 if still alive): ";
            cin >> date_of_death;

            // Add it to the dataset.
            if (s.addEntry(name, gender, date_of_birth, date_of_death))
            {
                cout << "Saved" << endl;
            }
            else
            {
                cout << "Can't save" << endl;
            }
        }
        else if(input == '4')
        {
			string name;
			ServiceLayer s;
            cout << "Search for entry" << endl;
            cin.ignore();
            getline(cin, name, '\n');
            try
            {
                Genius g = s.find(name);
                cout << g << endl;
            }
            catch(int n)
            {
                cout << "Did not find anything" << endl;
            }
        }
        else if(input == 'q' || input == 'Q')
        {
            break;
        }
        else
        {
            cout << "Please enter a number between 1-3" << endl;
            cout << "or q to quit the application" << endl;
        }

    }
    while(1);

}
