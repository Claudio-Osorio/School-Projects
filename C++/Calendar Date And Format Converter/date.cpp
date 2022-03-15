// ******************************************************************************//
// * Name: Assignment #2 Date Class *                                            //
// * Class: COP3330 *                                                            //
// * Description: Interact with the user's input and show, calculate:            //
// Gregorian, Two Digit, Long and Julian formatted dates as requested by the     //
// directions in the assignment.*                                                 //
// * All the code below was created by Claudio Osorio*                           //
// * Date: January 17, 2021 *                                                    //
// ******************************************************************************//


#include <iostream>
#include "date.h"

using namespace std;

//Constructor
Date::Date()
{
    SetFormat(DEFAULT_FORMAT);
    SetMonth(DEFAULT_MONTH);
    SetDay(DEFAULT_DAY);
    SetYear(DEFAULT_YEAR);


}
//Sets the format
bool Date::SetFormat(char newFormat)
{
    //If given format is not good then show it's  not good.
    if (newFormat != 'D' && newFormat != 'T' && newFormat != 'L' && newFormat != 'J')
    {
        return false;
    }else
    {
        format = newFormat;
        return true;
    }
}

//Sets the month
void Date::SetMonth(int newMonth)
{
    month = newMonth;
}

//Sets the day
void Date::SetDay(int newDay)
{
    day = newDay;
}

//Sets the year
void Date::SetYear(int newYear)
{
    year = newYear;
}


//Gets the date format stored by the user
char Date::GetFormat()
{
    return format;
}

//Gets the month stored by the user
int Date::GetMonth()
{
    return month;
}

//Gets the day stored by the user
int Date::GetDay()
{
    return day;
}

//Gets the year stored by the user
int Date::GetYear()
{
    return year;
}

//Compares the first date given with the second date passed
int Date::Compare( Date & d)
{

    if ( year < d.GetYear())
    {
        return -1;
    }
    else if (year == d.GetYear())
    {// year  matches let's test for month
        if (month < d.GetMonth())
        {
            return -1;
        }else if (day == d.GetMonth())
        {//year and month matches let's test for day
            if (day < d.GetDay())
            {
                return -1;
            }else if (day == d.GetDay())
            {
                return 0;
            }else // year and month match but day1 < day2.
            {
                return 1;
            }

        }

    }
    return 1; //By default I assume date1 is newer than date 2 until code proves the opposite.
}

