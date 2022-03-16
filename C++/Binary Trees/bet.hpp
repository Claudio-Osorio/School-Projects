
#ifndef BINARY_TREES_BET_HPP
#define BINARY_TREES_BET_HPP
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <iterator>
using namespace std;
//****************************************
//* BET(): Constructor for the class BET *
//****************************************
BET::BET()
{
    root = nullptr;
}

//*****************************************************
//* Constructor for the class BET, takes in a postfix *
//* expression and creates a tree.                    *
//*****************************************************
BET::BET(const string & postfix)
{
    buildFromPostfix(postfix);
}

//*************************************************
//* Copy Constructor: Makes deep copy of the tree *
//*************************************************
BET::BET(const BET & other)
{
    root = clone(other.root);
}

//*******************************
//* Destructor of the class BET *
//*******************************
BET::~BET()
{
    makeEmpty(root);
    delete root;
}

//***************************************************************
//* Uses string argument of a postfix expression to make a tree *
//***************************************************************
bool BET::buildFromPostfix(const string & postfix)
{
    istringstream  myStream(postfix);
    stack<BinaryNode*> stack;
    string expression;
    list<string> listExpression;

    while (myStream >> expression)
    {
        listExpression.push_back(expression);
    }

    auto itr = listExpression.begin();

    if (!ValidExpression(listExpression))
    {
        root = nullptr;
        return false;
    }

    if (listExpression.size() == 1)
    {
        BinaryNode * aNewNode = new BinaryNode;
        aNewNode->element = listExpression.front();
        aNewNode->left  = nullptr;
        aNewNode->right = nullptr;
        root = aNewNode;
        return true;
    }

    itr = listExpression.begin();

    while (itr != listExpression.end())
    {
            if (IsOperator(*itr))
            {
                if (stack.size() < 2)
                {
                    cout << "Error: The expression is invalid" << endl;
                    return false;
                }
                BinaryNode* operandL = new BinaryNode;
                BinaryNode* operandR = new BinaryNode;
                operandR = clone(stack.top());
                stack.pop();
                operandL = clone(stack.top());
                stack.pop();

                BinaryNode* operatorNode = new BinaryNode;
                operatorNode->element = *itr;
                operatorNode->left = operandL;
                operatorNode->right = operandR;

                stack.push(operatorNode);
                root = clone(operatorNode);

            } else //It is an operand
            {
                BinaryNode * aNewNode = new BinaryNode;
                aNewNode->element = *itr;
                aNewNode->left  = nullptr;
                aNewNode->right = nullptr;
                stack.push(aNewNode);
            }
        itr++;
    }
    if (stack.size() != 1)
    {
        cout << "Error: The expression is invalid" << endl;
        return false;
    } else { return true; }
}

//********************************************
//* Assignment operator that makes deep copy *
//********************************************
const BET & BET::operator= (const BET & other)
{
    root = clone(other.root);
    return *this;
}

//***********************************************
//* Recursively Prints out the infix expression *
//***********************************************
void BET::printInfixExpression()
{
    printInfixExpression(root);
}

//*************************************************
//* Recursive - Prints out the postfix expression *
//*************************************************
void BET::printPostfixExpression()
{
    printPostfixExpression(root);
}

//*******************************************************
//* Recursive - Returns the number of nodes in the tree *
//*******************************************************
size_t BET::size()
{
    return size(root);
}

//************************************************************
//* Recursive - Returns the number of leaf nodes in the tree *
//************************************************************
size_t BET::leaf_nodes()
{
    return leaf_nodes(root);
}

//******************************************************
//* Returns true when tree is empty else returns false *
//******************************************************
bool BET::empty()
{
if (root == nullptr)
    { return true; }
    else { return false; }
}

//********************************************************************
//* prints to the standard output the corresponding infix expression *
//* it  adds parentheses depending on the precedence of operators    *
//********************************************************************
void BET::printInfixExpression(BinaryNode *n)
{
    //When subtree root is not operator -> print out
    if (!IsOperator(n->element))
    {
        cout << n->element << ' ';
    } else
    {
        //When left child of subtree is not operator
        // go recursive for left subtree
        if (!IsOperator(n->left->element))
        {
            printInfixExpression(n->left);

        //When left child is operator and has less precedence
        //then put parenthesis on it
        } else if ( IsOperator(n->left->element)
        && HasHigherOrEqualPrecedence(n->element, n->left->element))
        {
            cout << '(' << ' ';
            printInfixExpression(n->left);
            cout << ')' << ' ';
        } else
        { //When left child is not operator o has higher precedence
          //do not put parenthesis on it they are not needed
            printInfixExpression(n->left);
        }

        //Print the root
        cout << n->element << ' ';

        //When right child is not operator -> print out
        if (!IsOperator(n->right->element))
        {
            cout << n->right->element << ' ';
        } else
        {
         //When right child is not operator
         //go recursive for left subtree
            if (!IsOperator(n->right->element))
            {
                printInfixExpression(n->right);
            //When right child is operator and has less precedence
            //then put parenthesis on it
            } else if (IsOperator(n->right->element)
            && HasHigherOrEqualPrecedence(n->element,n->right->element))
            {
                cout << '(' << ' ';
                printInfixExpression(n->right);
                cout << ')' << ' ';
            } else
                //When right child is not operator o has higher precedence
                //do not put parenthesis on it they are not needed
                printInfixExpression(n->right);
        }
    }

}

