#ifndef BINARY_TREES_BET_H
#define BINARY_TREES_BET_H
#include <string>
#include <stack>
#include <list>
using namespace std;

bool IsOperator(string element);
bool HasHigherOrEqualPrecedence(string val1, string val2);
bool ValidExpression(list<string> expression);

class BET
{
public:
    BET();
    BET(const string & postfix);
    BET(const BET &);
    ~BET();
    bool buildFromPostfix(const string & postfix);
    const BET & operator= (const BET &);
    void printInfixExpression();
    void printPostfixExpression();
    size_t size();
    size_t leaf_nodes();
    bool empty();

private:

    struct BinaryNode
    {
        string    element;       // The data in the node
        BinaryNode  *left;       // Left child
        BinaryNode *right;       // Right child

    };

    BinaryNode *root;
    void printInfixExpression(BinaryNode *n);
    void makeEmpty(BinaryNode* &t);
    BinaryNode * clone(BinaryNode *t);
    void printPostfixExpression(BinaryNode *n);
    size_t size(BinaryNode *t);
    size_t leaf_nodes(BinaryNode* t);
};

//******************************************
//* INCLUDING IMPLEMENTATIONS IN "bet.hpp" *
//******************************************
#include "bet.hpp"

#endif
