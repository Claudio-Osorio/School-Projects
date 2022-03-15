#include <iostream>
#include "shape.h"
//**********************************
//*    ACCESSORS AND MUTATORS      *
//**********************************
void Shape::SetPerimeter(double const newPerimeter) { perimeter = newPerimeter; }
void Shape::SetArea(double const newArea)           { area = newArea;            }
double Shape::GetArea()                             { return area;         }
double Shape::GetPerimeter()                        { return perimeter;    }

//*******************************
//*      VIRTUAL FUNCTION       *
//*******************************
void Shape::PrintData()
{
    cout << "The area is:      " << GetArea() << endl;
    cout << "The perimeter is: " << GetPerimeter() << endl;
}
