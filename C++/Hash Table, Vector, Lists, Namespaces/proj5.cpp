// ********************************************************************
// *                    Name: Claudio Osorio                          *
// * Description:  This program uses vectors, lists, iterators and    *
// *   namespaces. This program will create Hash-tables and encrypted *
// *   passwords. The information will be saved in pairs and written  *
// *   to files if requested.                                         *
// *                                                                  *
// *                    Date: July 6, 2021                            *
// *                    Last Checked: July 14, 2021                   *
// *                                                                  *
// * Disclaimer: Some parts of this code were provided by Dr. Gaitros *
// * in his videos. I have also inspired my code and used small parts *
// * from examples provided  by the book "Data Structures Algorithm   *
// * Analysis in C++ by Mark A. Weiss" and the website cplusplus.com  *
// * I have also used some one-liners from tutorialspoint.com for     *
// * the implementation and handling of the pairs from the hashtable. *
// *                                                                  *
// * This code has been tested in linprog and compiled with no errors *
// * a copy of the output should have been provided in the comments of*
// * the submission of this assignment. Thanks                        *
// ********************************************************************
#include <iostream>
#include <string>
#include "hashtable.h"
#include "passserver.h"
using namespace std;
using namespace COP4530;

typedef vector<list<pair<string,string>>> myType;
void Menu();

int main()
{
    char choice;
    int capacity;
    string filename;
    string username;
    string password;
    string newUser;
    string newPass;
    cout << "Welcome to Hash Table by Claudio Osorio" << endl;
    cout <<"Enter preferred hash table capacity: ";
    cin >> capacity;

    //Hashtable with the capacity specified by the user
    myType * myHT;
    PassServer server(capacity);
    myHT = new myType[capacity];

    do
    {
        Menu();
        cin >> choice;

        if ( choice == 'l' || choice == 'L' ) //Load From File
        {
            cout << "Specify password file name to load from: ";
            cin >> filename;
            if(!server.load(filename.c_str()))
            {
                cout << "Error: File \"" << filename << "\" cannot be opened."
                " Check if it exist first";
            }
            else
            { cout << "File \"" << filename << "\" successfully loaded" << endl; }

            cout << endl;

        } else if ( choice == 'a' || choice == 'A') //Add User
        {
            cout << "New Username: ";
            cin >> newUser;
            cout << "New Password: ";
            cin >> newPass;

            pair<string,string> newPair;
            newPair.first = newUser;
            newPair.second = newPass;

            if (!server.addUser(newPair))
            {
                cout << "ERROR: The username could not be added" << endl;
            } else
            {
                cout << "The following has been added "
                        "\nUser: " << newUser << "\nPass: " << newPass << endl;
            }

        } else if ( choice == 'r' || choice == 'R') //Remove User
        {   cout << "Please enter the username you want to remove: ";
            cin >> username;

            if(!server.removeUser(username))
            { cout << "ERROR: user could not be removed. Maybe it doesn't exist" << filename; }
            else
            { cout << "User \"" << username <<"\" has been successfully removed"; }

        } else if ( choice == 'c' || choice == 'C') //Change User Password
        {
            cout << "Enter user: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            cout << "Enter new password: ";
            cin >> newPass;
            cout << endl;
            if(server.changePassword(make_pair(username, password), newPass))
            {
                cout << "The password has been successfully changed for the user \""
                     << username << "\""<<endl;
            }
            else
            { cout << "ERROR: User \"" << username << "\" password failed to be changed" << endl; }

        } else if ( choice == 'f' || choice == 'F' ) //Find user
        {
            cout << "Enter username to be found: ";
            cin >> username;

            if (server.find(username))
            {
                cout << "User \"" << username << "\" was FOUND" << endl;
            } else
            {
                cout << "User \"" << username << "\" was NOT FOUND" << endl;
            }

        } else if ( choice == 'd'|| choice == 'D' ) //Dump HashTable
        {
            server.dump();
        } else if ( choice == 's' || choice == 'S' ) //HashTable Size
        {
            cout << "Hashtable size is " << server.size() << endl;
        } else if ( choice == 'w' || choice == 'W') //Write to Password File
        {
            cout << "Specify name of the file that will store all the data: ";
            cin >> filename;

            if(!server.write_to_file(filename.c_str()))
                cout << "ERROR: File write failure" << endl;
            else
                cout << "The File was Successfully Stored" << endl;

        } else if ( choice == 'x' ) //Exit program
        {
            cout << "##### END ######" << endl;
        } else //Wrong input
        {
            cout << "Your input is not valid. "
                    "Please check it is correct and try again." << endl;
            //Nothing happens. Re-start
        }

    } while ( choice != 'x');

    return 0;
}
//*********************
//* Displays the Menu *
//*********************
void Menu()
{
    cout << "\n\n";
    cout << "l - Load From File" << endl;
    cout << "a - Add User" << endl;
    cout << "r - Remove User" << endl;
    cout << "c - Change User Password" << endl;
    cout << "f - Find User" << endl;
    cout << "d - Dump HashTable" << endl;
    cout << "s - HashTable Size" << endl;
    cout << "w - Write to Password File" << endl;
    cout << "x - Exit program" << endl;
    cout << "\nEnter choice: ";
}
