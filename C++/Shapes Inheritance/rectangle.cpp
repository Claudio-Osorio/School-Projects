#include <iostream>
#include "shape.h"
#include "rectangle.h"

//**************************************
//*            CONSTRUCTORS            *
//**************************************
Rectangle::Rectangle()
{
    SetLength1(1.00);
    SetLength2(1.00);
}
//**************************************
//*       OVERLOADED CONSTRUCTOR       *
//**************************************
Rectangle::Rectangle(const double newLength1, const double newLength2)
{
    if (newLength1 < 1.00) SetLength1(1.00);
    else SetLength1(newLength1);

    if (newLength2 < 1.00) SetLength2(1.00);
    else SetLength2(newLength2);
}

//**************************************
//*      ACCESSORS AND MUTATORS        *
//**************************************
void Rectangle::SetLength1(const double newLength)
{
    length1 = newLength;
}
void Rectangle::SetLength2(const double newLength)
{
    length2 = newLength;
}
double Rectangle::GetLength1()  {return length1;}
double Rectangle::GetLength2()  {return length2;}

//**************************************
//*            CALCULATIONS            *
//**************************************
void Rectangle::CalculatePerimeter() { SetPerimeter((2 * GetLength1()) + (2 * GetLength2())); }
void Rectangle::CalculateArea()      { SetArea(GetLength1() * GetLength2());                      }

//**************************************
//*         VIRTUAL FUNCTION           *
//**************************************
void Rectangle::PrintData()
{
    cout << "The length1 of the RECTANGLE is: " << GetLength1() << endl;
    cout << "The length2 of the RECTANGLE is: " << GetLength2() << endl;
}