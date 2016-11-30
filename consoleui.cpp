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
            DataLayer p;
            vector<Genius> GVector = p.getInfo();

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
            //Error check TODO
            cout << "Add entry" << endl;
        }
        else if(input == '4')
        {
            cout << "Search for entry" << endl;
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
