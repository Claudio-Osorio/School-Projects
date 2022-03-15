#include <iostream>
#include "shape.h"
#include "square.h"

//**************************************
//*            CONSTRUCTORS            *
//**************************************
Square::Square()
{
    SetLength(1.00);
}

//**************************************
//*       OVERLOADED CONSTRUCTOR       *
//**************************************
Square::Square(const double newLength)
{
    if (newLength < 1) SetLength(1.00);
    else SetLength(newLength);
}

//**************************************
//*      ACCESSORS AND MUTATORS        *
//**************************************
void Square::SetLength(const double newLength)      { length = newLength; }
double Square::GetLength()                          { return length;      }

//**************************************
//*            CALCULATIONS            *
//**************************************
void Square::CalculatePerimeter() { SetPerimeter(4 * GetLength()); }
void Square::CalculateArea()      { SetArea(GetLength() * GetLength()); }

//**************************************
//*         VIRTUAL FUNCTION           *
//**************************************
void Square::PrintData()
{
    cout << "The side of the SQUARE is: " << GetLength() << endl;
}