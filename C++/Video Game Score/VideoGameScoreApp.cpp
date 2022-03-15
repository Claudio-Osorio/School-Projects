/*Name: Claudio Osorio
 *Date: 11/26/2020
 *Section: Module 12
 *Assignment: Video Game Scores Program
 *Due Date: 11/29/2020 11:59PM
 *About this project: This program will:
     * Call 3 instances of a function that displays -Name - Score - if VideoGame Score is over 10000
 *Assumptions: The user will follow the instructions and will not expect additional
 *functionality besides the required and previously mentioned.
 *
 *All work below was performed by Claudio Osorio
*/


#include <iostream>
#include "VideoGameScore.h"  //including the class file

using namespace std;

//Prototype
void DisplayGamer(VideoGameScore Gamer);

int main()
{
    cout << "Welcome to the VideoGameScore App by Claudio Osorio\n"<<endl;

    //Declaring the first 3 Gamers that will have some unique data
    VideoGameScore Gamer1;
    VideoGameScore Gamer2;
    VideoGameScore Gamer3;

    //Entering the data for every gamer
    //Gamer1
    Gamer1.setName("Kristen Lee");
    Gamer1.setScore(4500);
    Gamer1.setAboveTenThousand();
    //Gamer2
    Gamer2.setName("Joe Smith");
    Gamer2.setScore(50000);
    Gamer2.setAboveTenThousand();
    //Gamer3
    Gamer3.setName("Tom Hanks");
    Gamer3.setScore(75000);
    Gamer3.setAboveTenThousand();

    //Call to display every Gamer
    DisplayGamer(Gamer1);
    DisplayGamer(Gamer2);
    DisplayGamer(Gamer3);
}
//Display the gamer information to the screen
void DisplayGamer(VideoGameScore Gamer) {
    cout << "Name: " << Gamer.getName() << endl;
    cout << "Score: " << Gamer.getScore() << endl;

    //If the result of Above 10 000 calculation is 1 then it's true so print it. Otherwise say No.
    if (Gamer.AboveTenThousand() == 1)
        cout << "Score Above Ten Thousand?: " << "Yes" << endl;
    else
        cout << "Score Above Ten Thousand?: " << "No" << endl;

    cout << endl;
}