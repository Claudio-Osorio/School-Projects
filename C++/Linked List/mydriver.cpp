// ********************************************************************
// *                    Name: Claudio Osorio                          *
// *         Assignment #1: Getting started with linked lists         *
// *                                                                  *
// * Description:   This is the implementation of a templated         *
// *   doubly-linked list class, along with an associated             *
// *   iterator class for helping with generic list traversals.       *
// *   In the doubly- linked list, each node has a pointer            *
// *   to the next node AND a pointer to the previous node            *
// *                                                                  *
// * Date: May 24, 2021                                               *
// * Last Checked: May 28, 2021                                       *
// * Disclaimer: Some parts of this program were provided by          *
// *   Dr. Gaitros via assignment instructions or lectures but        *
// *   the remainder of the code was written by me, Claudio Osorio    *
// *   This code has been tested in linprog and compiled with         *
// *   no errors. A copy of the output should have been provided      *
// *   in the comments of this submission                             *
// ********************************************************************


//PROVISIONAL TESTING... MAKE SURE TO EDIT THIS OUT AND ADD MORE TESTING

#include <iostream>
#include <string>
#include <iomanip>
#include "tlist.h"

    using namespace std;

    template <typename T>
void PrintList(const TList<T>& L, string label)
{
    cout << label << " size is: " << L.GetSize() << "\n"
         << label << " = ";
    L.Print(cout);
    cout << "\n\n";
}

