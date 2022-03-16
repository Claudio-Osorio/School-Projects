// ********************************************************************
// *                    Name: Claudio Osorio                          *
// *         Assignment #2: Iterators and const iterators             *
// *                                                                  *
// *                         Date: June 7 2021                        *
// *                    Last Checked: Jun 11, 2021                    *
// * Disclaimer: Some parts of this program were provided by          *
// *   Dr. Gaitros via assignment instructions. I have used part      *
// *   of the examples given by the book  "Data Structures Algorithm  *
// *   Analysis in C++ by Mark A. Weiss". My code was also inspired   *
// *   by some examples from geeksforgeeks.org and learncpp.com       *
// *   However, all the code was written or adapted by me.            *
// *   This code has been tested in linprog and compiled with         *
// *   no errors. A copy of the output should have been provided      *
// *   in the comments of this submission                             *
// ********************************************************************

#include "List.h"
#ifndef LIST_HPP
#define LIST_HPP

//          ***********************************************************
//          * NESTED "const_iterator" CLASS FUNCTIONS IMPLEMENTATIONS *
//          ***********************************************************


// **********************************
// * Constructor for const_iterator *
// **********************************
template<typename T>
List<T>::const_iterator::const_iterator()
{
    current = nullptr;
}

// *********************************************************************
// * Overloading  operator* to make it retrieve the data within a node *
// *********************************************************************
template<typename T>
const T & List<T>::const_iterator:: operator*() const
{
    return retrieve();
}

// *******************************************************************************
// * Overloading the ++ operator to go next on the object of type const_iterator *
// *******************************************************************************
template<typename T>
typename List<T>::const_iterator & List<T>::const_iterator::operator++()
{
    current = current->next;
    return *this;
}

// *******************************************************************************
// * Overloading the ++ operator to go next on the object of type const_iterator *
// *******************************************************************************
template<typename T>
typename List<T>::const_iterator List<T>::const_iterator:: operator++(int)
{
    const_iterator myItr = *this;
    ++(*this);
    return myItr;
}

// *******************************************************************************
// * Overloading the -- operator to go back on the object of type const_iterator *
// *******************************************************************************
template<typename T>
typename List<T>::const_iterator &  List<T>::const_iterator:: operator--()
{
    current = current->prev;
    return *this;
}

// *******************************************************************************
// * Overloading the -- operator to go back on the object of type const_iterator *
// *******************************************************************************
template<typename T>
typename List<T>::const_iterator List<T>::const_iterator:: operator--(int)
{
    const_iterator myItr = *this;
    --(*this);
    return myItr;
}

// *******************************************************
// * Overloading the == operator so that it returns true *
// * two objects of type const_iterator are equal        *
// *******************************************************
template<typename T>
bool List<T>::const_iterator:: operator==(const const_iterator &rhs) const
{
    if (*this == rhs)
        return true;
    else return false;
}

// ***********************************************************************
// * Overloaded != operator that compares objects of time const iterator *
// ***********************************************************************
template<typename T>
bool List<T>::const_iterator::operator!=(const const_iterator &rhs) const
{
    return (this->current != rhs.current);
}

// ****************************************************************
// * retrieve() will return the data of the parent const_iterator *
// ****************************************************************
template<typename T>
T & List<T>::const_iterator::retrieve() const
{
    return this->current->data;
}

// **********************************************************************************
// * Constructor for const_iterator that sets the current node to the one passed in *
// **********************************************************************************
template<typename T>
List<T>::const_iterator::const_iterator(Node *p)
{
    current = p;
}

//          **********************************************
//          * "iterator" CLASS FUNCTIONS IMPLEMENTATIONS *
//          **********************************************

// ********************************************************************
// * Constructor for the iterator. Sets the iterator to point nothing *
// ********************************************************************
template<typename T>
List<T>::iterator::iterator()
{
    this->current = nullptr;
}

// *****************************************************************
// * Operator* overloading to make it return de-referenced T value *
// *****************************************************************
template<typename T>
T & List<T>::iterator:: operator*()
{
    return this->current->data;
}

// ******************************************************************************
// * Overload of the * operator which will return the referenced iterator value *
// ******************************************************************************
template<typename T>
const T & List<T>::iterator:: operator*() const
{
    return this->retrieve();
}

