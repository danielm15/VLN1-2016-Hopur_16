#include "consoleui.h"

using namespace std;

ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{
    char input = ' ';

    do
    {
        cout << "Enter *1* to view original list" << endl;
        cout << "Enter *2* to view list in alphabetical order" << endl;
        cout << "Enter *3* to add entry to list" << endl;
        cout << "Enter *4* to search for entry in the list" << endl;
        cout << "Enter *q* to quit application" << endl;
        cin >> input;


        switch (input)
        {
        case '1':
        {
            cout << "Unsorted list" << endl;
            ServiceLayer s;
            vector<Genius> GVector = s.getGenius();

            for(unsigned int i = 0; i < GVector.size(); i++)
               {
                 cout << GVector[i] << endl;
               }
            break;
        }
        case '2':
        {
            cout << "Sorted list" << endl;
            ServiceLayer s;
            vector<Genius> GVector = s.sortVector();

            for(unsigned int i = 0; i < GVector.size(); i++)
                {
                    cout << GVector[i] << endl;
                }
            break;
        }
        case '3':
        {
            bool saved = false;

            string name;
            char gender;
            int dateOfBirth;
            int dateOfDeath;
            ServiceLayer s;

            cout << "Add entrey" << endl;
            cout << "Name: ";

            cin.ignore();
            getline(cin,name,'\n');
            cout << "Gender (m/f): ";
            cin >> gender;
            cout << "Year of birth: ";
            cin >> dateOfBirth;
            cout << "Year of death: ";
            cin >> dateOfDeath;

            saved = s.addEntry(name,gender,dateOfBirth,dateOfDeath);

            if(saved == true)
            {
                cout << "Entry saved";
            }
            else
                cout << "Entry failed";

            break;
        }
        case '4':
        {
            string name;

            cout << "Search for entry" << endl;
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

            break;
        }
        case 'q':
        {
            break;
        }
        default:
        {
            cout << "Please enter a number between 1-3" << endl;
            cout << "or q to quit the application" << endl;
            break;
        }

    }

    }while(!(input == 'q' || input == 'Q'));

}


