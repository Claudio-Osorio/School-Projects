#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;
// ***************************************************************
// * Template Assignment simplevector.h                          *
// * Description:  Contains the basic definition of the          *
// * SimpleVector Template class.                                *
// * Author: Claudio Osorio                                      *
// * Last Modified:  March 22, 2021.                             *
// * Disclaimer: Some parts of the code were provided by         *
// * Dr. Gaitros as part of the assignment.                      *
// ***************************************************************
template <class T>
class SimpleVector {
private:
    // *****************************************
    // *    aptr - Points to allocated array     *
    // *****************************************
    T *aptr;

    // ***********************************************
    // * arraysize - Number of elements in the array *
    // ***********************************************
    int arraysize;

    // *************************************************
    // * memError() - Handles memory allocation errors *
    // *************************************************
    void memError();

    // ************************************************
    // * subError() - Handles subscripts out of range *
    // ************************************************
    void subError();
public:
    // ***********************
    // * Default Constructor *
    // ***********************
    SimpleVector() { aptr = 0; arraysize = 0;}

    // *****************************
    // *  Constructor Declaration  *
    // *****************************
    SimpleVector(int);

    // **********************************
    // *  Copy Constructor Declaration  *
    // **********************************
    SimpleVector(const SimpleVector &);

    // ***************
    // *  Destructor *
    // ***************
    ~SimpleVector();
    // ***************************************
    // *  Accessor to return the array size  *
    // ***************************************
    int size() const;

    // *****************************************
    // * Accessor to return a specific element *
    // *****************************************
    T getElementAt(int sub);

    // *****************************************
    // *   Overload [] Operator Declaration    *
    // *****************************************
    T &operator[](const int &);
};

#endif //SIMPLEVECTOR_H

    // #=#=#+#=#=#=#+#=#=#=#+#=#=#=#+#=#=#=#+#=#=#=#+#=#=#
    // #=#=#+#=          IMPLEMENTATION           #=#=#+#=
    // #=#=#+#=#=#=#+#=#=#=#+#=#=#=#+#=#=#=#+#=#=#=#+#=#=#

    // ****************************************************
    // * memError() Implementation for SimpleVector Class *
    // * NOTE: Displays error and ends program            *
    // ****************************************************
template <class T>
void SimpleVector<T>::memError()
{
    cout << "ERROR: cannot allocate memory." << endl;
    exit (EXIT_FAILURE);
}

    // ****************************************************
    // * subError() Implementation for SimpleVector Class *
    // * NOTE:   Handles subscripts out of range          *
    // ****************************************************
template <class T>
void SimpleVector<T>::subError()
{
    cout << "ERROR: The subscript is out of range.\nThis program will end" << endl;
    exit (EXIT_FAILURE);
}

    // ***********************************************************
    // * Constructor for SimpleVector Class                      *
    // * NOTES:                                                  *
    // * -If memory alloc fails go to error and exit program.    *
    // * -Initialize array to zeros                              *
    // ***********************************************************
template <class T>
SimpleVector <T>::SimpleVector(int s)
{
    if (s < 1) arraysize = 1;
    else       arraysize = s;
    try {
        aptr = new T [arraysize];
        }
        catch (bad_alloc)
        {
            memError();
        }


    for (int index = 0; index < arraysize; index++)
        aptr [index] = 0;

}

    // *************************************
    // * Copy Constructor - Implementation *
    // *************************************
template <class T>
SimpleVector<T> :: SimpleVector (const SimpleVector & sourceVector)
{
    arraysize = sourceVector.size();
    aptr = new T [ arraysize];
    if(aptr == 0)
    {
        memError();
    }

    for (int index = 0; index < arraysize; index++)
    {
        aptr[index]=sourceVector.aptr[index];
    }
}

    // **************
    // * Destructor *
    // **************
template <class T>
SimpleVector<T> :: ~SimpleVector()
{
    if (arraysize > 0)
    {
        delete aptr;
        aptr = nullptr;
    }
}

    // **********************************************
    // * Array Size - Accessor Implementation       *
    // * NOTE:  Accessor to return the array size   *
    // **********************************************

template <class T>
int SimpleVector<T> :: size() const
{
    return arraysize;
}

    // ************************************************
    // * Return Element - Accessor Implementation     *
    // * NOTE: Accessor to return a specific element  *
    // ************************************************

template <class T>
T SimpleVector<T> :: getElementAt(int sub)
{
    return *(aptr + sub);
}

// ********************************************
// *  Overload [] - Operator Implementation   *
// ********************************************

template <class T>
T & SimpleVector<T> :: operator[](const int & index)
{
    if (index >= arraysize)
    {
        subError();
    }
return aptr[index];
}