// ******************************************************************************
// * Overload of the ++ operator which returns the next object of type iterator *
// ******************************************************************************
template<typename T>
typename List<T>::iterator & List<T>::iterator:: operator++()
{
    this->current = (this->current)->next;
    return *this;
}

// ******************************************************************************
// * Overload of the ++ operator which returns the next object of type iterator *
// ******************************************************************************
template<typename T>
typename List<T>::iterator List<T>::iterator:: operator++(int)
{
    iterator old = *this;
    ++(*this);
    return old;
}

// ******************************************************************************
// * Overload of the -- operator which returns the prev object of type iterator *
// ******************************************************************************
template<typename T>
typename List<T>::iterator & List<T>::iterator:: operator--()
{
/*    typename List<T>::iterator currentItr = *this;
    this->current = this->current->prev;
    return currentItr;*/
    const_iterator::current = const_iterator::current->prev;
    return *this;
}

// ******************************************************************************
// * Overload of the -- operator which returns the prev object of type iterator *
// ******************************************************************************
template<typename T>
typename List<T>::iterator List<T>::iterator:: operator--(int)
{
/*    typename List<T>::iterator myItr = *this;
    --*this;
    return myItr;*/
    const_iterator::current = const_iterator::current->prev;
    return *this;
}

// *************************************************************************
// * Constructor for the iterator. Sets the iterator to the node passed in *
// *************************************************************************
template<typename T>
List<T>::iterator::iterator(Node *p)
{
    this->current = p;
}

//          ******************************************
//          * "List" CLASS FUNCTIONS IMPLEMENTATIONS *
//          ******************************************

// ****************************************************
// * Constructor for the List class being initialized *
// ****************************************************
template<typename T>
List<T>::List()
{
    init();
}

// *******************************************************
// * Constructor that creates a list using rhs passed in *
// *******************************************************
template<typename T>
List<T>::List(const List &rhs)
{
    init();
    for(auto & x : rhs)
        push_back(x);
}

// ************************************************
// * Constructor deep copying rhs passed (rvalue) *
// ************************************************
template<typename T>
List<T>::List(List && rhs)
{
    theSize = rhs.theSize;
    head = rhs.head;
    tail = rhs.tail;
    rhs.theSize = 0;
    rhs.head = nullptr;
    rhs.tail = nullptr;
}

// ****************************************************************
// * Constructor insert  "num" qty of elements all with value "T" *
// ****************************************************************

template<typename T>
List<T>::List(int num, const T& val)
{
    init();
    clear();
    for (int x = 0; x < num; x++)
    {
        push_back(val);
    }
}

// ***************************************************************************
// * Constructs a List with elements from another list between start and end *
// * Includes the element referred to by the start iterator,                 *
// * but not the end iterator, that is [start, end).                         *
// ***************************************************************************
template<typename T>
List<T>::List(const_iterator start, const_iterator end)
{
    init();
    auto myItr = start;
    while (myItr != end)
    {
        push_back(*myItr);
        myItr++;
    }

}

// **********************************************************************
// * Construct a List with elements from the initializer list that is   *
// * passed in. Note that this will allow declarations like this:       *
// *              List myList {2, 4, 6, 8, 10, 12, 14, 16};             *
// **********************************************************************
template<typename T>
List<T>:: List (std::initializer_list<T> iList)
{
    init();
    for (auto  & x : iList)
        push_back(x);
}

// ****************************************************************************
// * Destructor - Clears the memory by deleting all the elements of the lists *
// ****************************************************************************
template<typename T>
List<T>::~List()
{
    clear();
    delete head;
    delete tail;
}

// *************************************
// * Copy Assignment Operator Overload *
// *************************************
template<typename T>
const List<T> & List<T>:: operator=(const List &rhs)
{
    init();
    clear();
    const_iterator myItr = rhs.begin();
    for(int x = 0; x < rhs.size(); x++)
    {
        push_back(myItr.retrieve());
        myItr++;
    }
    return *this;
}

// *************************************
// * Move Assignment Operator Overload *
// *************************************

