#include "consoleui.h"

using namespace std;

ConsoleUI::ConsoleUI()
{

}

void wait()
{
    Sleep(1000);
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
        cout << "Enter 5 to Delete an entry" << endl;
        cout << "Enter q to Quit" << endl;
        cout << "============================" << endl;
        cin >> input;


        switch (input)
        {
        case '1':
        {
            clearscreen ();
            cout << "=============| Unsorted list |==============" << endl;
            vector<Genius> GVector = _service.getGenius();

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

            if ('D' == sortby || 'd' == sortby)
            {
                clearscreen ();
                cout << "==============| Sorted list by Descending order |===============" << endl;
                vector<Genius> GVector = _service.sortVector();

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
                vector<Genius> GVector = _service.sortVector();

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
            bool rejected = false;
            bool check = true;
            char gender;
            string strgender,name, strdateOfBirth, strdateOfDeath;
            unsigned int dateOfDeath, dateOfBirth;;

            ServiceLayer s;

            cout << "===============| Add entry |================" << endl;

            // Name check fall
            while(check)
            {

                cout << "Name: ";
                cin.ignore();
                getline(cin,name,'\n');
                name[0] = toupper(name[0]);

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
                if(rejected == true)
                {
                    cout << "Name can only contain alphabetic characters and spaces!" << endl;
                    check = true;
                    rejected = false;
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


            // Gender check fall
            check = true;
            rejected = false;

            while(check)
            {
                cout << "Gender (m/f): ";
                getline(cin,strgender,'\n');

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


                if(rejected == true)
                {
                    cout << "Please enter m for male or f for female" << endl;
                    check = true;
                    rejected = false;
                    wait();
                }
                else
                {
                    check = false;
                    cout << "Gender successfully entered" << endl;
                    wait();
                }
                clearscreen();
            }

            //Year of birth check fall
            rejected = false;
            check = true;
            while(check)
            {
                cout << "Year of birth: ";
                getline(cin,strdateOfBirth,'\n');

                for(unsigned int i = 0; i < strdateOfBirth.length() && !rejected; i++)
                {
                    if(isdigit(strdateOfBirth[i]))
                        continue;
                    rejected = true;
                }

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
                    rejected = false;

                    wait();
                }
                clearscreen();
            }

            //Year of death check fall
            rejected = false;
            check = true;
            while(check)
            {
                cout << "Enter 0 if person is alive" << endl;
                cout << "Year of death: ";
                getline(cin,strdateOfDeath,'\n');

                for(unsigned int i = 0; i < strdateOfDeath.length() && !rejected; i++)
                {
                    if(isdigit(strdateOfDeath[i]))
                        continue;
                    rejected = true;
                }
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
                    rejected = false;

                    wait();
                }
                clearscreen();
            }

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
            break;
        }
        case '4':
        {
            clearscreen ();
            string name;

            cout << "===============| Search for entry |================" << endl;
            cin.ignore();
            getline(cin,name,'\n');

                vector<Genius> filtered = _service.filter(name);
                for(int i = 0; i < filtered.size(); i++)
                {
                    cout << filtered[i] << endl;
                }

           if (filtered.size() == 0)
                {
                    cout << "No results found" << endl;
                }
            cout << endl;
            break;
        }
        case '5':
        {
            clearscreen ();
            string name;
            char YorN;

            cout << "===============| Delete entry |================" << endl;
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
                    "Entry was not deleted";
                }

            }
            catch(int)
            {
                cerr << "Did not find anything" << endl;
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

