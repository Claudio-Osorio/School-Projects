#include <iostream>
#include <string>
#include "shape.h"
#ifndef ASSIGNMENT__5_SHAPES_INHERITANCE_TRIANGLE_H
#define ASSIGNMENT__5_SHAPES_INHERITANCE_TRIANGLE_H
class Triangle: public Shape
{
public:
//*******************************
//*         CONSTRUCTORS        *
//*******************************
    Triangle();
    Triangle(const double newLength1,const double newLength2, const double newLength3);

//*******************************
//*    ACCESSORS AND MUTATORS   *
//*******************************
    void SetLength1(const double newLength);
    void SetLength2(const double newLength);
    void SetLength3(const double newLength);
    double GetLength1();
    double GetLength2();
    double GetLength3();

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
    double length3;


};
#endif //ASSIGNMENT__5_SHAPES_INHERITANCE_TRIANGLE_H