template<typename T>
List<T> & List<T>::operator=(List && rhs)
{
    std::swap(theSize, rhs.theSize);
    std::swap(head, rhs.head);
    std::swap(tail,rhs.tail);
    return *this;
}

// ******************************************************
// * Assignment Operator Overload:                      *
// * Sets list to the elements of the initializer_list  *
// ******************************************************
//
template<typename T>
List<T> & List<T>:: operator= (std::initializer_list<T> iList)
{
    init();
    for (auto & x:iList )
        push_back(x);
    return *this;
}

// *********************************************
// * Return the number of elements in the list *
// *********************************************
template<typename T>
int List<T>::size() const
{
    return theSize;
}

// *******************************
// * Checks if the list is empty *
// *******************************
template<typename T>
bool List<T>:: empty() const
{
    if(theSize == 0)
        return true;
    else return false;
}

// ******************************************
// * Removes all the elements from the list *
// ******************************************
template<typename T>
void List<T>:: clear()
{
    while(!empty())
        pop_back();
}

// **********************************************************************
// * Reverts the order of the list. For example if {1,2,3} then {3,2,1} *
// **********************************************************************
template<typename T>
void List<T>:: reverse()
{
    List<T> newList;
    iterator oldItr = begin();
    for (int x = 0; x < theSize; ++x)
    {

        newList.push_front(oldItr.current->data);
        oldItr++;
    }
    *this = newList;
}

// **************************************************************
// * Returns the T data stored in the first element of the list *
// **************************************************************
template<typename T>
T & List<T>:: front()
{
    return (head->next)->data;
}

// **************************************************************
// * Returns the T data stored in the first element of the list *
// **************************************************************
template<typename T>
const T& List<T>:: front() const
{
    return (head->next)->data;
}

// *************************************************************
// * returns the T data stored in the last element of the list *
// *************************************************************
template<typename T>
T& List<T>:: back()
{
    return (tail->prev)->data;
}

// *************************************************************
// * returns the T data stored in the last element of the list *
// *************************************************************
template<typename T>
const T& List<T>:: back() const
{
    return (tail->prev)->data;
}

// ************************************************************
// * Inserts an item to occupy the first position on the list *
// ************************************************************
template<typename T>
void List<T>:: push_front(const T & val)
{
    insert(begin(),val);
}

// *********************************************************************
// * Inserts an item to occupy the first position on the list (rvalue) *
// *********************************************************************
template<typename T>
void List<T>:: push_front(T && val)
{
    std::swap((head->next)->data, val);
}

// ***********************************************************
// * Inserts an item to occupy the last position on the list *
// ***********************************************************
template<typename T>
void List<T>:: push_back(const T & val)
{
    insert(end(),val);
}

// ********************************************************************
// * Inserts an item to occupy the last position on the list (rvalue) *
// ********************************************************************
template<typename T>
void List<T>:: push_back(T && val)
{
    std::swap((tail->prev)->data, val);
}

// *******************************************
// * Removes the first element from the list *
// *******************************************
template<typename T>
void List<T>:: pop_front()
{
    erase(begin());
}

// ******************************************
// * Removes the last element from the list *
// ******************************************
template<typename T>
void List<T>:: pop_back()
{
    typename List<T>::iterator  myItr = end();
    myItr--;
    erase(myItr);
}

// ************************************************************************
// * Removes the element that has T data matching the one passed in (val) *
// ************************************************************************
template<typename T>
void List<T>:: remove(const T &val)
{
    typename List<T>::iterator myItr = begin();
    while (myItr != end())
    {
        if (myItr.retrieve() == val)
            myItr = erase(myItr);
        else
            myItr.current = myItr.current->next;
    }
}

// *********************************************************************
// * Removes all elements from which the predicate "pred" returns true *
// * in this project Pred will be the "isOdd" function from the driver *
// *********************************************************************

template <typename T>
template <typename PREDICATE>
void  List<T>:: remove_if(PREDICATE pred)
{
    typename List<T>::iterator myItr = begin();
    while (myItr != end())
    {
        if (pred(myItr.current->data))
            myItr = erase(myItr);
        else
            myItr.current = myItr.current->next;
    }
}

