#include <iostream>
#include "shape.h"
#include "circle.h"

//**************************************
//*            CONSTRUCTORS            *
//**************************************
Circle::Circle()
{
    SetRadius(1.00);
}

//**************************************
//*       OVERLOADED CONSTRUCTOR       *
//**************************************
Circle::Circle(const double newRadius)
{
    if (newRadius < 1) SetRadius(1.00);
    else SetRadius(newRadius);
}

//**************************************
//*      ACCESSORS AND MUTATORS        *
//**************************************
void Circle::SetRadius(const double newRadius)
{
    radius = newRadius;
}
double Circle::GetRadius()        { return radius;}

//**************************************
//*            CALCULATIONS            *
//**************************************
void Circle::CalculatePerimeter() { SetPerimeter(PI * 2 * GetRadius()); }
void Circle::CalculateArea()      { SetArea(PI * GetRadius() * GetRadius()); }

//**************************************
//*         VIRTUAL FUNCTION           *
//**************************************
void Circle::PrintData()
{
    cout << "The radius is: " << GetRadius() << endl;
}

