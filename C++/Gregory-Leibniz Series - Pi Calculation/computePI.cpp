/* Name: CLAUDIO OSORIO
 * Date:  09/25/2020
 * Section: Module 5
 * Assignment: #5 Calculating Pi (π) using infinite series Program Assignment
 * Due Date: 09/26/2020
 * About this project:  This program asks the user to input a number and then uses
 * it to find PI by calculating using  Gregory-Leibniz Series.
 * Assumptions: The user will follow the steps and will enter characters an not numbers when required.
 * The user wants to input a number for the calculation as soon as the program starts.
 * All work below was performed by CLAUDIO OSORIO */

#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
  long int num; //num will store the required value to start the calculation.
  char yesOrNo = 'Y'; //yesOrNo will store if the user wants to continue calculating or not.

    cout << "Welcome to Claudio's CALCULATING PI program" << endl;
    do
    {
        long double pi = 0.0;//Pi variable storage.
                      // Must be outside for loop so next start pi value doesn't add up.

        do//This loop makes sure the user enters a valid integer >0
        {
            cout << "Please enter a number (INT) greater than 0:" << endl;
            cin >> num;

            if (num <= 0)
                cout << "You have entered an invalid integer, please try again:" << endl;
        }
        while(num <= 0);

        //Gregory-Leibniz Series Calculation using the number of terms "num"
        long double den = 1.0;//Initial Denominator for the Calculation of the Series
        //Adding terms until we reach the amount specified by user  and

        // Calculating Formula + Accounting for the fact that the first value is 4/1
        for(int i= 1; i <= num+1; i++)
        {
            if(i % 2 == 0)
                pi -= (4/den);//When series term is even then term is subtracted.
            else
                pi += (4/den);//When series term is odd then term is added.

            den += 2;//Denominator of the series increases by 2.
        }


        //Printing PI with 250 decimal places to the screen
        cout << setprecision(250) << pi << endl;


        cout << "Do you want to run again (Y/N)?" << endl;
        cin >> yesOrNo;

        //This loop makes sure the user enters a correct char for continuing or exiting
        while (yesOrNo!='Y' && yesOrNo !='y' && yesOrNo != 'N' && yesOrNo != 'n')
        {
            cout << "You must enter a Y or a N." << endl;
            cout << "Do you want to run again (Y/N)?" << endl;
            cin >> yesOrNo;
            //If the input is wrong let the user know. Restart Loop.

        }

        if (yesOrNo == 'Y' || yesOrNo == 'y')
        {
              //If User wants to continue then code won't do anything.
              // Instead the loop will restart.
        }
        else if (yesOrNo == 'N' || yesOrNo == 'n')
        {
              //If the user wants to stop then exit loop to end program.
              break;
        }


    }
    while(yesOrNo == 'Y' || yesOrNo == 'y'); //Program will only repeat if user says Y or y

    cout << "Good Bye" << endl;
    return 0;
}