// Increments days to the default date.
void Date::Increment(int numDays)
{
    int leap = 0;
    int sumDays;
    int totalDays; //stores the final result for the julian calendar
    //if the year is a leap year it will account for the extra day
    if (LeapYearValidation(year))
        leap = 1;

    switch (month) {
        case 12: //Dec
            sumDays = 31 + 28 + leap + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
            break;
        case 11:  //Nov
            sumDays = 31 + 28 + leap + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
            break;
        case 10: //Oct
            sumDays = 31 + 28 + leap + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
            break;
        case 9://Sept
            sumDays = 31 + 28 + leap + 31 + 30 + 31 + 30 + 31 + 31 + day;
            break;
        case 8: //Aug
            sumDays = 31 + 28 + leap + 31 + 30 + 31 + 30 + 31 + day;
            break;
        case 7: //July
            sumDays = 31 + 28 + leap + 31 + 30 + 31 + 30 + day;
            break;
        case 6://June
            sumDays = 31 + 28 + leap + 31 + 30 + 31 + day;
            break;
        case 5://May
            sumDays = 31 + 28 + leap + 31 + 30 + day;
            break;
        case 4: //Apr
            sumDays = 31 + 28 + leap + 31 + day;
            break;
        case 3: //Mar
            sumDays = 31 + 28 + leap + day;
            break;
        case 2: //Feb
            sumDays = day + 31;
            break;
        case 1: //Jan
            sumDays = day;
            break;
    }

    totalDays = numDays + sumDays; //Days to increment + current days

    //Every 365 + leap days a year is added and the count is reduced
    //Makes sure that as years go by the leap years are taken into account
    while (totalDays > (365 +leap))
    {
        year += 1;
        totalDays -= (365 + leap);
        if (LeapYearValidation(year))
        {
            leap = 1;
        }
        else
        {
            leap = 0;
        }

    }

    if (LeapYearValidation(year))
        leap = 1;

    //Estimating landing month and day
    if (totalDays >= 1 && totalDays < 32)
    {
        month = 1;
        day = totalDays;
    }

    if (totalDays >=32 && totalDays < (60 + leap))
    {
        month = 2;
        day = totalDays - 31;
    }

    if (totalDays >= (60+leap) && totalDays < (91 + leap))
    {
        month = 3;
        day = totalDays - (31+28+leap);
    }
    if (totalDays >= (91+leap) && totalDays < (121 + leap))
    {
        month = 4;
        day = totalDays - (31+28+leap+31);
    }

    if (totalDays >= (121+leap) && totalDays < (152 + leap))
    {
        month = 5;
        day = totalDays - (31+28+leap+31+30);
    }

    if (totalDays >= (152+leap) && totalDays < (182 + leap))
    {
        month = 6;
        day = totalDays - (31+28+leap+31+30+31);
    }
    if (totalDays >=(182+leap) && totalDays < (213 + leap))
    {
        month = 7;
        day = totalDays - (31+28+leap+31+30+31+30);
    }
    if (totalDays >= (213+leap) && totalDays < (244 + leap))
    {
        month = 8;
        day = totalDays - (31+28+leap+31+30+31+30+31);
    }
    if (totalDays >= (244+leap) && totalDays < (274 + leap))
    {
        month = 9;
        day = totalDays - (31+28+leap+31+30+31+30+31+31);
    }
    if (totalDays >= (274+leap) && totalDays < (305 + leap))
    {
        month = 10;
        day = totalDays - (31+28+leap+31+30+31+30+31+31+30);
    }
    if (totalDays >= (305+leap) && totalDays < (335 + leap))
    {
        month = 11;
        day = totalDays - (31+28+leap+31+30+31+30+31+31+30+31);
    }
    if (totalDays >=(335+leap) && totalDays < (366 + leap))
    {
        month = 12;
        day = totalDays - (31+28+leap+31+30+31+30+31+31+30+31+31);
    }
}

//Validates that the date given in default format is correct
bool Date::Set(int newMonth, int newDay, int newYear)
{
    bool goodDate;

       //verifies all the parts of the date are within the correct parameters
    if (newMonth < 1 || newMonth > 12)
    {
        goodDate = false;
    } else if (newDay < 1 || newDay > 31)
    {
        goodDate = false;
    } else if (newMonth == 2 && newDay > 30)
    {
        goodDate = false;
    }
    else if (newMonth == 4 && newDay > 30)
    {
        goodDate = false;
    }
    else if (newMonth == 6 && newDay > 30)
    {
        goodDate = false;
    }
    else if (newMonth == 9 && newDay > 30)
    {
        goodDate = false;
    }
    else if (newMonth == 11 && newDay > 30)
    {
        goodDate = false;
    }
        //If the year is not leap and february has more than 28 days
    else if ( !(LeapYearValidation(newYear)) && newMonth == 2 && newDay > 28 )
    {
        goodDate = false;
    }else if ( newMonth == 2 && newDay > 29)
    { goodDate = false;
    }
    else if(newYear < 1582)
    {
        goodDate = false;
    }else //If none if the exceptions is true then the date is GOOD.
    {
        goodDate = true;
    }
    //Judges if the date is bad then get a new one. Or keep it if it's good

    if(goodDate)
    {
    //If date is good then store given values
        SetMonth(newMonth);
        SetDay(newDay);
        SetYear(newYear);

    }

    //goodDate = 1 for success; = 0 for failure
    cout << "Set(month,day,year) Returned: "<< goodDate <<endl;
    return goodDate;

}

//Verifies if the year is a leap year or not. Can take any year so that I can
//test a year before it replaces the one stored in private.
bool Date::LeapYearValidation(int newYear)
{
    bool leap = false;
    if (newYear % 4 == 0)
    {
        leap = true;
    }
    if (newYear % 100 == 0)
    {
        leap = false;
    }
    if (newYear % 100 ==0 && newYear % 400 == 0)
    {
        leap = true;
    }
    return leap;
}

