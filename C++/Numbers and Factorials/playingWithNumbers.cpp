/* Name: Claudio Osorio
 * Date: 10/10/2020
 * Section: Module 6
 * Assignment: Playing with Numbers Program
 * Due Date: Oct 10 by 11:59pm EST
 * About this project:  This Program will compute the factorial of a number and
 * compute the alternating factorial of a number.
 * Assumptions:
 * -The user will follow the instructions while running or entering numbers in the program.
 * -The user understands the program will restart after the result is displayed.
 * -The user will not expect any functionality not explicitly specified.
 *
 * All work below was performed by Claudio Osorio
 *
 */

#include <iostream>
#include <cstdlib> // I MUST include this or the EXIT function won't compile in G++!!!

void menu();
void validateMenuNumber(int &menuNum);
void optionOne();
void getValidUserInputPosNumGT0 (int &num);
long  double factorial(int);
void optionTwo();
long double AlternatingFactorial (int num);



using namespace std;
int main() {
    int menuNum=0;
    cout <<"Welcome to Playing with Numbers Program by Claudio Osorio" << endl;

    while (menuNum != 3)
    {
        //Printing the Menu to the screen
        menu();
        //Storing the selecting menu option
        cin >> menuNum;
        //Validating Menu Option
        validateMenuNumber(menuNum);

        //Using the input from user to toggle to a desired function/subprogram
        switch(menuNum)
        {
            case 1:
                //Users Selected Compute the factorial of a number
                optionOne();
                break;
            case 2:
                //User Selected Compute the alternating factorial of a number
                optionTwo();
                break;
            case 3:
                //User Selected Quit
                exit(EXIT_SUCCESS);
            default:
                //2nd Safe for Incorrect Menu Option Input
                exit(EXIT_FAILURE);
        }
    }
    return 0;
}

void menu()
{
    //Printing the menu to the screen
    cout <<"1. Compute the factorial of a number\n"
           "2. Compute the alternating factorial of a number\n"
           "3. Quit\n"
           "Select an option (1, 2 or 3) ...  ";
};


void validateMenuNumber(int &menuNum)
{
    //Validating User Enters Only Existing Menu Options/Numbers
    while(menuNum <= 0 || menuNum > 3)
    {
        cout << "Select an option (1,2 or 3).. ";
        cin >> menuNum;
    }
};

//Compute the factorial of a number
void optionOne()
{
    int num = 0;
    long double numFactorial;

    //Validating Input
    getValidUserInputPosNumGT0 (num);

    //Obtaining Factorial from given Num
    numFactorial = factorial(num);
    cout << "Factorial (" << num << ") = " << numFactorial <<endl;
};

void getValidUserInputPosNumGT0 (int &num)
{
    cout << "Enter in a positive number greater than 0...  ";
    cin >> num;

    //Validating input is greater than 0. (Positive)
    while(num <= 0)
    {
        cout << "Enter in a positive number greater than 0...  ";
        cin >> num;
    }
};

long double factorial (int num)
{
    //Calculating Factorial of Num
    long double factorial=1;
    for(int i = 1; i <=num; ++i)
    {
        factorial *= i;
    }

    return factorial;
};

//Compute the alternating factorial of a number
void optionTwo()
{
    int num;
    long double numAlterFac;

    //Validating input and obtaining alternating factorial
    getValidUserInputPosNumGT0 (num);

    //Obtaining Alternating Factorial of Num
    numAlterFac = AlternatingFactorial(num);

    //Printing result to the screen
    cout << "AlternatingFactorial(" << num << ") = " << numAlterFac <<endl;
};

//produces a AlternatingFactorial  from the number sent as a parameter and returns it;
long double AlternatingFactorial (int num)
{
    long double numAlterFac = 0;
    long double serie;

    //Alternating Factorial Calculation
    for (int i = 1; i<=num; i++)
    {
        //Serie is positive when the number is even
        if(i%2 == 0)
            serie = factorial(i);
        //Serie is negative when the number is odd
        if(i%2 == 1)
            serie = factorial(i)  * -1;

        numAlterFac += serie;
    }
    //Making the answer positive
    if (numAlterFac < 0)
        numAlterFac *= -1;

    return numAlterFac;

};
