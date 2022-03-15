#include <iostream>
#include "simplevector.h"
// *****************************************************************
// * Template Assignment #6 simplevector.h                         *
// * Author: Claudio Osorio                                        *
// * Last Modified:  March 19th, 2021.                             *
// * Disclaimer: Some of the code that has been explicitely        *
// * requested to be used in this program pertains to Dr. Gaitros. *
// *****************************************************************

using namespace std;


int main(void)
{

/*
   const int SIZE = 10;
    SimpleVector<int> intTable (SIZE);
    cout <<  intTable.size() << endl;

    for (int index = 0; index < SIZE ; index++)
        intTable[index] = (index*2);

    for (int index  = 0; index < SIZE; index++)
        cout << intTable.getElementAt(index) << endl;

*/



  const int SIZE=10;
    int count= 0;
    SimpleVector<int> intTable(SIZE);
    SimpleVector<double> doubleTable(SIZE);

    cout <<"The size of intTable is: " << intTable.size()<<endl;
    cout <<"The size of doubleTable is " << doubleTable.size() <<endl;

    for (count=0; count<SIZE; count++)
    {
        intTable[count]= (count * 2);
        doubleTable[count] = (count * 2.14);
    }
// ******************************************************************
// * Tests the getElementAt(index) function. *
// ******************************************************************
    cout << "The element in the first position of intTable is " <<intTable.getElementAt(0)<<endl;
    cout << "These values are in intTable: \n";
    for (count=0; count< intTable.size(); count++)
        cout << intTable[count]<<' ' ;
    cout << endl;
    cout <<     "These are the values for the doubleTable\n";
    for (count=0; count <SIZE; count++)
        cout << doubleTable[count] << ' ';
    cout << endl;

// *******************************************************************
// * Add five to each element. Tests the [] overload operator. *
// *******************************************************************

    cout << "Adding five to each element" << endl;
    cout << "Checking the overload [] operator"<<endl;
    for (count=0; count < SIZE; count++)
    {
        intTable[count] = intTable[count]+5;
        doubleTable[count] = doubleTable[count] + 5.0;
    }

    cout << "These values are in intTable: \n";
    for (count=0; count< intTable.size(); count++)
        cout << intTable[count]<<' ';
    cout << endl;
    cout << "These are the values for the doubleTable\n";
    for (count=0; count <doubleTable.size(); count++)
        cout << doubleTable[count] <<' ';
    cout << endl;
// *****************************************************************
// * Tests the copy constructor. *
// *****************************************************************

    SimpleVector<double> CopyDouble(doubleTable);
    cout <<"The size of the copied vector is:" << CopyDouble.size()<< endl;
    cout << "These are the values for the copied table:\n";
    for (int index=0; index <CopyDouble.size(); index++)
        cout << CopyDouble[index] << ' ';
    cout<<endl;

    return 0;
}