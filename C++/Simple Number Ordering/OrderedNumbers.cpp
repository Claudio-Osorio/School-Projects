/*
 *
 * Name: Claudio Osorio
 * Date: 09/16/2020
 * Section: Module 4
 * Assignment: Should I applaud and Ordered Numbers Programs
 * Due Date: Sep 20 by 11:59pm EST
 * About this project: This program will take the input for 3 numbers and store them. The numbers will be compared
 * and they will be printed to the screen once they are sorted in descending order.
 * Assumptions: The assumptions are that the user will enter 3 whole numbers when required.
 * All work below was performed by Claudio Osorio
 *
 */

#include <iostream>


using namespace std;
int main() {
int num1, num2, num3; //Declaring the variables to store the numbers

    cout << "Welcome! This is Claudio's Program ORDERED NUMBERS.\nPlease your numbers below\n" << endl;
    //Asking for the input for the 3 numbers required
    cout << "Please enter in a number ...";
    cin >> num1;

    cout << "\nPlease enter in a number ...";
    cin >> num2;

    cout << "\nPlease enter in a number ...";
    cin >> num3;

    //If the 3 numbers are the same let the user know
    if (num1 == num2 && num2 == num3)
    {
        cout << "\nAll the numbers are equal. Please restart the program" <<endl;
    }
    //Order:  Num3<=num2<=num1
    else if ( num1 >= num2 && num1 >= num3 && num2 >= num3)
    {
        cout << num3 << endl << num2 << endl << num1 << endl;

    }
    //Order:  Num1<=num2<=num3
    else if (num1 <= num2 && num1 <= num3 && num2 <= num3)
    {
        cout << num1 << endl << num2 << endl << num3 << endl;
    }
    //Order:  Num1<=num3<=num2
    else if (num1 <= num2 && num1 <= num3 && num2 >= num3)
    {
        cout << num1 << endl << num3 << endl << num2 <<endl;
    }
    //Order:  Num2<=num1<=num3
    else if (num1 >= num2 && num1 <= num3 && num2 <= num3)
    {
        cout << num2 << endl << num1 << endl << num3 <<endl;

    }
    //Order:  Num2<=num3<=num1
    else if (num1 >= num2 && num1 >= num3 && num2 <= num3)
    {
        cout << num2 << endl << num3 << endl << num1 << endl;
    }
    //Order:  Num3<=num1<=num2
    else if (num1 <= num2 && num1 >= num3 && num2 >= num3)
    {
        cout << num3 << endl << num1 << endl << num2 << endl;
    }
    return 0;
}
