// ********************************************************************
// *                    Name: Claudio Osorio                          *
// * Description:  Assignment#6 Word, Number, And Character Usage     *
// * Statistics. Practicing selecting and making use of appropriate   *
// * STL containers and algorithms to perform tasks. This program     *
// * collects the statistics of word, number, and character usage in  *
// * a file                                                           *
// *                                                                  *
// *                    Date: July 20, 2021                           *
// *                    Last Checked: July 22, 2021                   *
// *                                                                  *
// * Disclaimer: Some parts of this code were provided by Dr. Gaitros *
// * in his videos. I have also inspired my code and used small parts *
// * from examples provided  by the book "Data Structures Algorithm   *
// * Analysis in C++ by Mark A. Weiss" and the website cplusplus.com  *
// * I have also used some one-liners from tutorialspoint.com  and    *
// * a function to lowercase a string from Stefan Mai - StackOverflow *
// *                                                                  *
// * This code has been tested in linprog and compiled with no errors *
// * a copy of the output should have been provided in the comments of*
// * the submission of this assignment. Thanks                        *
// ********************************************************************

#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>
#include <algorithm>
#include <map>
#include <iterator>
#include <vector>

using namespace std;

void PrintTopTenWords     (map<string,  pair<int, int>> wordMap      );
void PrintTopTenCharacters(map<char,    pair<int, int>> characterMap );
void PrintTopTenNumbers   (map<string,  pair<int, int>> numberMap    );

void AddWord     (map<string, pair<int, int>> &wordMap,     int priority, string &singleWord);
void AddCharacter(map<char,   pair<int, int>> &characterMap,char   &singleCharacter);
void AddNumber   (map<string, pair<int, int>> &numberMap,   int priority, string &singleNumber);

int comparatorStr (const pair<string,  pair<int, int>>, const pair<string, pair<int, int>>);
int comparatorChar(const pair<char,    pair<int, int>>, const pair<char,  pair<int, int>>);
//******************************************************************************
//* Main function dictates the logic of the program to store and account       *
//* for all the numbers, characters and words existing in  the file passed in. *
//******************************************************************************
int main()
{
    clock_t start = clock(); //Start Time

    //Each map will contain  two things:
    //1st. A string to store the word, number or a character.
    //2nd. A pair of integers where (first is priority (index)) (second is quantity)
    //Example map <value, pair<priority,quantity>>
    map <string, pair<int, int> > wordMap;
    map <char  , pair<int, int> > characterMap;
    map <string, pair<int, int> > numberMap;

    cout << "Welcome to Claudio Osorio Assignment #6"
            "\n\"Word, Number, And Character Usage Statistics\"" << endl;

    cout << "\nThe assignment specifications required this program to be passed in "
            "\na text file as input. Command line example:  proj6.x < myTextFile" << endl;

    char singleCharacter ='\0';
    string singleNumber;
    string stringNumber;

    string singleWord;
    bool hasWord= false;

    int priority = 0;


    while (!cin.eof())
    {
        cin.get(singleCharacter);
        if (isdigit(singleCharacter))
        {
            stringNumber += singleCharacter; //Keep track of string of numbers
            //If there are characters stored the word ends now so add it
            if (singleWord != " " && singleWord != "\n" && singleWord != "\t")
            {
                if (hasWord) //Prevents storing empty strings
                {   //Storing Word
                    AddWord(wordMap, priority,singleWord);
                    singleWord.clear();
                    hasWord = false;
                }
            }

        } else // Char is Not a digit
        {
            //If current char is an ending then add word else keep building the word
                if (isalpha(singleCharacter))
            {
                singleWord.append(1,singleCharacter); //Keep track of word
                hasWord = true;
            } else
            {
                if (hasWord) //Prevents storing empty strings
                {
                    AddWord(wordMap, priority,singleWord);
                    singleWord.clear();
                    hasWord = false;
                }
            }

            if (!stringNumber.empty())
            {
                singleNumber = stringNumber;
                //Storing Number
                AddNumber(numberMap, priority,singleNumber);
                stringNumber.clear();
            }
        }
            //Store every character
            AddCharacter(characterMap, singleCharacter);

        priority += 1;
    }

    PrintTopTenWords     (wordMap);
    cout << "\n\n";
    PrintTopTenNumbers   (numberMap);
    cout << "\n\n";
    PrintTopTenCharacters(characterMap);

    clock_t end = clock();
    clock_t totalTime = end - start;
    cout << "Success: Run time " << float(totalTime)/CLOCKS_PER_SEC << endl;
    return 0;
}

// *******************************************************
// * Stores a word, its priority and quantity to the map *
// *******************************************************
void AddWord(map<string, pair<int, int>> &wordMap, int priority, string &singleWord)
{
    //Lowercase string. CopyRight Stefan Mai - StackOverflow.
    transform(singleWord.begin(), singleWord.end(), singleWord.begin(),
              [](unsigned char c){ return std::tolower(c); });

    if (wordMap.find(singleWord) == wordMap.end())
    {
        auto itr = wordMap.end();
        wordMap.insert(itr,make_pair(singleWord, make_pair(priority,1)));
    } else
    {
        auto itr = wordMap.find(singleWord);
        itr->second.second = itr->second.second + 1;
    }

}

