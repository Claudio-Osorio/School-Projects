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

#ifndef TLIST_HPP
#define TLIST_HPP

#include <list>
#include <iterator>

using namespace std;

//           #*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#
//           *      IMPLEMENTATION FOR TListIterator CLASS     *
//           #*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#

// *****************************************
// * CONSTRUCTOR: Creating a new Iterator  *
// *****************************************
template <typename T>
TListIterator<T>::TListIterator()
{
    ptr = nullptr;
}

// *******************************************************************
// * HasNext: Returns a true/false if there's a next item available  *
// *******************************************************************
template <typename T>
bool TListIterator<T>::HasNext() const
{
    if (ptr->next != nullptr)
        return true;
    else return false;
}

// ***************************************************************************
// * HasPrevious: Returns a true/false if there's a previous item available  *
// ***************************************************************************
template <typename T>
bool TListIterator<T>::HasPrevious() const
{
    if (ptr->prev != nullptr)
        return true;
    else return false;
}

// ********************************************************
// * Next: Sets the iterator to the next item in the list *
// ********************************************************
template <typename T>
TListIterator<T> TListIterator<T>::Next()
{
    if (HasNext())
        ptr = ptr->next;

    return *this;
}

// ********************************************************
// * Previous: Sets the iterator to the next item in the list *
// ********************************************************
template <typename T>
TListIterator<T> TListIterator<T>::Previous()
{
    static TListIterator<T> prevIterator;
    if (HasPrevious())
    {
        ptr = ptr->prev;
        prevIterator.ptr = ptr;
    }
    return  prevIterator;
}

// *********************************************************
// * GetData: Returns the data element in the current node *
// *********************************************************
template <typename T>
T&  TListIterator<T>::GetData() const
{
    return ptr->data;
}

//           #*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#
//           *      IMPLEMENTATION FOR TList CLASS     *
//           #*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#

// ***********************************************
// * CONSTRUCTOR: Creating an empty linked list  *
// ***********************************************
template <typename T>
TList<T>::TList()
{
    first = new class Node<T> (dummy);
    last  = new class Node<T> (dummy);

    first->next = last;
    last->prev = first;

    size = 0;
}

// **********************************************************************
// * OVERLOADED CONSTRUCTOR: Creates "num" copies of "T" element "val"  *
// **********************************************************************
template <typename T>
TList<T>::TList(T val, int num)
{
    first = new  class Node<T> (dummy);
    last  = new class Node<T> (dummy);

    first->next = last;

    last->prev = first;

    size = 0;

    for (int copyCount = 0; copyCount < num; copyCount++)
    {
        InsertFront(val);
    }
}

// ********************************************************************
// * ~TList: DESTRUCTOR. Frees memory and deletes all items when they *
// * lose all their dependencies                                      *
// ********************************************************************
template <typename T>
TList<T>::~TList()
{

    Node<T>* start;
    start = first->next;
    while (start != last)
    {
        Node<T>* temp;
        temp = start;
        start = start->next;
        temp = nullptr;
        delete temp;
    }
    first =nullptr;
    last =nullptr;
    delete first;
    delete last;
    size = 0;

}


// **********************************************************
// * Copy constructor: Copies list passed in to current one *
// **********************************************************
template <typename T>
TList<T>::TList(const TList& L)
{
    first = L.first;
    last  = L.last;
    size  = L.size;
}


// *********************************************************
// * Copy assignment operator: Assigns the lists LHS = RHS *
// *********************************************************
template <typename T>
TList<T>& TList<T>::  operator=(const TList& L)
{
    if(this != &L)
    {
        first = L.first;
        last  = L.last;
        dummy = L.dummy;
        size  = L.size;
    }

    return *this;
}


// *********************
// * Move Constructor  *
// *********************
template <typename T>
TList<T>::TList(TList && L)
{
    first  = move(L.first);
    last   = move(L.last);
    size   = move(L.size);
    dummy  = move(L.dummy);

}


// ************************************************************
// * My assignment operator: Takes the data passed in from    *
// * the right and moves it to the local list (left)          *
// ************************************************************
template <typename T>
TList<T>& TList<T>:: operator=(TList && L)
{
    swap (first , L.first);
    swap (last  , L.last );
    swap (size  , L.size );
    swap (dummy , L.dummy);

    return *this;
}


// ******************************************************************
// * IsEmpty: Returns True/False when the list is one or the other  *
// ******************************************************************
template <typename T>
bool TList<T>::IsEmpty() const
{
    if (first->next == last)
    return true;
    else return false;
}


// **************************************************************************
// * Clear:Clears out the list. It deletes the data and sets it to be empty *
// **************************************************************************
template <typename T>
void TList<T>::Clear()
{
    while (!IsEmpty())
    {
        RemoveBack();
    }
}


// *****************************************
// * GetSize: Returns the size of the list *
// *****************************************
template <typename T>
int TList<T>::GetSize() const
{
    return size;
}


