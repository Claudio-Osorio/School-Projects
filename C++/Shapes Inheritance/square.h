#include <iostream>
#include <string>
#include "shape.h"
#ifndef ASSIGNMENT__5_SHAPES_INHERITANCE_SQUARE_H
#define ASSIGNMENT__5_SHAPES_INHERITANCE_SQUARE_H

class Square:public Shape
{
public:
//*******************************
//*         CONSTRUCTORS        *
//*******************************
    Square();
    Square(const double newLength);

//*******************************
//*    ACCESSORS AND MUTATORS   *
//*******************************
    void SetLength(const double newLength);
    double GetLength();

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
    double length;
};

#endif //ASSIGNMENT__5_SHAPES_INHERITANCE_SQUARE_H