void Date::Input()
{
    int newMonth, newDay, newYear;
    char separator = '/';
    cout << "Please enter a date (mm/dd/yyyy): ";
    cin >> newMonth >> separator >> newDay >> separator >> newYear;

    while (Set(newMonth, newDay, newYear) == false)// Validates that the Input is correct
    {
        cout << "Invalid Date. Try again. Enter a date in the format mm/dd/yyyy: ";
        cin >> newMonth >> separator >> newDay >> separator >> newYear;
    }

}

//Displays date formats
void Date::Show ()
{
    char format;
    format = GetFormat();
    switch (format)
    {
        case 'D': //Default Format
            cout << "\nDefault Format: ";
            ShowDefaultFormat();
            break;
        case 'T': // Two Digit Format
            cout << "\nTwo Digit Format: ";
            ShowTwoDigitFormat();
            break;
        case 'L': //Long Format
            cout << "\nLong Format: ";
            ShowLongFormat();
            break;
        case 'J': //Julian Format
            cout << "\nJulian Format: ";
            ShowJulianFormat();
            break;
        default:  //Default Format
            cout << "\nDefault Format: ";
            ShowDefaultFormat();
            break;
    }
}
//displays the Default format
void Date::ShowDefaultFormat()
{
    cout << month << "/" << day << "/" << year << endl;
}
//displays the two digit format
void Date::ShowTwoDigitFormat()
{
    int month = GetMonth();
    int day = GetDay();
    int year = GetYear();

    //Get the last 2 values of year. and print the result
    if ( year % 100 > 0 )
    {
        year = year % 100;
        cout << month << "/" << day << "/" << year << endl;
    }else
    {
        cout << month << "/" << day << "/" << "00" << endl;
    }
}
//displays the long format
void Date::ShowLongFormat()
{
    int month = GetMonth();
    int day = GetDay();
    int year =GetYear();
    string textMonth;

    if (month == 1)
        textMonth = "Jan";
    if (month == 2)
        textMonth = "Feb";
    if (month == 3)
        textMonth = "Mar";
    if (month == 4)
        textMonth = "Apr";
    if (month == 5)
        textMonth = "May";
    if (month == 6)
        textMonth = "June";
    if (month == 7)
        textMonth = "July";
    if (month == 8)
        textMonth = "Aug";
    if (month == 9)
        textMonth = "Sept";
    if (month == 10)
        textMonth = "Nov";
    if (month == 12)
        textMonth = "Dec";

    cout << textMonth << " " << day << ", " << year << endl;
}

//displays the Julian format
void Date::ShowJulianFormat()
{
    GetMonth();
    GetDay();
    GetYear();
    int leap = 0;
    int sumDays;
    //Accounting for Leap Year
    if (LeapYearValidation(GetYear()))
    {
        leap = 1;
    }

    //Adds the days according to the month for the julian calendar
    //also takes into consideration the leap year
    switch (GetMonth())
    {
        case 12: //Dec
            sumDays = 31+28+leap+31+30+31+30+31+31+30+31+30+GetDay();
            break;
        case 11:  //Nov
            sumDays = 31+28+leap+31+30+31+30+31+31+30+31+GetDay();
            break;
        case 10: //Oct
            sumDays = 31+28+leap+31+30+31+30+31+31+30+GetDay();
            break;
        case 9://Sept
            sumDays = 31+28+leap+31+30+31+30+31+31+GetDay();
            break;
        case 8: //Aug
            sumDays = 31+28+leap+31+30+31+30+31+GetDay();
            break;
        case 7: //July
            sumDays = 31+28+leap+31+30+31+30+GetDay();
            break;
        case 6://June
            sumDays = 31+28+leap+31+30+31+GetDay();
            break;
        case 5://May
            sumDays =  31+28+leap+31+30+ GetDay();
            break;
        case 4: //Apr
            sumDays = 31+28+leap+31+GetDay();
            break;
        case 3: //Mar
            sumDays = 31 + 28 + leap + GetDay();
            break;
        case 2: //Feb
            sumDays = GetDay() + 31;
            break;
        case 1: //Jan
            sumDays = GetDay();
            break;
    }

    cout << sumDays << ", " << GetYear() << endl;
}
