#include <iostream>
#include <string>
using namespace std;

#ifndef ASSIGNMENT__5_SHAPES_INHERITANCE_SHAPE_H
#define ASSIGNMENT__5_SHAPES_INHERITANCE_SHAPE_H
class Shape
{

public:
//*******************************
//*    ACCESSORS AND MUTATORS   *
//*******************************
    void SetPerimeter(double const newPerimeter);
    void SetArea(double const newArea);
    double GetPerimeter();
    double GetArea();

//*******************************
//*      VIRTUAL FUNCTION       *
//*******************************
    virtual void PrintData()=0;

private:
    double perimeter;
    double area;

};
#endif //ASSIGNMENT__5_SHAPES_INHERITANCE_SHAPE_H
