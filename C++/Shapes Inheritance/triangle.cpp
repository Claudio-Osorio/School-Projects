#include <iostream>
#include "shape.h"
#include "triangle.h"
#include "cmath"

//**************************************
//*            CONSTRUCTORS            *
//**************************************
Triangle::Triangle()
{
    SetLength1(1.00);
    SetLength2(1.00);
    SetLength3(1.00);
}

//**************************************
//*       OVERLOADED CONSTRUCTOR       *
//**************************************
Triangle::Triangle(const double newLength1,const double newLength2,const double newLength3)
{
    if (newLength1 < 1) SetLength1(1.00);
    else SetLength1(newLength1);

    if (newLength2 < 1) SetLength2(1.00);
    else SetLength2(newLength2);

    if (newLength3 < 1) SetLength3(1.00);
    else SetLength3(newLength3);
}

//**************************************
//*      ACCESSORS AND MUTATORS        *
//**************************************
void Triangle::SetLength1(const double newLength)
{
    length1 = newLength;
}
void Triangle::SetLength2(const double newLength)
{
    length2 = newLength;
}
void Triangle::SetLength3(const double newLength)
{
    length3 = newLength;
}
double Triangle::GetLength1(){return length1;}
double Triangle::GetLength2(){return length2;};
double Triangle::GetLength3(){return length3;};

//**************************************
//*            CALCULATIONS            *
//**************************************
void Triangle::CalculatePerimeter()
{ SetPerimeter(GetLength1() + GetLength2() + GetLength3()); }

void Triangle::CalculateArea()
{   double result;
    double s  = (GetLength1() + GetLength2() + GetLength3())/2.00;
    result = sqrt(abs(s * (s - GetLength1()) * (s - GetLength2()) * (s - GetLength3())));
    SetArea(result);
}

//**************************************
//*         VIRTUAL FUNCTION           *
//**************************************
void Triangle::PrintData()
{
    cout << "The length1 of the TRIANGLE is: " << GetLength1() << endl;
    cout << "The length2 of the TRIANGLE is: " << GetLength2() << endl;
    cout << "The length3 of the TRIANGLE is: " << GetLength3() << endl;
}