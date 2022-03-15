#include <iostream>
#include <string>
#include "shape.h"
#ifndef ASSIGNMENT__5_SHAPES_INHERITANCE_RECTANGLE_H
#define ASSIGNMENT__5_SHAPES_INHERITANCE_RECTANGLE_H
class Rectangle:public Shape
{
public:
//*******************************
//*         CONSTRUCTORS        *
//*******************************
    Rectangle();
    Rectangle(const double newLength1, const double newLength2);

//*******************************
//*    ACCESSORS AND MUTATORS   *
//*******************************
    void SetLength1(const double newLength);
    void SetLength2(const double newLength);
    double GetLength1();
    double GetLength2();

//*******************************
//*         CALCULATIONS        *
//*******************************
    void CalculatePerimeter();
    void CalculateArea();

//*******************************
//*      VIRTUAL FUNCTION       *
//*******************************
    virtual void PrintData();

private:
    double length1;
    double length2;
};
#endif //ASSIGNMENT__5_SHAPES_INHERITANCE_RECTANGLE_H
