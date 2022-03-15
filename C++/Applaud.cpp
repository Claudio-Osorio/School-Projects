/* Name: Claudio Osorio
 * Date: 09/16/2020
 * Section: Module 4
 * Assignment: Should I applaud and Ordered Numbers Programs
 * Due Date: Sep 20 by 11:59pm EST
 * About this project: This program will take the user's input and define a path according to his/her answers. The user
 * will provide a set of yeses or noes that will determine if the user should applaud or not.
 * Assumptions: The assumption is that the user understands that he/she must enter the correct strings of text such
 * as 'Y','y','N',and 'n'.
 *
 * All work below was performed by Claudio Osorio
 *
 */
#include <iostream>
#include <string>


using namespace std;
int main() {
string yes_or_no; //Declaration of the string to store the answers

    //Introduction, Welcome and Instructions for new users
    cout << "Welcome to Claudio's SHOULD I APPLAUD? Program.\n"
            "To  Get Started Please Enter Y or y for YES, or N or n for NO" << endl;

    //Start of the program
    cout << "Do you know how the piece ends?" << endl;
    cin >> yes_or_no;

    //If the user answers "yes" he will continue to answer more questions
    if (yes_or_no == "Y" || yes_or_no == "y")
    {
        cout << "Was that the end of the piece?" << endl;
        cin >> yes_or_no;

    //The user knows the piece and how it ends
        if (yes_or_no == "Y" || yes_or_no == "y")
        {
            cout << "Go Ahead" << endl;
            cout << "\nThis program has successfully ended..." << endl;
        }
    //The user knows the piece ends and knows this is not the end
        else if (yes_or_no == "N" || yes_or_no == "n")
        {
            cout << "Probably Not";
            cout << "\nThis program has successfully ended..." << endl;

        }
    //User entered wrong input
        else
        {
            cout << "Wrong Input. Please restart program." << endl;
        }

    }
    //The user doesn't know how the piece ends
    else if (yes_or_no == "N" || yes_or_no == "n")
    {
        cout << "Is the performer about to bow?" << endl;
        cin >> yes_or_no;
    //The user knows how the piece ends and sees the performer is about to bow
        if (yes_or_no == "Y" || yes_or_no == "y")
        {
            cout << "Go Ahead" << endl;
            cout << "\nThis program has successfully ended..." << endl;
        }
    //The user doesn't know the piece and sees the artist isn't bowing
        else if (yes_or_no == "N" || yes_or_no == "n")
        {
            cout << "Is everybody else applauding?" << endl;
            cin >> yes_or_no;
    //The user doesn't know the piece and sees the artist isn't bowing but everyone is applauding
            if (yes_or_no == "Y" || yes_or_no == "y")
            {
                cout << "Go Ahead" << endl;
                cout << "\nThis program has successfully ended..." << endl;
            }
    //The user doesnt know the piece, doesn't see the artist bowing and nobody is applauding.
            else if (yes_or_no == "N" || yes_or_no == "n")
            {
                cout << "Don't Start It" << endl;
                cout << "\nThis program has successfully ended..." << endl;
            }
    //User entered wrong input
            else
           {
                    cout << "Wrong Input. Please restart program." << endl;
           }
     }
     else
    //User entered wrong input
     {
            cout << "Wrong Input. Please restart program." << endl;
     }
    }
    else
    //User entered wrong input
    {
        cout << "Wrong Input. Please restart program." << endl;
    }

    return 0;
}
