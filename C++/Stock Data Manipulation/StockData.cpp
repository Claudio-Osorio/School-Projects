/*Name: Claudio Osorio
 *Date: 11/18/2020
 *Section: Module 11
 *Assignment: StockData
 *Due Date: 11/22/2020 11:59PM
 *About this project: This program will:
     * Calculate the highest price out the 4 available prices for each stock
     * Display the non calculated and calculated prices for each stock
     * Program will end at user's request
 *Assumptions: The user will follow the instructions and will not expect additional
 *functionality besides the required and previously mentioned.
 *
 *All work below was performed by Claudio Osorio
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Structure for Stock data
struct StockData
{
    string StockName;   //Name of Stock
    double price[4];    //Price
    double highestPrice;//Highest Price
};

//Prototypes
void showMenu();
void getValidChoice(char & choice);
void computeHighPrice(StockData stocks []);
void displayData (StockData stocks[]);

int main() {

    char choice;
//These are all the current prices for the stocks
    StockData stocks[3];

    stocks[0].StockName = "GE";
    stocks[0].price[0] = 47.88;
    stocks[0].price[1] = 56.99;
    stocks[0].price[2] = 98.66;
    stocks[0].price[3] = 45.77;
    stocks[0].highestPrice = 0.00;

    stocks[1].StockName = "ATT";
    stocks[1].price[0] = 66.99;
    stocks[1].price[1] = 45.33;
    stocks[1].price[2] = 32.99;
    stocks[1].price[3] = 34.99;
    stocks[1].highestPrice = 0.00;

    stocks[2].StockName = "MPS";
    stocks[2].price[0] = 88.99;
    stocks[2].price[1] = 99.78;
    stocks[2].price[2] = 76.99;
    stocks[2].price[3] = 66.99;
    stocks[2].highestPrice = 0.00;

    cout << "Welcome to Claudio's Stock Data Program" << endl;

    //Loops the whole program until the user enters c or C to exit.
    do {
    showMenu();
    getValidChoice(choice);

    //Provides the options for the menu
    switch (choice)
    {
        case 'a':
            computeHighPrice(stocks);
            break;
        case 'b':
            displayData (stocks);
            break;
        case 'c':
             //Program exits
            break;
         default:
            cout << "You failed to enter a,b, or c. Program will end" << endl;
            break;
    }

    }while  ('c' != tolower(choice));

    return 0;
}

//Prints the menu to the screen
void showMenu()
{
    cout << "    Menu Options:\n"
            "    A) Compute Highest Price\n"
            "    B) Display Data\n"
            "    C) Quit"<<endl;
}

//Obtains a valid character that can be used for the menu
void getValidChoice(char & choice)
{
    cout << "Please enter a,b, or c: " << endl;
    cin >> choice;

        while ('a' != tolower(choice) && 'b' != tolower(choice) && 'c' != tolower(choice) )
        {
            cout << "Your input is incorrect. Please try again. Enter a,b, or c" << endl;
            cin >> choice;
        }
     //Making sure the choice is lowercase
     choice = tolower(choice);
}

//Calculates the stock's highest price from the 4 prices (or weeks)
void computeHighPrice( StockData stocks[] )
{
    int stock, week;
    for (stock = 0; stock < 3; stock++ )
    {
        for (week = 0; week < 4; week++)
        {
            if ( stocks[stock].price[week] > stocks[stock].highestPrice)
                stocks[stock].highestPrice = stocks[stock].price[week];
        }
    }

}

//Prints the 4 prices (or weeks) of all the stocks
void displayData (StockData stocks[])
{
    int stock, week;
    for(stock = 0; stock <3; stock++)
    {
        cout << "Stock Name: " << stocks[stock].StockName << endl;
        for (week = 0; week < 4; week++)
        {
            cout << "Price:" << setw(20) << setprecision(2) << fixed << stocks[stock].price[week] << endl;
        }
        cout << "Highest price:" << setw(12)<< setprecision(2) << fixed << stocks[stock].highestPrice << "\n" << endl;
    }

}