int main()
{
    cout << "Made by Claudio Osorio" << endl;

// **********************************************************
// * INSERTING AT THE BACK AND FRONT WITH LISTS OF INTEGERS *
// **********************************************************
    cout << "### List containing integer elements 1 through 30 ###" << endl;
    cout << "List in increasing order [ L1.InsertBack(i) ]:" << endl;
    TList<int> L1;
    for (int i = 1; i < 31; i++)
        L1.InsertBack(i);
    PrintList(L1,"L1");

    cout << "Removing the last 10 elements [ L1.RemoveBack() ]:" << endl;
    for (int i = 0; i < 10; i++)
        L1.RemoveBack();
    PrintList(L1,"L1");

    cout <<"\nInsertBack:" << endl;
    L1.InsertBack(300);
    PrintList(L1,"L1");
    cout <<"\nInsertBack:" << endl;
    L1.InsertBack(100);
    PrintList(L1,"L1");
    cout <<"\nRemoveBack:" << endl;
    L1.RemoveBack();
    PrintList(L1,"L1");
    cout <<"\nInsertBack:" << endl;
    L1.InsertBack(52);
    PrintList(L1,"L1");
    cout <<"\nRemoveBack:" << endl;
    L1.RemoveBack();
    PrintList(L1,"L1");
    cout <<"\nInsertFront:" << endl;
    L1.InsertFront(255);
    PrintList(L1,"L1");
    cout <<"\nInsertFront:" << endl;
    L1.InsertFront(254);
    PrintList(L1,"L1");
    cout <<"\nRemoveFront:" << endl;
    L1.RemoveFront();
    PrintList(L1,"L1");
    cout <<"\nInsertBack:" << endl;
    L1.InsertBack(77);
    PrintList(L1,"L1");
    cout <<"\nRemoveBack:" << endl;
    L1.RemoveBack();
    PrintList(L1,"L1");
    cout <<"\nInsertFront:" << endl;
    L1.InsertFront(1000);
    PrintList(L1,"L1");
    cout <<"\nInsertFront:" << endl;
    L1.InsertFront(999);
    PrintList(L1,"L1");
    cout <<"\nRemoveFront:" << endl;
    L1.RemoveFront();
    PrintList(L1,"L1");

    cout << "List in decreasing order [ L2.InsertFront(i) ]:" << endl;
    TList<int> L2;
    for (int i = 1; i < 31; i++)
        L2.InsertFront(i);
    PrintList(L2,"L2");

    cout << "Removing the first 10 elements [ L2.RemoveFront() ]:" << endl;
    for (int i = 0; i < 10; i++)
        L2.RemoveFront();
    PrintList(L2,"L2");

// *******************************************************
// * INSERTING AT THE BACK AND FRONT WITH LISTS OF CHARS *
// *******************************************************
    cout << "### List containing 30 char elements ###" << endl;
    cout << "Defining list to be [TList<char> L3 ('B', 30) ]:" << endl;
    TList<char> L3 ('B', 30);
    PrintList(L3,"L3");

    cout << "Removing the last 20 elements using an iterator:" << endl;
    TListIterator<char> myCharItr = L3.GetIterator();
    for (int i = 0; i < 20; i++)
    {
        L3.Remove(myCharItr);
        myCharItr.Next();
    }
    PrintList(L3,"L3");

    cout << "Inserting a ('D') element 1 node away from the back using an iterator:" << endl;
    myCharItr = L3.GetIteratorEnd();
    L3.Insert(myCharItr,'D');
    PrintList(L3,"L3");


    cout << "Inserting a ('G') elements at the front using an iterator:" << endl;
    myCharItr = L3.GetIterator();
    L3.Insert(myCharItr,'G');
    PrintList(L3,"L3");

    cout << "Inserting a ('E') elements at the back using an iterator:" << endl;
    myCharItr = L3.GetIteratorEnd();
    L3.Insert(myCharItr.Next(),'E');
    PrintList(L3,"L3");

    cout << "Inserting a ('F') element as the 4th node (left to right) using an iterator:" << endl;
    myCharItr = L3.GetIterator();
    myCharItr.Next();
    myCharItr.Next();
    myCharItr.Next();
    L3.Insert(myCharItr,'F');
    PrintList(L3,"L3");


    cout << "Inserting 10 elements ('A') at the front using an iterator:" << endl;
    TListIterator<char> myCharItr2 = L3.GetIterator();
    for (int i = 0; i < 10; i++)
        L3.Insert(myCharItr2,'A');

    PrintList(L3,"L3");

    cout << "Inserting 10 ('C') elements 3 nodes away from the back using an iterator:" << endl;
    myCharItr2 = L3.GetIteratorEnd();
    myCharItr2.Previous();
    myCharItr2.Previous();
    for (int i = 0; i < 10; i++)
        L3.Insert(myCharItr2,'C');

    PrintList(L3,"L3");

    TList<string> classMatesNames;
    TListIterator<string> myStringItr = classMatesNames.GetIterator();
    classMatesNames.Insert(myStringItr, "Jabari Allen");
    classMatesNames.Insert(myStringItr, "Ashley Arnold");
    classMatesNames.Insert(myStringItr, "Alex Bernstein");
    classMatesNames.Insert(myStringItr, "Trevor Brooks");
    classMatesNames.Insert(myStringItr, "Joshua Bush");
    classMatesNames.Insert(myStringItr, "Aubrey Champagne");
    classMatesNames.Insert(myStringItr, "Evan Charles");
    classMatesNames.Insert(myStringItr, "Ersoy Demir");
    classMatesNames.Insert(myStringItr, "Andy Eisenmann");
    classMatesNames.Insert(myStringItr, "Edwin Flores");

    myStringItr = classMatesNames.GetIterator();
    cout << "Printing list of some classmates names using  myStringItr.Next()" << endl;

    while(myStringItr.HasNext())
    {
        cout << ' '<< myStringItr.GetData();
        myStringItr.Next();
    }

    cout << "\nUsing iterators to go through the list Front To Back"<< endl;
    myStringItr = classMatesNames.GetIterator();
    int number = 1;
    while(myStringItr.HasNext())
    {
        cout << number << ".- " << myStringItr.GetData() << endl;
        myStringItr.Next();
        number += 1;
    }

    cout << "\nUsing iterators to go through the list Back To Front"
            "\n(The numbers will not be altered)"<< endl;
    number = 1;
    myStringItr = classMatesNames.GetIteratorEnd();
    while(myStringItr.HasPrevious())
    {
        cout << number << ".- "<< myStringItr.GetData() << endl;
        myStringItr.Previous();
        number += 1;
    }


    cout << "\nJoining (+ operator) two lists of strings" << endl;
    TList<string> listOfStrings;
    listOfStrings.InsertBack("Kitchen");
    listOfStrings.InsertBack("Living Room");
    listOfStrings.InsertBack("Bedroom");
    listOfStrings.InsertBack("Terrace");
    listOfStrings.InsertBack("Garage");

    PrintList(listOfStrings,"listOfStrings");

    cout << "Resulting List: ";
    TList <string> both = listOfStrings + TList<string> ( "Bedroom", 5);
    TListIterator<string> listOfStringItr = both.GetIterator();
    while (listOfStringItr.HasNext())
    {
        cout << listOfStringItr.GetData() << ' ';
        listOfStringItr.Next();
    }

    cout<<"\n\n";

    cout << "Using the copy function (TList<string> placesInAHouse(listOfStrings)) :" << endl;
    TList<string> placesInAHouse(listOfStrings);
    PrintList(placesInAHouse,"placesInAHouse");

    cout << "Using the (=) and (+) in   [ L5 = listOfStrings + listOfStrings ]" << endl;
    TList<string> L5;
    L5 = listOfStrings + listOfStrings;

    PrintList(L5, "L5");

}
