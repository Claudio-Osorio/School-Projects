/*Name: Claudio Osorio
 *Date: 10/22/2020
 *Section: Module 7
 *Assignment: Bowling Tournament Program Part 2
 *Due Date: 10/28/2020 11:59PM
 *About this project: This program comes with 3 games and scores pre-saved. Each game has its own score.
     * This program will be able to:
     * -Display all the games and their scores
     * -Modify the score of any existing game
     * -Display the highest score and also from which game
     * -Display the average game score
     * -Display a sorted list of the scores
 *Assumptions: The user will follow the instructions and will not expect additional
     * functionality besides the required and expected.
 *All work below was performed by Claudio Osorio
*/
//Libraries
#include <iostream>
#include <iomanip>

//Prototypes
const int NUM_GAMES = 3;
void showMenu();
int validateMenu();
int getValidScore();
void displayScores(int[]);
void ChangeAScore(int[]);
void displayGameHighestScore(int[]);
int getValidGameNumber(int[],int );
void displayAverageScore(int []);
void displaySortedScores(int []);
void swap(int &, int &);
using namespace std;

int main()
{
    int scores[NUM_GAMES]={178,98,288};
    int optionChosen = 0;
    cout << "Welcome to the help with the bowling tournament program\nCreated by Claudio Osorio!" << endl;

    //Loops the whole program so it only ends when the user selects option 4
    while(optionChosen!=6)
    {
        showMenu();
        optionChosen = validateMenu();

        //Redirects user to the option he/she selected
        switch(optionChosen)
        {
            case 1:
                displayScores(scores);
                break;
            case 2:
                ChangeAScore(scores);
                break;
            case 3:
                displayGameHighestScore(scores);
                break;
            case 4:
                displayAverageScore(scores);
                break;
            case 5:
                displaySortedScores(scores);
                break;
            case 6:
                break;
            default:
                break;
        }
    }
    return 0;
}
//Displays the menu on the screen
void showMenu()
{
    cout << "\n1) Display the scores\n"
            "2) Change a score\n"
            "3) Display game with the highest score\n"
            "4) Display average game score\n"
            "5) Display a sorted list of the scores\n"
            "6) Quit"<<endl;
};

//Validates and returns a valid input for menu options
int validateMenu()
{
    int option = 0;
    while (option < 1 || option > 6)
    {
        cout << "Select an option (1..6)  ";
        cin >> option;
        cout <<endl;
    }
    return option;
};


//Validates and returns a game number from the range of possible games in existance
int getValidGameNumber(int scores[NUM_GAMES], int NUM_GAMES)
{
    int gameNumber;

    cout << "Please enter a game number" << endl;
    cin  >> gameNumber;

    while (gameNumber < 1 || gameNumber > NUM_GAMES)
    {
        cout << "Please enter a valid game number" << endl;
        cin  >> gameNumber;
    }
    return gameNumber;
};

//Validates and returns score between range 0 to 300
int getValidScore ()
{
    int validScore = -1;

    while (validScore < 0 || validScore >=301)
    {
        cout <<"Please enter a score" << endl;
        cin >> validScore;

    }

    return validScore;
};

//Displays scores to screen in an organized way
void displayScores(int scores[NUM_GAMES])
{
    cout << "Display Scores" << endl;
    //Displays the word game as many times as there are games
    for (int i = 0; i < NUM_GAMES;i++)
    {
        cout << setw(10)<<"Game "<< i+1;

    }
    cout <<endl;
    //Displays the scores for every game in existence
    for (int i = 0; i < NUM_GAMES;i++)
    {
        cout << setw(10)<< scores[i];

    }
    cout <<endl;
};


// This allows the user to enter in a valid score and a valid game
void ChangeAScore(int scores[NUM_GAMES])
{
    int scoreToChange;
    cout << "Change a score"<<endl;
    scoreToChange = getValidGameNumber(scores,NUM_GAMES);
    //-1 because the array starts at 0 and games start at 1
    scores[scoreToChange -1 ] = getValidScore();

};


// This displays the number of the game with the highest score
void displayGameHighestScore(int scores[NUM_GAMES])
{
    int highestScore,highestScoreGame;
    //Stores the game /array with the highest score/value
    for(int i = 0; i < NUM_GAMES;i++)
    {
        if (scores[i] >= scores[i+1])
        {
            highestScore = scores[i];
            highestScoreGame = i+1; //games start at 1. Array start at 0. Match game and array with i+1
        }

    }
    cout << "The Highest Score is "<<highestScore<< " from |Game "<<highestScoreGame << "|"<< endl;
};

//Computing the game score the average for all existing games
void displayAverageScore(int scores[NUM_GAMES])
{
    int averageScore = 0;

    for (int i = 0; i < NUM_GAMES;i++)
    {
        averageScore += scores[i];
    }
    averageScore = averageScore/NUM_GAMES;
    cout << "Average score is " << averageScore <<endl;

};

//Takes the scores array as a parameter,
// it creates a local copy of the scores array, sorts the new array in descending order
// and displays values in the new array
void displaySortedScores(int scores[NUM_GAMES])
{
    int maxElement;
    int index;
    int localScores[NUM_GAMES];
    //Creating local copy of the array

    for (int i = 0; i < NUM_GAMES; i++)
    {
        localScores[i] = scores[i];
    }

    //Bubble sort
    for (maxElement = NUM_GAMES - 1; maxElement > 0; maxElement--)
    {
        for (index = 0; index < maxElement; index++)
        {
            if (localScores[index] > localScores[index + 1])
            {
                swap(localScores[index], localScores[index + 1]);
            }
        }

    }
    //Printing the results to the screen
    cout << "Sorted List of Scores:" << endl;
    for ( int i = 0; i<NUM_GAMES;i++)
    {
        cout<<setw(10)<<localScores[i];

    }

    cout <<  endl;
};

//Swapping terms . Useful for bubblesort on Sorted list of scores function
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

