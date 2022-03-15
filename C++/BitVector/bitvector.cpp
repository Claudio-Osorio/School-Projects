// Assignment 3
// Created by Claudio Osorio
#include "bitvector.h"
#include <iostream>
#include <iomanip>
#include <string>

//Constructor. Initially it will turn all the bits to off
//Default constructor allocates enough words to store 256 bits
BitVector::BitVector()
{
    size = 8;                                 //256/32 = 8 words
    bvect = new int[size];                    //bvect stores 8 words
}

//Constructor uses custom view range of Index# of bits
BitVector::BitVector(const size_t index)
{
    size = ( index/32 ) +1;             //Specifying how many words in total
    bvect = new int[size];
}



//Constructor initializes bitvector class based on another bitvector.
BitVector::BitVector(const BitVector & a)
{
    size = a.size;
    bitlocations = (a.bitlocations);
    bvect = (a.bvect);

}

//Destructor
BitVector::~BitVector()
{
}

//Copies vector. Right side is source, left side is the copy
// The ampersands indicate it is copying
//from the address of one to the address of the other one.
BitVector & BitVector:: operator = (const BitVector & a)
{
    size =(a.size);                  //size = a.size
    bitlocations = (a.bitlocations); //bitlocations = a.bitlocations
    bvect = a.bvect;                 //Sets BVect using a.size

    return * this;
    //must give the address back to the object on the left of the assignment operator
}

//Returns size
size_t BitVector::Size() const
{
    return size;
}


//Unset specific bit
void BitVector::Unset(const size_t bit)
{
    if (Test(bit) == true)
    {
    int mask = 1;
    //Moves the bit to  index location to be later turned on (1).
    mask = mask << (bit % 32);
    bvect[bit/32] = bvect[bit/32] ^ mask;

    }
}

//Sets all the words to zero (0) so all bits are zero (0)
void BitVector::Unset()
{
    for (int count = 0 ; count < size; count++)
    {
        bvect[count] = 0;
    }
}

// Passes in a constant integer zero or larger and turns
// that particular bit on.  If the bit value is out of range
// then take no action.
//Sets all the bits to ones (1)
//Moves the bit to  index location to be later turned on (1).
void BitVector::Set(size_t bit)
{
    int mask = 1;

    mask = mask << (bit % 32);
    bvect[bit/32] = bvect[bit/32] | mask;
}

//Sets all the bits to ON
void BitVector::Set()
{
    for (int x = 0; x <= Size();x++)
    bvect[x] = -1;
}

//Passes in a constant integer zero or larger and flips that particular bit.
// If the bit value is out of range then take no action
//Flips all the bits ON to OFF and viceversa.
// It displays a before and an after.
void BitVector::Flip(const size_t bit)
{
    int mask = 1;
    //Moves the bit to  index location to be later turned on (1).
    mask = mask << (bit % 32);
    bvect[bit/32] = bvect[bit/32] ^ mask;

}

//Flips all the bits
void BitVector::Flip()
{
    for(int x =0; x <= (Size()*32); x++)
    {
        Flip(x);
    }
}

//Check the bit passed in as a positive integer value.
//Return a True if the bit is set to one, otherwise return zero.
//If the value is out of range then return zero.
 bool BitVector::Test(size_t bit) const
 {
     int mask  = 1;
     int results;
     mask = mask <<  (bit % 32); //Moves bit to the left "remainder" times
     results = bvect[bit/32] & mask;
     // Store 1 or TRUE in "results" if the word where the bit is stored
     // and the bit on the mask are both 1.
     if(results!=0) return true;
     else return false;
 }

 //Print the status of each bit.
 //You may elect to print only the bits turned on
 //or whether a bit is turned on or off
void BitVector::Print()
 {
     //loop goes through all the bits & says if they're  on or off
     for (int count = 0; count < (32 * Size()); count++)
         if( Test(count) == true )
         {
             cout << "Bit " << setw(3) << count  << " is ON"<<endl;
         }
         else
         {
             cout << "Bit " << setw(3) << count   << " is OFF"<<endl;
         }
 }