// **********************************************************************
// * Print out all elements and uses "ofc" as the delimiter for spacing *
// **********************************************************************
template <typename T>
void List<T>:: print(std::ostream& os, char ofc) const
{
    auto myItr = begin()++;

    while (myItr != end())
    {
        os << myItr.current->data << ofc;
        myItr++;
    }
}

// ***************************************************
// * Sets the iterator to the first node on the list *
// ***************************************************
template<typename T>
typename List<T>::iterator List<T>:: begin()
{
    return iterator(head->next);
}

// ***************************************************
// * Sets the iterator to the first node on the list *
// ***************************************************
template<typename T>
typename List<T>::const_iterator List<T>::begin() const
{
    return const_iterator(head->next);
}

// **************************************************
// * Sets the iterator to the last node on the list *
// **************************************************
template<typename T>
typename List<T>::iterator List<T>:: end()
{
    return iterator(tail);
}

// **************************************************
// * Sets the iterator to the last node on the list *
// **************************************************
template<typename T>
typename List<T>::const_iterator List<T>:: end() const
{
    return const_iterator(tail);
}

// ********************************************************************************
// * Inserts T value "val" right below the location pointed by the iterator "itr" *
// ********************************************************************************
template<typename T>
typename List<T>::iterator List<T>:: insert(iterator itr, const T& val)
{
    theSize++;
    Node* myNode;
    myNode = itr.current;
    Node* newNode;
    newNode = new Node{val, myNode->prev, myNode};
    myNode->prev->next = newNode;
    myNode->prev = newNode;
    iterator myItr;
    myItr.current = myNode->prev;

    return myItr;
}

// *************************************************************
// * Inserts T value "val" right below the location pointed by *
// * the iterator "itr"  (rvalue)                              *
// *************************************************************
template<typename T>
typename List<T>::iterator List<T>:: insert(iterator itr, T && val)
{
    auto* currentNode = itr.current;
    theSize++;
    auto* newNode = new Node;
    (currentNode->prev)->next = newNode;
    currentNode->prev = newNode;
    typename List<T>::iterator myItr{newNode};
    return myItr;
}

// ***********************************************************
// * Erases the node pointed by the iterator passed in "itr" *
// ***********************************************************
template<typename T>
typename List<T>::iterator List<T>::  erase(iterator itr)
{
    if (itr != end())
    {
        auto *myPtr = itr.current;
        typename List<T>::iterator myItr{myPtr->next};
        myPtr->prev->next = myPtr->next;
        myPtr->next->prev = myPtr->prev;
        delete myPtr;
        theSize--;
        return myItr;
    } else { return itr; }
}

// *******************************************************************************
// * Erases the nodes that start from the locations pointed by "start" and "end" *
// *******************************************************************************
template<typename T>
typename List<T>::iterator   List<T>:: erase(iterator start, iterator end)
{
    for( iterator itr = start; itr!=end; )
    {
        itr = erase(itr);
    }

    return end;
}

// *********************************************************************
// * Helping function that will serve to initialize other constructors *
// *********************************************************************
template<typename T>
void List<T>::init()
{
    theSize = 0;
    head = new Node;
    tail = new Node;

    head->next = tail;
    tail->prev = head;
    head->prev = nullptr;
    tail->next = nullptr;
}

// *************************************************************
// * == operator used to compare two elements of the same type *
// *************************************************************
template <typename T>
bool operator==(const List<T> & lhs, const List<T> &rhs)
{
    bool answer = true;
    if( lhs.size() == rhs.size())
    {
        auto rhs_itr = rhs.begin();

        for(auto lhs_itr = lhs.begin(); lhs_itr != lhs.end(); lhs_itr++)
        {
            if(*lhs_itr != *rhs_itr)
            {
                answer = false;
                break;
            }
            ++(rhs_itr);
        }
        return answer;
    }
    else
        return false;
}

// ********************************************************
// * != returns true or false when lhs and rhs dont match *
// ********************************************************
template <typename T>
bool operator!=(const List<T> & lhs, const List<T> &rhs)
{
    return !(lhs == rhs);
}

// ***************************************************************
// * Overload to the output operator. Allows to print the result *
// ***************************************************************
template <typename T>
std::ostream & operator<<(std::ostream &os, const List<T> &l)
{
    l.print(os);
    return os;
}
#endif
