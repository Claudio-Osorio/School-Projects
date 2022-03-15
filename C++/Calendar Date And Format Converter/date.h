// ******************************************************************************//
// * Name: Assignment #2 Date Class *                                            //
// * Class: COP3330 *                                                            //
// * Description: Interact with the user's input and show, calculate:            //
// Gregorian, Two Digit, Long and Julian formatted dates as requested by the     //
// directions in the assigment.*                                                 //
// * All the code below was created by Claudio Osorio*                           //
// * Date: January 17, 2021 *                                                    //
// ******************************************************************************//


#ifndef ASSIGNMENT__2_DATE_CLASS_2_0_DATE_H
#define ASSIGNMENT__2_DATE_CLASS_2_0_DATE_H


class Date
{
private:
    char format;
    int month;
    int day;
    int year;

public:
    //Constants
    const char DEFAULT_FORMAT = 'D';
    const int DEFAULT_MONTH = 1;
    const int DEFAULT_DAY = 1;
    const int DEFAULT_YEAR = 2000;

    //Constructor
    Date();

    //Mutators
    bool SetFormat(char newFormat);
    void SetMonth(int newMonth);
    void SetDay(int newDay);
    void SetYear(int newYear);

    void Input();
    bool Set(int newMonth, int newDay, int newYear);
    void Show ();
    bool LeapYearValidation(int newYear);
    void ShowDefaultFormat();
    void ShowLongFormat();
    void ShowTwoDigitFormat();
    void ShowJulianFormat();
    int Compare( Date & d);
    void Increment(int numDays = 1);

    //Accessors
    char GetFormat();
    int GetMonth();
    int GetDay();
    int GetYear();

};

#endif //ASSIGNMENT__2_DATE_CLASS_2_0_DATE_H
