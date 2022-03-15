
#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
#include <iterator>
#include <list>
#include <initializer_list>
using namespace std;

const int DEFAULTSIZE = 100;
template <class T>
class Stack {
public:
    Stack();                                // Default Constructor, stack is size 100.
    Stack(const int size);                  // Constructor, creates stack of size "size"
    Stack(const Stack<T> & item);           // Copy constructor
    bool Full();                            // Return true if the stack is full
    bool Empty();                           // Return true if the stack is empty
    int Size();                             // Return the size of the stack
    T Top();                                // Returns the top element, does not pop it.
    bool Push (const T item);               // Put an item on the stack.
    bool Pop();                             // Pop an item off and display to std out
    void PrintAllElements();                // Prints all the elements stored in the stack
    Stack & operator = (const Stack<T> &a); // Assigns two stacks to be equal
    ~Stack();                               // Deletes the memory allocation
    bool operator == (const Stack<T> &a);   // == operator will be used to compare two stacks
                                            // and see if they are equal or not
    friend ostream &operator <<(ostream & os, Stack<T> &s)
        {
            if (s.Empty() == true) {
                os << "ERROR: Stack is empty" << endl;
            } else {
                os << s.Top() << endl;
                s.Pop();

                return os;
            }

        }
private:
    T * _stack;                 // The "stack"
    int _size;                  // The number of elements the stack can hold
    int _top;                   // Points to the first empty node
};

#endif

//------------ T E M P L A T E -- I M P L E M E N T A T I O N -------------
//***********************************************************************
//* Constructor - Gives size and specifies the top element of the stack *
//***********************************************************************
template <class T>
Stack<T>::Stack()
{
    _stack = new T [DEFAULTSIZE];
    _size  = DEFAULTSIZE;
    _top   = 0;

    for (int x = 0; x < DEFAULTSIZE; x ++)
        _stack[x]=x+100;

}

//*******************************************************************************************
//* Overloaded Constructor - Gives a custom size and specifies the top element of the stack *
//*******************************************************************************************
template <class T>
Stack<T>::Stack(const int size)
{
    int newSize = size;
    if (newSize < 1) {newSize = DEFAULTSIZE;}

    _size  = newSize;
    _stack = new T [newSize];
    _top   = 0;

    for (int x = 0; x < newSize; x ++)
        _stack[x]=x + 100;
}

//*******************************************************************************
//* Copy Constructor - Copies the item passed in to the left side class element *
//*******************************************************************************
template<class T>
Stack<T>::Stack(const Stack<T> & item)
{
    _size  = item._size;
    _stack = new T [DEFAULTSIZE];
    _top = item._top;
    for(int element = 0; element <= item._size; element++)
        _stack[element] = item._stack[element];
}

//************************************
//* Return true if the stack is full *
//************************************
template<class T>
bool Stack<T>::Full()
{
    if(_top >= _size)
    { return true; }
    else { return false; }
}

//***************************************
//*  Returns true if the stack is empty *
//***************************************
template<class T>
bool Stack<T>::Empty()
{
    if (_top == 0)
    { return true; }
    else { return false; }
}

//********************************
//*Returns the size of the stack *
//********************************
template<class T>
int Stack<T>::Size(){ return _size;}

//********************************************
//* Returns the top element, does not pop it *
//********************************************
template<class T>
T Stack<T>::Top()
{
    if (Empty())
    { return 0; }
    else { return _stack[_top - 1]; }
}

//****************************
//* Put an item on the stack *
//****************************
template<class T>
bool Stack<T>::Push (const T item)
{
    if (Full() == false)
    {
        cout << "Pushing " << item << " into index " << _top << endl;
        _stack[_top] = item;
        _top += 1;
        return true;
    }else
    {
        cout << "ERROR: The stack is full. "
                "You are trying to add something to index " << _top <<
                " but \n _stack maxes out with " << _size  <<" elements" << endl;
        return false;
    }
}

//********************
//* Pop an item off  *
//********************
template<class T>
bool Stack<T>::Pop ()
{
    if(Empty() == true)
    {
        cout << "ERROR: The stack is empty. You cannot pop because there are no elements" << endl;
        return false;
    }
    else
    {
        cout << "Popping out " << _stack[_top - 1] << endl;
        _top -= 1;
        return true;
    }

}

//*************************
//* Print stack elements  *
//*************************
template<class T>
void Stack<T>::PrintAllElements()
{
    for (int element = 0; element < _top; element++)
    cout <<" " << _stack[element];

}

//*****************************
//*  Assignment Operator (=)  *
//*****************************
template<class T>
Stack<T> & Stack<T> :: operator = (const Stack<T> & a)
{
    if (&a != this) {
        _stack = (a._stack);
        _size = (a._size);
        _top = (a._top);
        for (int element = 0; element <= a._size; element++)
            _stack[element] = a._stack[element];
    }

    return *this;
}

//******************************
//*  Comparison Operator (==)  *
//******************************
template <class T>
bool Stack<T> :: operator==(const Stack<T> &a)
{
return (_stack == a._stack && _size == a._size && _top == a._top );
}

//****************
//*  Destructor  *
//****************
template<class T>
Stack<T>::~Stack()
{
    if(!Empty())
    delete[]  _stack;
}