// *********************************************************
// * Stores a number, its priority and quantity to the map *
// *********************************************************
void AddNumber(map<string, pair<int, int>> &numberMap, int priority, string &singleNumber)
{
    if (numberMap.find(singleNumber) == numberMap.end())
    {
        auto itr = numberMap.end();
        numberMap.insert(itr,make_pair(singleNumber, make_pair(priority,1)));
    } else
    {
        auto itr = numberMap.find(singleNumber);
        itr->second.second = itr->second.second + 1;
    }

}

// ********************************************************************
// * Stores a character, its priority (ASCII) and quantity to the map *
// ********************************************************************
void AddCharacter(map<char, pair<int, int>> &characterMap, char &singleCharacter)
{
    if (characterMap.find(singleCharacter) == characterMap.end())
    {
        auto itr = characterMap.end();
        characterMap.insert(itr,make_pair(singleCharacter
                               ,make_pair(int(singleCharacter),1)));
    } else
    {
        auto itr = characterMap.find(singleCharacter);
        itr->second.second = itr->second.second + 1;
    }
}

// **************************************************
// * Prints the top ten words more used in the file *
// **************************************************
void PrintTopTenWords(map<string, pair<int, int>> wordMap )
{
    cout << "There are " << wordMap.size() << " Unique Words. "
            "TOP 10 WORDS" << endl;
    int rank = 0;
    vector<pair<string,pair<int, int>>> temp;
    for (auto&itr :wordMap)
        temp.emplace_back(itr);

    sort(temp.begin(),temp.end(), comparatorStr);

    cout << "Index           Item       Number        Priority" << endl;
    for (auto& itr : temp)
    {
        if (rank >= 10)
            break;

        cout << "[" << right << setw(2) << rank << "]" << setw(15) << itr.first <<
             setw(14) << itr.second.second << setw(16) << itr.second.first << endl;
        rank += 1;
    }
}

// *******************************************************
// * Prints the top ten most Characters used in the file *
// *******************************************************
void PrintTopTenCharacters(map<char, pair<int, int>> characterMap )
{
    cout << "There are " << characterMap.size() << " Unique Characters. "
            "TOP 10 CHARACTERS" << endl;
    int rank = 0;
    vector<pair<char,pair<int, int>>> temp;

    for (auto&itr :characterMap)
        temp.emplace_back(itr);

    sort(temp.begin(),temp.end(), comparatorChar);

    cout << "Index           Item       Number        Priority" << endl;
    for (auto& itr : temp)
    {
        if (rank >= 10)
            break;

        if (itr.first == '\n')
        {
            cout << "[" << right << setw(2) << rank << "]" << setw(15) << "\\n" <<
                 setw(14) << itr.second.second << setw(16) << itr.second.first << endl;
        } else if (itr.first == ' ' )
        {
            cout << "[" << right << setw(2) << rank << "]" << setw(15) << "space" <<
                 setw(14) << itr.second.second << setw(16) << itr.second.first << endl;
        }else if (itr.first == '\t' )
        {
            cout << "[" << right << setw(2) << rank << "]" << setw(15) << "\\t" <<
                 setw(14) << itr.second.second << setw(16) << itr.second.first << endl;
        } else
        {
            cout << "[" << right << setw(2) << rank << "]" << setw(15) << itr.first <<
                 setw(14) << itr.second.second << setw(16) << itr.second.first << endl;
        }

        rank += 1;
    }

}

// ******************************************************
// * Prints the Top Ten Most Used numbers in the file   *
// ******************************************************
void PrintTopTenNumbers(map<string, pair<int, int>> numberMap)
{
    cout << "There are " << numberMap.size() << " Unique Numbers. "
            "TOP 10 NUMBERS" << endl;
    int rank = 0;
    vector<pair<string,pair<int, int>>> temp;
    for (auto&itr :numberMap)
        temp.emplace_back(itr);

    sort(temp.begin(),temp.end(), comparatorStr);
    cout << "Index           Item       Number        Priority" << endl;
    for (auto& itr : temp)
    {
        if (rank >= 10)
            break;

        cout << "[" << right << setw(2) << rank << "]" << setw(15) << itr.first <<
             setw(14) << itr.second.second << setw(16) << itr.second.first << endl;

        rank += 1;
    }
}

// ************************************************************
// * Serves as a comparator for the Sort() and map of strings *
// ************************************************************
int comparatorStr(const pair<string, pair<int, int>> a, const pair<string, pair<int, int>> b)
{
    if (a.second.second > b.second.second)
        return 1; // a goes first
    else if (a.second.second == b.second.second)
    {
        if (a.second.first < b.second.first)
            return 1; // a goes first
        else return 0;// b goes first
    }else
    {
        return 0; // b goes first
    }
}

// **********************************************************
// * Serves as a comparator for the Sort() and map of chars *
// **********************************************************
int comparatorChar(const pair<char, pair<int, int>> a, const pair<char, pair<int, int>> b)
{
    if (a.second.second > b.second.second)
        return 1; // a goes first
    else if (a.second.second == b.second.second)
    {   //Compared by ASCII. Lower ASCII goes first
        if (a.second.first < b.second.first)
            return 1; // a goes first
        else return 0;// b goes first
    }else
    {
        return 0; // b goes first
    }
}
