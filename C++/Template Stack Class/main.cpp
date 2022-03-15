// Created by Claudio Osorio on 03/29/21.
// ********************************************************************
// *                    Name: Claudio Osorio                          *
// * Description:  A template Stack class designed to be used with    *
// *      any simple C++ type to include floating point, double       *
// *             floating point, character, and boolean.              *
// *                    Date: March 29, 2021                          *
// *                    Last Checked: April 2, 2021                   *
// * Disclaimer: Small parts of this code (in stack.hpp) were provided*
// * by Dr. Gaitros, the rest was written by me, Claudio Osorio.      *
// * This code has been tested in linprog and compiled with no errors *
// * a copy of the output should have been provided in the comments of*
// * the submission of this assignment. Thanks                        *
// ********************************************************************

#include <iostream>

#include "stack.hpp"
using namespace std;

int main(void)

{
    cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*"
            "\n*\t\t\tAssignment #7 Templates\t\t\t*"
            "\n*\t\t    Author: Claudio Osorio\t\t\t*"
            "\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << endl;

    //*******************************************
    //* DRIVER - TESTING ALL THE FUNCTIONALITY  *
    //*******************************************

    //****************************************
    //* Default Constructor - Test Int Stack *
    //****************************************
    cout<<"Please notice if the stack is empty then the last element \"Top()\" will return is \"zero\"" << endl;

    Stack<int> IntStack;
    cout <<  "\n\n* Int - Default Constructor Test  "
             "\nStack<int> IntStack;" <<
             "\nStack<int> IntStack | Empty() is: " << IntStack.Empty() <<
             "\nStack<int> IntStack | Full()  is: " << IntStack.Full() <<
             "\nStack<int> IntStack | Size()  is: " << IntStack.Size() <<
             "\nStack<int> IntStack | Top()   is: " << IntStack.Top() <<
             "\nStack<int> IntStack printing Elements (should be empty): ";
    IntStack.PrintAllElements();

    //*********************************************
    //* Overloaded Constructor - Test Float Stack *
    //*********************************************
    Stack<float> Float5 (5);
    cout << "\n\n* Float - Overload Constructor Test  *"
         "\nStack<float> Float5(5);" <<
         "\nStack<float> Float5(5) | Empty() is: " << Float5.Empty() <<
         "\nStack<float> Float5(5) | Full()  is: " << Float5.Full() <<
         "\nStack<float> Float5(5) | Size()  is: " << Float5.Size() <<
         "\nStack<float> Float5(5) | Top()   is: " << Float5.Top() <<
         "\nStack<float> Float5 printing Elements (should be empty): ";
    Float5.PrintAllElements();

    //**********************************************
    //* Overloaded Constructor - Test Double Stack *
    //**********************************************
    Stack<double> Double8(8);   // Test Double Stack
    cout << "\n\n* Double - Overload Constructor Test *"
            "\nStack<double> Double8(8);" <<
         "\nStack<double> Double8(8) | Empty() is: " << Double8.Empty() <<
         "\nStack<double> Double8(8) | Full()  is: " << Double8.Full() <<
         "\nStack<double> Double8(8) | Size()  is: " << Double8.Size() <<
         "\nStack<double> Double8(8) | Top()   is: " << Double8.Top() <<
         "\nStack<double> Double8(8) printing Elements (should be empty): " ;
    Double8.PrintAllElements();

    //***********************************************
    //* Overloaded Constructor - Test Boolean Stack *
    //***********************************************
    Stack<bool> Bool2(2);
    cout << "\n\n* Boolean - Overload Constructor Test *"
            "\nStack<bool> Bool2(2);" <<
         "\nStack<bool> Bool2(2); | Empty() is: " << Bool2.Empty() <<
         "\nStack<bool> Bool2(2); | Full()  is: " << Bool2.Full() <<
         "\nStack<bool> Bool2(2); | Size()  is: " << Bool2.Size() <<
         "\nStack<bool> Bool2(2); | Top()   is: " << Bool2.Top() <<
         "\nStack<bool> Bool2(2); printing Elements (should be empty): ";
    Double8.PrintAllElements();

    //***********************************************
    //* Testing Push and Pop                        *
    //* 4th Push should give error as stack is full *
    //* 3rd Pop should give error as stack is empty *
    //***********************************************
    cout << "\nBool2.Push(true);\nResult: " << endl;
    Bool2.Push(true);
    cout << "Bool2.Push(true);\nResult: " << endl;
    Bool2.Push(false);
    cout << "Bool2.Push(true); (should give error, stack is size 2)\n Answers: " << endl;
    Bool2.Push(true);
    cout << "Printing the stack: ";
    Bool2.PrintAllElements();

    cout<<"\nNow testing the Pop():"
          "\n(3rd one should give error)"<<endl;
    Bool2.Pop();
    Bool2.Pop();
    Bool2.Pop();

    //***********************************************
    //* Testing Default Copy Constructor with Char  *
    //***********************************************
    cout << "\n\n* Testing Default Copy Constructor|  Stack<char> Charcy(Char10); *" <<endl;
    Stack<char> Char10;
    Stack<char> Charcy(Char10);

    //************************************
    //* Testing Pushing Chars to Char10  *
    //************************************
    cout << "Testing Pushing chars A,B,C to Char10;" << endl;
    Char10.Push('A');
    Char10.Push('B');
    Char10.Push('C');
    cout << "Char10.Pop();  | (should produce a 'C'): ";
    Char10.Pop();
    cout << "Printing the stack: " << endl;
    Char10.PrintAllElements();
    cout << "\nNow Pushing the 'C' again: " << endl;
    Char10.Push('C');
    cout << "Printing the stack: ";
    Char10.PrintAllElements();

    //*****************************
    //* Testing ostream overload  *
    //*****************************
    cout << "\n\n* Testing ostream overloads *"<<endl;
    cout << "cout << Charcy; | (should be Empty):  ";
    cout << Charcy;
    cout << "cout << Char10; | (should be a 'C'): ";
    cout <<Char10;
    cout << "cout << Char10; | (should be a 'B'): ";
    cout <<Char10;
    cout << "cout << Char10; | (should be a 'A'): ";
    cout <<Char10;
    cout << "cout << Char10; | (should be an error): ";
    cout <<Char10;

    //************************************************************
    //*    Creating Stacks OriginalStack and CopyStack           *
    //*     to test if the assignment operator works             *
    //*    OriginalStack will have 'Y', 'E', 'S' while           *
    //*   CopyStack will be empty. After == both will be equal   *
    //************************************************************

    cout << "\n\n* Creating and pushing elements into Stack<char> OriginalStack; *"<<endl;
    Stack<char> OriginalStack;
    OriginalStack.Push('Y');
    OriginalStack.Push('E');
    OriginalStack.Push('S');
    cout << "Printing the stack \"OriginalStack\": ";
    OriginalStack.PrintAllElements();
    cout << "\nCreating an empty stack | Stack<char> CopiedStack;"<<endl;
    Stack<char> CopiedStack;
    cout << "Printing the stack \"CopiedStack\" (should be empty): " << endl;
    CopiedStack.PrintAllElements();
    cout << "Assigning: OriginalStack = CopiedStack;"<<endl;
    OriginalStack = CopiedStack;

    cout << "\n* Testing OriginalStack == CopiedStack *"<<endl;
    if (OriginalStack == CopiedStack) { cout << "The stacks are equal" << endl; }
    else { cout << "The stacks are different" << endl; }

    cout << "\n* Testing OriginalStack == Char10 *"<<endl;
    if (OriginalStack == Char10) { cout << "The stacks are equal" << endl; }
    else { cout << "The stacks are different" << endl; }

    return 0;
}
