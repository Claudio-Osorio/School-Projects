// ***************************************************************************
// * File: linklist.cpp                                                      *
// * Description: Defines linklist.h for Assignment #8 Link List             *
// * Author: Claudio Osorio                                                  *
// * Date: April 13th, 2021                                                  *
// ***************************************************************************
#include <iostream>
#include <iomanip>
#include "linklist.h"
using namespace std;

//******************************************************************************
//* LinkList() is a constructor that declares and defines a dummy head, tail,  *
//*  and a count of records                                                    *
//******************************************************************************
LinkList::LinkList()
{
    head = new PieCake_struct;
    tail = new PieCake_struct;
    head->id = -1;
    head->fname = " ";
    head->lname = " ";
    head->mi = ' ';
    head->sex = ' ';
    head->pORc = ' ';
    head->prev = nullptr;
    head->next = tail;

    tail->id = 2147483647;
    tail->fname = "ZZZZZZZZZZZ";
    tail->lname = "ZZZZZZZZZZZ";
    tail->mi = ' ';
    tail->sex = ' ';
    tail->pORc = ' ';
    tail->next = nullptr;
    tail->prev = head;

    count = 0;
}

//**********************************************************************************
//* Empty() Checks if the list is empty by seeing if the tail comes after the head *
//**********************************************************************************
bool LinkList::Empty() { return (head->next == tail); }

//****************************************************************************
//* Size() returns the count of the records, that is the quantity of records *
//****************************************************************************
int  LinkList::Size() { return count; }

//**************************************************************************************
//*Find() takes in an id number and goes through all the records. It then returns true *
//* when the matching record is found. If there is no matching record it returns false *
//**************************************************************************************
bool LinkList::Find(const int idnumber)
{
    PieCake_struct * candidate;
    candidate = head->next;
    while ( candidate != tail )
    {
        if( candidate->id == idnumber )
        {
            current = candidate;
            return true;
        }
        candidate = candidate->next;
    }
    return false;
}

//**************************************************************************************************
//* Insert() goes through all the existing records and inserts the one passed in as an             *
//* argument in the correct location. This function makes sure it inserts it by alphabetical order.*
//**************************************************************************************************
void LinkList::Insert(PieCake_struct * p)
{
    current = head->next;
    while (current != tail && current->lname < p->lname)
        current = current->next;

    p->prev = current->prev;
    p->next = current;
    (current->prev)->next = p;
    current->prev = p;

    ++count;
}

//********************************************************************************************
//* Delete() links the previous and next records accordingly it then deletes the current one.*
//********************************************************************************************
bool LinkList::Delete()
{
    if (current == nullptr) { return false;}
    else
    {
        (current->prev)->next = current->next;
        (current->next)->prev = current->prev;
        delete current;
        --count;
        return true;
    }
}

//************************************************************************************
//*   Print() goes through all the existing records and prints each one using List() *
//*  it then proceeds to print the total counts for records, and survey answers      *
//************************************************************************************
void LinkList::Print()
{
    current = head->next;
    cout << "--   ----------       -  ----------    --------     ------   \n"
            "ID   First Name       MI Last Name       Sex        Answer   \n"
            "--   ----------       -  ----------    --------     ------   "<<endl;
    while (current != tail)
    {
        List();
        current = current->next;
    }

    cout << "Total who thought cheesecake is pie:  " << CountPie() << endl;
    cout << "Total who thought cheesecake is cake: " << CountCake() << endl;
    cout << "Total Number of records: " << Size() << endl;
}

//************************************************************************************************
//* List() prints the formatted output of the current record. It also autocompletes small phrases*
//************************************************************************************************
void LinkList::List()
{
    PieCake_struct * thisRecord;
    thisRecord = current;
    cout << setw(6) << left << thisRecord->id << setw(16)  <<  thisRecord->fname << setw(3)
         << thisRecord->mi << setw(15) << thisRecord->lname  << setw(12)
         << ((thisRecord->sex == 'M') ? "Male" : (thisRecord->sex == 'F') ? "Female" : "Other")
         << ((thisRecord->pORc == 'P') ? "Pie" : "Cake") << endl;
}

//****************************************************************************************
//*  This is the destructor which frees space by deleting all the records, head and tail *
//****************************************************************************************
LinkList::~LinkList()
{
    PieCake_struct * candidate;
    candidate = head->next;

    while (candidate != tail)
    {
        current = candidate;
        candidate = candidate->next;
        delete current;
    }

    delete head;
    delete tail;
    count = 0;
}

//**********************************************************************************************
//*  CountPie() goes through all the records and adds up to a total number of mentions for Pie *
//**********************************************************************************************
int LinkList::CountPie()
{
    int pieCount = 0;
    PieCake_struct * candidate;
    candidate = head->next;
    while (candidate != tail)
    {
        if (candidate->pORc == 'P')
            ++pieCount;

        candidate = candidate->next;
    }
    return pieCount;
}

//***********************************************************************************************
//* CountCake() goes through all the records and adds up to a total number of mentions for Cake *
//***********************************************************************************************
int LinkList::CountCake()
{
    int cakeCount = 0;
    PieCake_struct * candidate;
    candidate = head->next;
    while (candidate != tail)
    {
        if (candidate->pORc == 'C')
            ++cakeCount;

        candidate = candidate->next;
    }
    return cakeCount;
}
