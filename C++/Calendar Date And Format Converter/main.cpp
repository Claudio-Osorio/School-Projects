
// ******************************************************************************//
// * Name: Assignment #2 Date Class *                                            //
// * Class: COP3330 *                                                            //
// * Description: Interact with the user's input and show, calculate:            //
// Gregorian, Two Digit, Long and Julian formatted dates as requested by the     //
// directions in the assigment.*                                                 //
// * All the code below was created by Claudio Osorio*                           //
// * Date: January 17, 2021 *                                                    //
// ******************************************************************************//


#include <iostream>
#include "date.h"

using namespace std;

int main() {
    ////Data for 1st and default term //////////////
    Date d1;
    int incDays;
    char newFormat;
    ////Data for 2nd term used for comparison ////
    Date d;
    /////////////////////////////////////////////

    cout << "Hello, Welcome to Date Generator by Claudio Osorio" << endl;
    d1.Input(); //Calls for the starting input with (default date) and validates

    cout <<"The Month is " << d1.GetMonth() <<endl;
    cout <<"The Day is   " << d1.GetDay() <<endl;
    cout <<"The Year is  " << d1.GetYear() <<endl;
    cout <<"Leap year?   " << d1.LeapYearValidation(d1.GetYear()) << endl;
    cout <<"=======================================" <<endl;

    cout << "Please enter the desired date format (J;L;T;D): ";
    cin >> newFormat;
    cout << "Set Format Returned: " << d1.SetFormat(newFormat) <<endl;
    cout << "Format is set to: " << d1.GetFormat() <<endl;
    cout <<"=======================================" <<endl;


    //Print desired format to screen
    cout << "The desired format looks like this: ";
    d1.Show();

    cout <<"=======================================" <<endl;

    cout << "All the formats are: "<< endl;
    cout << "Default Format:    ";
    d1.ShowDefaultFormat();

    cout << "Julian Format:     ";
    d1.ShowJulianFormat();

    cout << "Long Format:       ";
    d1.ShowLongFormat();

    cout << "Two Digit Format:  ";
    d1.ShowTwoDigitFormat();

    cout <<"=======================================" <<endl;

     //Stores the date to be compared
    cout << "To compare with a second date ";
    d.Input();//Obtain day, month , year
    cout << "The Comparison Returned: " << d1.Compare(d) << endl;

    cout <<"=======================================" <<endl;

    cout << "How many days you want to increment to your first date?: ";
    cin >> incDays;

    cout << "Your Date went from " << d1.GetMonth() << "/"<< d1.GetDay() << "/"<< d1.GetYear() << " to ";
    d1.Increment(incDays);

    cout << d1.GetMonth() << "/"<< d1.GetDay() << "/"<< d1.GetYear() << endl;

    return 0;
}



