//*******************************************************
//* PROGRAM CREATED BY:   CLAUDIO OSORIO                *
//* CONTACT INFORMATION:  cbo20h@my.fsu.edu             *
//* CREDITS: FUNCTIONS ARE PARTIALLY BASED ON LECTURES  *
//     & EXAMPLES FACILITATED DR. GAITROS' LECTURES     *
//*******************************************************





#include <iostream>
#include "shape.h"
#include "square.h"
#include "triangle.h"
#include "circle.h"
#include "rectangle.h"
int main() {
//**************************************
//*               SQUARE               *
//*      Declares class object         *
//*      Initializes class object      *
//**************************************
    Square mySquare;
    mySquare.SetLength(5);
    cout << "\n=*=*=*=*=* SQUARE - Default Constructor=*=*=*=*=*"
            "\n mySquare.SetLength(5)"
            "\n mySquare.PrintData():" << endl;
    mySquare.PrintData();

//  ***********************************
//  *          CALCULATIONS           *
//  ***********************************
    mySquare.CalculateArea();
    mySquare.CalculatePerimeter();

    cout << "\n mySquare.GetArea()    is: " << mySquare.GetArea() <<
            "\n mySquare.GetPerimeter()  is: " << mySquare.GetPerimeter() << endl;

    Square aSquare(5);
    cout << "\n=*=*=*=* SQUARE - Overloaded Constructor=*=*=*=*"
            "\n aSquare(5)"
            "\n aSquare.PrintData(): " << endl;
    aSquare.PrintData();
//  ***********************************
//  *          CALCULATIONS           *
//  ***********************************
    aSquare.CalculateArea();
    aSquare.CalculatePerimeter();

    cout << "\n aSquare.GetArea()      is: " << aSquare.GetArea() <<
            "\n aSquare.GetPerimeter() is: " << aSquare.GetPerimeter() << endl;


//**************************************
//*            RECTANGLE               *
//*      Declares class object         *
//**************************************
    Rectangle myRectangle;
    myRectangle.SetLength1(3);
    myRectangle.SetLength2(5);

    cout << "\n=*=*=*=*=* RECTANGLE - Default Constructor=*=*=*=*=*"
            "\n myRectangle.SetLength1 = 3"
            "\n myRectangle.SetLength2 = 5"
            "\n myRectangle.PrintData():" << endl;
    myRectangle.PrintData();

//  ***********************************
//  *          CALCULATIONS           *
//  ***********************************
    myRectangle.CalculateArea();
    myRectangle.CalculatePerimeter();

    cout << "\n myRectangle.GetArea()       is: " << myRectangle.GetArea() <<
            "\n myRectangle.GetPerimeter()  is: " << myRectangle.GetPerimeter() << endl;

//**************************************
//*            RECTANGLE               *
//*   Declares & Initializes object    *
//**************************************
    Rectangle aRectangle(5,10);
    cout << "\n=*=*=*=* RECTANGLE - Overloaded Constructor =*=*=*=*"
            "\n aRectangle(5,10)"
            "\n aRectangle.PrintData():" << endl;
    aRectangle.PrintData();

//  ***********************************
//  *          CALCULATIONS           *
//  ***********************************
    aRectangle.CalculateArea();
    aRectangle.CalculatePerimeter();

    cout << "\n aRectangle.GetArea()      is: " << aRectangle.GetArea() <<
            "\n aRectangle.GetPerimeter() is: " << aRectangle.GetPerimeter() << endl;


//**************************************
//*             TRIANGLE               *
//*      Declares class object         *
//*      Initializes class object      *
//**************************************
    Triangle myTriangle;
    myTriangle.SetLength1(3);
    myTriangle.SetLength2(5);
    myTriangle.SetLength3(7);

    cout << "\n=*=*=*=*=* TRIANGLE - Default Constructor =*=*=*=*=*"
            "\n myTriangle.SetLength1 = 3"
            "\n myTriangle.SetLength2 = 5"
            "\n myTriangle.SetLength3 = 7"
            "\n myTriangle.PrintData(): " << endl;
    myTriangle.PrintData();

//  ***********************************
//  *          CALCULATIONS           *
//  ***********************************
    myTriangle.CalculateArea();
    myTriangle.CalculatePerimeter();

    cout << "\n myTriangle.GetArea()      is: " << myTriangle.GetArea() <<
            "\n myTriangle.GetPerimeter() is: " << myTriangle.GetPerimeter() << endl;

//**************************************
//*             TRIANGLE               *
//*      Declares class object         *
//*      Initializes class object      *
//**************************************
    Triangle aTriangle(5,10,14);
    cout << "\n=*=*=*=* TRIANGLE - Overloaded Constructor =*=*=*=*"
            "\n aTriangle(5,10,14)"
            "\n aTriangle.PrintData(): " << endl;
    aTriangle.PrintData();

//  ***********************************
//  *          CALCULATIONS           *
//  ***********************************
    aTriangle.CalculateArea();
    aTriangle.CalculatePerimeter();

    cout << "\n aTriangle.GetArea()       is: " << aTriangle.GetArea() <<
            "\n aTriangle.GetPerimeter()  is: " << aTriangle.GetPerimeter() << endl;

//**************************************
//*              CIRCLE                *
//*      Declares class object         *
//*      Initializes class object      *
//**************************************
    Circle myCircle;
    myCircle.SetRadius(3);

    cout << "\n=*=*=*=*=* CIRCLE - Default Constructor =*=*=*=*=*"
            "\n myCircle.SetRadius = 3"
            "\n myCircle.PrintData(): " << endl;
    myCircle.PrintData();

//  ***********************************
//  *          CALCULATIONS           *
//  ***********************************
    myCircle.CalculateArea();
    myCircle.CalculatePerimeter();

    cout << "\n myCircle.GetArea()      is: " << myCircle.GetArea() <<
            "\n myCircle.GetPerimeter() is: " << myCircle.GetPerimeter() << endl;

    Circle aCircle(5);
    cout << "\n=*=*=*=* CIRCLE - Overloaded Constructor =*=*=*=*"
            "\n aCircle(5)"
            "\n aCircle.PrintData(): " << endl;
    aCircle.PrintData();

//  ***********************************
//  *          CALCULATIONS           *
//  ***********************************
    aCircle.CalculateArea();
    aCircle.CalculatePerimeter();

    cout << "\n aCircle.GetArea()      is: " << aCircle.GetArea() <<
            "\n aCircle.GetPerimeter() is: " << aCircle.GetPerimeter() << endl;
    

//**************************************
//*             TRIANGLE               *
//*      DEMO OF INPUT LESS THAN 1     *
//**************************************
Triangle wrongTriangle(-5,-5,-5);
cout << "\n=*=*=*=* TRIANGLE - Overloaded with values < 1  (defaults to 1) =*=*=*=*"
        "\n wrongTriangle(-5,-4,-50)"
        "\n wrongTriangle.PrintData(): " << endl;
wrongTriangle.PrintData();

//  ***********************************
//  *          CALCULATIONS           *
//  ***********************************
wrongTriangle.CalculateArea();
wrongTriangle.CalculatePerimeter();

cout << "\n wrongTriangle.GetArea()       is: " << wrongTriangle.GetArea() <<
        "\n wrongTriangle.GetPerimeter()  is: " << wrongTriangle.GetPerimeter() << endl;

    return 0;
}
