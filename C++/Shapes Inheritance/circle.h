#include <iostream>
#include <string>
#include "shape.h"
#ifndef ASSIGNMENT__5_SHAPES_INHERITANCE_CIRCLE_H
#define ASSIGNMENT__5_SHAPES_INHERITANCE_CIRCLE_H

const double PI = 3.14159265359;
class Circle : public Shape
{
public:
//*******************************
//*         CONSTRUCTORS        *
//*******************************
    Circle();
    Circle(const double newRadius);

//*******************************
//*    ACCESSORS AND MUTATORS   *
//*******************************
    void SetRadius(const double newRadius);
    double GetRadius();

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
double radius;

};
#endif //ASSIGNMENT__5_SHAPES_INHERITANCE_CIRCLE_H
