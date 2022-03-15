// Assignment 3
// Created by Claudio Osorio
// Disclaimer:
// Print, Set( int bit), and Test functions are based on Dr. David Gaitros work.
// All the other code was written by Claudio Osorio.
#include <iostream>
#include "bitvector.h"
#include <string>

using namespace std;

size_t ValidateInteger (const int minimumValue,const int indexToValidate);
void ValidateOption(string & option);
void ShowMenu(string & option);
void Macro(string option,BitVector & a, const size_t index,BitVector & b);
int main()
{
    BitVector   DefaultVector;        //Uses default 256bits constructor
    BitVector   CopyVector;        //This vector will store a copy

    int bit = -1;                     //Verified bitlocation
    string option;                 //Stores the command to be executed.
    char exitKey = 'y';

    cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n"
            "*Welcome to Claudio Osorio BitVector Program :)*\n"
            "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n"<<endl;

    cout << "+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+"
            "*   THIS IS YOUR SEMI RANDOM 256 BIT STRING   *"
          "\n*       IT WILL HAVE BIT# 16 OFF BEFORE       *"
          "\n*         THEN THE BIT# 16 WILL BE ON         *"
          "\n=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="<<endl;
    cout << "\n=+=BEFORE+=+"<<endl;
    DefaultVector.Unset(16);
    DefaultVector.Print();
    cout << "\n+=+=AFTER+=+="<<endl;
    DefaultVector.Set(16);
    DefaultVector.Print();

    cout <<  "\n**--*-*-*-**-*-*DETAILS:-*-*-*-**-**-*-*"
             "\n*   DefaultVector.Size() is:  " << DefaultVector.Size()
    <<" words *\n**--*-*-*-**--*-*-*-**--*-*-*-**-**-*-"  << endl;

    cout << "\n+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+"
            "\n*    ABOVE IS THE DEFAULT VECTOR.     *"
            "\n*    NOW LET'S CREATE A NEW VECTOR    *"
            "\n*     \"YourVector(YourIndex);\"        *"
            "\n+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+"<<endl;

    cout << "\n+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+"
            "\n*  Enter a positive integer representing  *"
            "\n*       the bit you want to change        *"
            "\n+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+"
            "\nENTER BIT#:";

    size_t index = ValidateInteger(0, bit);

    BitVector   YourVector(index);

        cout << "REMEMBER BIT "<< index
             << " IS \""<<((YourVector.Test(index)) ? "ON" : "OFF")
             <<"\" BEFORE YOU DO ANYTHING" << endl;

        while(exitKey=='y' || exitKey =='Y')
        {
            ShowMenu(option);

            Macro(option, YourVector, index,CopyVector);

            cout<<"\nTo continue testing please enter y or Y: ";
            cin >> exitKey;

        }

    return 0;
}

//Gets the string of bits  as a positive integer.
size_t ValidateInteger (const int minimumValue,const int indexToValidate)
{
    bool set = false;
    size_t validatedIndex =  indexToValidate;
    do
    {
        if(validatedIndex < minimumValue && set == true)
            cout << "Please try again. Enter a number "
                    "equal or greater than " << minimumValue <<": "<< endl;
        else set = true;

        cin >> validatedIndex;

    }
    while (validatedIndex < minimumValue && set == true);

return validatedIndex;

}


//Show possible commands
void ShowMenu(string & option)
{
    cout << "\n=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+"
            "\n*Select the procedure to be performed*"
            "\n=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+"
            "\nEnter any of the following commands to get started:"
            "\n*  set bit"
            "\n*  set all"
            "\n*  flip bit"
            "\n*  flip all"
            "\n*  unset bit"
            "\n*  unset all"
            "\n*  copy vectors"
            "\n*  print"
            "\n*  exit program"
            "\n\nENTER ONE: ";
    getline(cin,option);
    ValidateOption(option);
}

//Menu for commands. Bitvector a is YourVector... b is CopyVector
void Macro(string option,BitVector & a, const size_t index,BitVector & b)
{

    if (option == "exit program")
    {
        cout << "\nHope I'll see you again :'("<<endl;
        exit(0);
    }

    if (option != "print")
    {
        if (option != "copy vectors")
        {


        cout << "\n=+=BEFORE+=+"<<endl;
        a.Print();

        cout << "=+=AFTER=+=+" <<endl;
        }
        if (option == "set bit")
        {
            a.Set(index);
            a.Print();
            cout << "Your bit#"<< index << " is now " << ((a.Test(index)) ? "ON" : "OFF") <<endl;
        }

        if (option == "flip bit")
        {
            a.Flip(index);
            a.Print();
            cout << "Your bit#"<< index << " is now " << ((a.Test(index)) ? "ON" : "OFF") <<endl;

        }

        if (option == "unset bit")
        {
            a.Unset(index);
            a.Print();
            cout << "Your bit#"<< index << " is now " << ((a.Test(index)) ? "ON" : "OFF") <<endl;
        }

        if (option == "set all")
        {
            a.Set();
            a.Print();
            cout << "\nMagic. Isn't it? -Dr G. 2021"<<endl;
        }

        if (option == "flip all")
        {
            a.Flip();
            a.Print();
            cout << "The bits in your word have been flipped like a burger"<<endl;
        }

        if (option == "unset all")
        {
            a.Unset();
            a.Print();
            cout << "Danger Will Robinson! An EMP shut everything off" << endl;
        }

        if (option == "copy vectors")
        {
            b = a;
            cout << "\n=+=YourVector+=+"<<endl;
            a.Print();
            cout << "\n=+=CopyVector+=+"<<endl;
            b.Print();

            cout << "\n+=+=+=+ CopyVector = YourVector +=+=+=+"
                 <<"     *\n*   YourVector.Size() is:  " << a.Size()
                 <<" words   *\n*   CopyVector.Size() is:  " << b.Size()
                 <<" words   *\n+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="<<endl;

        }

    }else a.Print();
}

//Make sure the option chosen is a valid one
void ValidateOption(string & option)
{
    bool set = false;

    while (
            option != "set bit" &&
            option != "set all" &&
            option != "flip bit" &&
            option != "flip all" &&
            option != "unset bit" &&
            option != "unset all" &&
            option != "copy vectors" &&
            option != "print" &&
            option != "exit program" )
    {
        if (set)
            cout << "\nYour input is wrong. Please try again: ";

        set = true;
        getline(cin,option);

    }

}
