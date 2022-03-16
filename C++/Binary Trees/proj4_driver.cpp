// ********************************************************************
// *                    Name: Claudio Osorio                          *
// * Description:                                                     *
// *      This program uses lists, stacks, classes and structures     *
// *      This program will evaluate an expression  and convert it    *
// *      from postfix to infix notation and back to postfix          *
// *       notation by using stacks and binary trees made with nodes  *
// *                    Date: July 1, 2021                            *
// *                    Last Checked: July 1, 2021                    *
// * Disclaimer: Some parts of this code were provided by Dr. Gaitros *
// * in his videos. I have adapted some of my own code that I         *
// * used in previous assignments of this same course                 *
// * I have also inspired my code and used small parts from examples  *
// *  provided  by the book "Data Structures Algorithm Analysis       *
// * in C++ by Mark A. Weiss" and from the website geeksforgeeks.com  *
// *                                                                  *
// * This code has been tested in linprog and compiled with no errors *
// * a copy of the output should have been provided in the comments of*
// * the submission of this assignment. Thanks                        *
// ********************************************************************

#include <iostream>
#include <string>
#include "bet.h"

using namespace std;

int main() {
    string postfix;

    // get a postfix expression
    cout << "Enter the first postfix expression: ";
    getline(cin, postfix);

    // create a binary expression tree
    BET bet1(postfix);
    if (!bet1.empty()) {
        cout << "Infix expression: ";
        bet1.printInfixExpression();

        cout << "\nPostfix expression: ";
        bet1.printPostfixExpression();

        cout << "\nNumber of nodes: ";
        cout << bet1.size() << endl;

        cout << "Number of leaf nodes: ";
        cout << bet1.leaf_nodes() << endl;

        // test copy constructor
        BET bet2(bet1);
        cout << "Testing copy constructor: ";
        bet2.printInfixExpression();

        // test assignment operator
        BET bet3;
        bet3 = bet1;
        cout << "\nTesting assignment operator: ";
        bet3.printInfixExpression();
    }

    cout << "\nEnter a postfix expression (or \"quit\" to quit): ";
    while (getline(cin, postfix)) {
        if (postfix == "quit") {
            break;
        }
        if (bet1.buildFromPostfix(postfix)) {
            cout << "\nInfix expression: ";
            bet1.printInfixExpression();

            cout << "\nPostfix expression: ";
            bet1.printPostfixExpression();

            cout << "\nNumber of nodes: ";
            cout << bet1.size() << endl;

            cout << "Number of leaf nodes: ";
            cout << bet1.leaf_nodes() << endl;
        }
        cout << "\nEnter a postfix expression (or \"quit\" to quit): ";
    }
    return 0;
}
