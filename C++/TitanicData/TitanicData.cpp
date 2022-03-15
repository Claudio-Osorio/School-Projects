/*Name: Claudio Osorio
 *Date: 11/12/2020
 *Section: Module 10
 *Assignment: Titanic Data Program
 *Due Date: 11/08/2020 11:59PM
 *About this project: This program will:
     * -Display a count of people who lived or died in numbers or percentages
     * -Display the count of people that lived or died by class.
 *Assumptions: The user will follow the instructions and will not expect additional
 *functionality besides the required and previously mentioned.
     *
 *I can assure you all work below was performed by Claudio Osorio
*/

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
//Function Prototypes
void showMenu();
char validate(char);
void ReadFromFile      (vector <int> &,vector <string> & ,vector <bool> & );
void LivedOrDiedByTotal(string Classes[], int NumDiedCount[], int NumLivedCount[],vector <string> PassengerClass,vector <bool> Survived);
void LivedOrDiedByClass(string Classes[], int NumDiedCount[], int NumLivedCount[],vector <string> PassengerClass,vector <bool> Survived);
void LivedOrDied(string [], int [], int [],vector <string>  ,vector <bool>  );

int main() {
    char option;
    //Vectors store all the data from text files which will be later used by functions
    vector <int> Age;
    vector <string> PassengerClass;
    vector <bool> Survived;
    string Classes[7] = {"1stClass","2ndClass","3rdClass","AlaCarte","Deck","Engine","Victualling"};
    int NumLivedCount[7]= {0};
    int NumDiedCount[7]= {0};

    //Reading necessary info from file. Program will exit if it fails.
    ReadFromFile(Age,PassengerClass,Survived);

    //Welcomes the user and stores the choice.
    cout << "\nWelcome to Titanic Data: Created by Claudio Osorio\n\n";
    showMenu();
    cin >> option;
    validate(option);

    switch(toupper(option))
    {
        case 'A':
            //Display count of people who lived and died
           LivedOrDiedByTotal(Classes,NumDiedCount, NumLivedCount,PassengerClass,Survived);
            break;
        case 'B':
            //Display count of people who lived by Passenger Class
           LivedOrDiedByClass(Classes,NumDiedCount, NumLivedCount,PassengerClass,Survived);
            break;
        default:
            cout << "Invalid option entered. This program will end now";
    }

    cout << "This program has finished without errors" << endl;
    return 0;
}

//prints menu to the screen
void showMenu()
{
    cout << "Options\n"
            "A) Display count of people who lived and died...\n"
            "B) Display count of people who lived by Passenger Class...\n"
            "Please select option (A-B)...";

}

//validates that the option entered is either A,a,B,b
char validate(char option)
{
    while (toupper(option) != 'A' && toupper(option) != 'B')
    {
        cout << "Invalid option entered. Please try again\n"
                "Select option (A-B)...";
        cin >> option;
    }

    return option;
}

//This function reads data from the text file and will store all the info in the corresponding vectors
//Age, Class, and survival status are saved independently and linked by the subscript of the vectors
void ReadFromFile(vector <int> & Age,vector <string> & PassengerClass,vector <bool> & Survived)
{
    string ageNumber;
    string stringClass;
    string boolStatus;
    string itsTrue = "TRUE";

    ifstream inputFile;
    string filename;
    filename = "TitanicData.txt";

    //Open the file
    inputFile.open(filename);
    //if the file successfully opened, process it.
    if(inputFile)
    {
        while(inputFile >> ageNumber >> stringClass >> boolStatus)
        {

            Age.push_back(stoi(ageNumber));
            PassengerClass.push_back(stringClass);

            //Converting Survived status from string to boolean
             if((boolStatus) == itsTrue)
            {
                Survived.push_back(1);
            } else
            {
                Survived.push_back(0);
            }

        }

        inputFile.close();

    }else{//if File can't open display error and exit program
        cout << "ERROR: Can't open to read \"" << filename << "\".\n"
                "Make sure the file exists.This program will end now";
        exit(EXIT_FAILURE);
    }

}


//Display count of people who lived and died...
void LivedOrDiedByTotal(string Classes[], int NumDiedCount[], int NumLivedCount[],vector <string> PassengerClass,vector <bool> Survived)
{
    float pLived,pDied;

    //Updating extracted data
    LivedOrDied(Classes,NumDiedCount,NumLivedCount,PassengerClass,Survived);

    int classCount = 0, livedCount = 0, diedCount = 0;
    //Do a for loop for all passenger classes as subscript  and sum all the elements on the lived array. REPEAT for DIED using died array

    //Summing all the classes to obtain totals
    for(;classCount < 7; classCount++)
    {
        livedCount += NumLivedCount[classCount];
        diedCount  += NumDiedCount[classCount];
    }

    //Calculating percentages
    pLived = ((float)(livedCount))/((float)(livedCount+diedCount));
    pDied = ((float)(diedCount))/((float)(livedCount+diedCount));

    //Printing final results to the screen
    cout << "\nNumber of people who lived: " << livedCount << endl;
    cout << "Number of people who died: "  << diedCount  << endl;
    cout << "\nPercentage of people who lived: "  << setprecision(4)<<pLived  << endl;
    cout << "Percentage of people who died: "   << setprecision(4)<<pDied   << endl;

}

//Display count of people who lived by Passenger Class...
void LivedOrDiedByClass(string Classes[], int NumDiedCount[], int NumLivedCount[],vector <string> PassengerClass,vector <bool> Survived)
{
    //Updating extracted data
    LivedOrDied(Classes,NumDiedCount,NumLivedCount,PassengerClass,Survived);

    //Printing deaths by classes
    cout << "\nNumber of people who lived By Class\n" << setw(28)<<"Class\tNumber\n";
    for (int i = 0; i < 7; i++)
    {
        cout << setw(20)<< Classes[i] << setw(10) << NumLivedCount[i] << endl;
    }

}

//Function matches every class and passenger from the vector and compares them. If the passenger is from
//certain class then its data will be assigned to the class-matching array
void LivedOrDied(string Classes[],int NumDiedCount[], int NumLivedCount[],vector <string>  PassengerClass,vector <bool>  Survived )
{
    int currentClass;
    int currentPassenger = 0;

    while (currentPassenger < PassengerClass.size())
    {
        for (currentClass = 0; currentClass < 7; currentClass++)
        {
            if (PassengerClass[currentPassenger] == Classes[currentClass] )
            {
                    if (Survived[currentPassenger] == 1)
                    {
                        NumLivedCount[currentClass] += 1;
                    }
                    if (Survived[currentPassenger] == 0)
                    {
                        NumDiedCount[currentClass] += 1;
                    }
            }
        }

        currentPassenger++;
    }

}
