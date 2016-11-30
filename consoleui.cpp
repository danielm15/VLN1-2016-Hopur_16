#include "consoleui.h"
#include <iostream>
#include "datalayer.h"
#include <vector>

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
            DataLayer d;
            vector<Genius> GVector = d.getInfo();

            cout << GVector.size() << endl;

            for(unsigned int i = 0; i < GVector.size(); i++)
                {
                    cout << GVector[i] << endl;
                }
            break;
        }
        case '3':
        {
            cout << "Add entrey" << endl;

            break;
        }
        case '4':
        {
            cout << "Search for entry" << endl;
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

    }
    while(!(input == 'q' || input == 'Q'));

}