// *************************************************************
// * InsertFront: Inserts the value passed in to the beginning *
// *  of the list and moves the existing values                *
// *************************************************************
template <typename T>
void TList<T>::InsertFront(const T& d)
{
    static TListIterator<T> itr;
    itr.ptr = first->next;
    Insert(itr,d);
}


// *************************************************************************
// * InsertBack: Inserts the value passed in to the ending of the          *
// * list and moves the existing values so they go before the inserted one *
// *************************************************************************
template <typename T>
void TList<T>::InsertBack(const T& d)
{
    Node<T>* newNode;
    newNode = new Node<T>(d);

    newNode->next = last;
    newNode->prev = last->prev;
    (last->prev)->next = newNode;
    last->prev = newNode;

    size +=1;

}


// *****************************************************************
// * RemoveFront: Removes the first element of the list (not head) *
// *****************************************************************
template <typename T>
void TList<T>::RemoveFront()
{
    if(!IsEmpty())
    {
        static Node<T>* temp;
        temp = first->next;
        first->next = temp->next;
        (temp->next)->prev = first;
        delete temp;

        size -= 1;
    }
}


// ***************************************************************
// * RemoveBack: Removes the last element of the list (not tail) *
// ***************************************************************
template <typename T>
void TList<T>::RemoveBack()
{
    static Node<T>* thirdToLastElement;

    thirdToLastElement       = (last->prev)->prev;
    thirdToLastElement->next = last;
    last->prev               = thirdToLastElement;

    size -= 1;
}


// ***************************************************
// * GetFirst: Returns the first element of the list *
// ***************************************************
template <typename T>
T& TList<T>::GetFirst() const
{
    return first->data;
}


// *************************************************
// * GetLast: Returns the last element of the list *
// *************************************************
template <typename T>
T& TList<T>::GetLast() const
{
    return last->data;
}


// *******************************************************
// * GetIterator: Returns the iterator to the first item *
// *******************************************************
template <typename T>
TListIterator<T> TList<T>:: GetIterator() const
{
    static TListIterator<T> itr;
    itr.ptr = first->next;

    return itr;
}


// *********************************************************
// * GetIteratorEnd: Returns the iterator to the last item *
// *********************************************************
template <typename T>
TListIterator<T> TList<T>:: GetIteratorEnd() const
{
    static TListIterator<T> itr;
    if (!IsEmpty())
    itr.ptr = last->prev;
    else itr.ptr = last;
    return itr;
}


// *******************************************************************
// * Insert: Inserts data element d just before item at pos position *
// *******************************************************************
template <typename T>
void TList<T>::Insert(TListIterator<T> pos, const T& d)
{
    static Node<T> *newNode;
    static Node<T> *nodeToMove;

    newNode = new Node<T>(d);
    nodeToMove = pos.ptr;

    if (nodeToMove->prev == nullptr)
    {
        first->next = newNode;
        newNode->prev = first;
        newNode->next = nodeToMove;
        nodeToMove->prev = newNode;

    }else
    {
    newNode->next = nodeToMove;
    newNode->prev = nodeToMove->prev;
    (nodeToMove->prev)->next = newNode;
    nodeToMove->prev = newNode;
    }


    size+=1;
}


// ***********************************************************************
// * Remove: Removes data item at position pos.                          *
// * Return iterator to the item that comes after the one being deleted. *
// ***********************************************************************
template <typename T>
TListIterator<T> TList<T>::Remove(TListIterator<T> pos)
{
    if(pos.ptr != first)
    {
        static Node<T> *itemToRemove;
        itemToRemove = pos.ptr;
        (itemToRemove->prev)->next = itemToRemove->next;
        (itemToRemove->next)->prev = itemToRemove->prev;
        size -= 1;
    }

    return pos.Next();
}


// **********************************************************
// * Print: Prints the list contents in order, separated    *
// * by given delimiter.                                    *
// **********************************************************
template <typename T>
void TList<T>::Print(std::ostream& os, char delim) const
{
    static TListIterator<T> itr;
    itr.ptr = first->next;

   while (itr.HasNext())
    {
        os << itr.GetData() << delim;
        itr.Next();
    }
}


// ***************************************************************
// * OPERATOR+: Stand-alone function for concatenating two TList *
// *  objects                                                    *
// ***************************************************************

template <typename T>
TList<T> operator+(const TList<T>& t1, const TList<T>& t2)
{
    static TList<T> myNewList;
    TListIterator<T> t1_Itr;
    TListIterator<T> t2_Itr;
    myNewList.Clear();

    t1_Itr = t1.GetIterator();
    t2_Itr = t2.GetIterator();

    while (t1_Itr.HasNext())
    {
        myNewList.InsertBack(t1_Itr.GetData());
        t1_Itr.Next();
    }

    while (t2_Itr.HasNext())
    {
        myNewList.InsertBack(t2_Itr.GetData());
        t2_Itr.Next();
    }

    return myNewList;
}
#endif