//*****************************************************************
//* Deletes all nodes in the subtree pointed to by the argument t *
//*****************************************************************
void BET::makeEmpty(BinaryNode* &t)
{
    t->element = '\0';
    if (t->left != nullptr)
        makeEmpty(t->left);
    else
    {
        delete t->left;
    }

    if (t->right != nullptr)
        makeEmpty(t->right);
    else
    {
        delete t->right;
    }

    t = nullptr;

}

//***************************************************
//* Clones all nodes in the subtree pointed to by t *
//***************************************************
BET::BinaryNode* BET::clone(BinaryNode *t)
{
    if (t == nullptr)
    { return nullptr; }
    else
    {
        BinaryNode * newNode = new BinaryNode;
        newNode->element = t->element;
        newNode->left    = clone(t->left);
        newNode->right   = clone(t->right);

        return newNode;
    }

}

//********************************************************
//* Prints to the standard output the postfix expression *
//********************************************************
void BET::printPostfixExpression(BinaryNode *n)
{
    //When subtree root is not operator -> print out
    if (!IsOperator(n->element))
    {
        cout << n->element << ' ';
    } else
    {
        //When left child of subtree is operator
        // go recursive for left subtree
        if (IsOperator(n->left->element))
        {
            printPostfixExpression(n->left);
        } else
        {
            cout << n->left->element << ' ';
        }

        //When right child of subtree is operator
        // go recursive for right subtree
        if (IsOperator(n->right->element))
        {
            printPostfixExpression(n->right);
        } else
        {
            cout << n->right->element << ' ';
        }

        //Print the root
        cout << n->element << ' ';
    }

}

//**************************************************************
//* Returns the number of nodes in the subtree pointed to by t *
//**************************************************************
size_t BET::size(BinaryNode *t)
{
    if(t->left == nullptr)
    {
        return 1;
    }
    else
    {
        return 1 + size(t->right) + size(t->left);
    }
}

//*******************************************************************
//* Returns the number of leaf nodes in the subtree pointed to by t *
//*******************************************************************
size_t BET::leaf_nodes(BinaryNode* t)
{
    if(t->left == nullptr)
        return 1;
    else
        return leaf_nodes(t->left) + leaf_nodes(t->right);
}

bool IsOperator(string element)
{
    if (element[0] == '+' || element[0] == '-' || element[0] == '*' || element[0] == '/' )
    { return true; }
    else { return false; }
}

bool HasHigherOrEqualPrecedence(string val1, string val2)
{
    int val1precedence = 0;
    int val2precedence = 0;

     if (val1[0] == '*' || val1[0] == '/')
        val1precedence = 2;
    else if (val1[0] == '-' || val1[0] == '+')
        val1precedence = 1;

    if (val2[0] == '*' || val2[0] == '/')
        val2precedence = 2;
    else if (val2[0] == '-' || val2[0] == '+')
        val2precedence = 1;

    if (val1precedence > val2precedence || val1precedence == val2precedence)
    { return true; }
    else { return false; }

}


bool ValidExpression(list<string> expression)
{
    if (expression.size() == 1 )
    {
        if (IsOperator(expression.front()))
        {
            cout << "Error: A postfix expression cannot start with an operator" << endl;
            return false;
        } else { return true; }

    } else if (expression.size() == 2)
    {
        cout << "Error: The expression is missing operators or operands" << endl;
        return false;
    }

    auto itr = expression.begin();
    int operators = 0;
    int operands = 0;

    while (itr != expression.end())
    {
        if(IsOperator(*itr))
            operators += 1;

        if(!IsOperator(*itr))
            operands += 1;
        itr++;
    }

    if(operators + 1 != operands)
    {
        cout << "Error: Postfix expression is invalid due to operator/operand ratio" << endl;
        return false;
    }
    else { return true; }

}

#endif
