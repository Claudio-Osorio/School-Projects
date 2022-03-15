///////////////////////////////////////////////////////////////////////////////////////////////////////////////
////                                      Author: Claudio Osorio                                           ////
////                                         Date: 02/16/2021                                              ////
////         Disclaimer: An small part of the code was based on Pearson powerpoints                        ////
////                   and Dr. Gaitros COP 3330 lectures in the 2021 Spring class.                         ////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
using namespace std;

void OpenFile(ifstream & infile);                                                    //Opens the text file for reading
void FileToArray( char arrayOfBlobs [22] [72], ifstream & inputfile, const int maxRow, const int maxCol);
                                                                                    //^Copies Values from File to The Array
void ClearArray(char arrayofBlobs[22] [72],const int maxRow, const int maxCol);     //Makes sure the array is clean @start
void PrintArray(char arrayOfBlobs[22][72], const int maxRow, const int maxCol);     //Shows the characters stored @array
void BlobCounter(char arrayOfBlobs [22] [72], const int maxRow, const int maxCol, int & blobCount, int blobDetails[30] [2]);
                                                                                    //^Counts blobs
void RemoveBlob(char arrayOfBlobs [22] [72],int row, int col);                      //Removes blob @array
void StoreBlobDetails (int blobDetails [30] [2],const int row,const int col, const int blobCount);
                                                                                    //^Stores Blobs row and col

int main()
{
    ifstream inputfile;
    int blobCount = 0;
    const int maxCol = 72;
    const int maxRow = 22;
    char arrayOfBlobs [maxRow][maxCol];
    int blobDetails [30] [2] = {0};
    OpenFile(inputfile);
    ClearArray(arrayOfBlobs,maxRow,maxCol);
    FileToArray(arrayOfBlobs, inputfile, maxRow,maxCol);
    inputfile.close();
    cout << "         1         2         3         4         5         6         7\n"
            "1234567890123456789012345678901234567890123456789012345678901234567890" << endl;

    PrintArray(arrayOfBlobs,maxRow,maxCol);
    BlobCounter(arrayOfBlobs,maxRow, maxCol,blobCount, blobDetails);

    for (int x = 1; x <= blobCount; x++)
    {
        if (blobDetails [x] [0] != 0)
        cout << "Blob Found at Row, Col is: " << blobDetails[x][0] << ", " << blobDetails[x][1] << endl;
    }
    cout << "\nNumber of blobs = " << blobCount << endl;

    return 0;
}
             /////////////////////////
            ////////FUNCTIONS////////
           /////////////////////////

//Opens the text file using the hardcoded filename.
void OpenFile(ifstream & infile)
{
    char filename[]= {"blob.txt"};
    infile.open(filename);

     if(infile.fail())
    {
        cout << "File open failed.\n";
        exit(1);
    }
}

//Stores text file content into array
//Every line from the text file will be stored into a new array
void FileToArray(char arrayOfBlobs[22][72], ifstream & inputfile,const int maxRow, const int maxCol)
{
    char myChar;
    int col;
    for( int row = 1; row < maxRow - 1 && !inputfile.eof(); row++)
    {
        col= 1;
        inputfile.get(myChar);
        while(myChar !='\n')
        {
            arrayOfBlobs[row][col++] = myChar;
            inputfile.get(myChar);
        }
    }
}

//Clear array. Sets all the characters and elements of the array to blank
void ClearArray(char arrayOfBlobs[22][72], const int maxRow,const int maxCol)
{
    for (int rowCount = 0; rowCount < maxRow; rowCount++)
    {
        for (int colCount = 0; colCount < maxCol; colCount++)
            arrayOfBlobs[rowCount][colCount] = ' ';
    }
}

//Print values from array
void PrintArray(char arrayOfBlobs[22][72], const int maxRow, const int maxCol)
{
    for (int rowCount = 1; rowCount < maxRow - 1; rowCount++)
    {
        for (int colCount = 1; colCount < maxCol - 1; colCount++)
            cout << arrayOfBlobs[rowCount][colCount];

        cout << "\n";
    }
}

//Goes through all the characters stored in the arrays and it finds an X then clears it and the surrounding
//X with it (which are part of the same blob)
void BlobCounter(char arrayOfBlobs [22] [72], const int maxRow, const int maxCol,int & blobCount, int blobDetails [30] [2])
{
    for(int row = 1; row < maxRow - 1; row++)
    {
        for (int col = 1; col < maxCol - 1 ; col++)
        {
            if (arrayOfBlobs [row] [col] == 'X')
            {
                blobCount +=1;
                StoreBlobDetails (blobDetails, row,col,blobCount);
                RemoveBlob(arrayOfBlobs, row,col);
            }
        }
    }
}

// Destroys the blobs by finding surrounding blobs recursively and setting them to blank
void RemoveBlob(char arrayOfBlobs [22] [72], int row, int col)
{
    arrayOfBlobs[row][col] = ' ';

        if (arrayOfBlobs[row][col + 1] != ' ')                           //RIGHT SIDE
            RemoveBlob(arrayOfBlobs, row, col + 1 );


        if (arrayOfBlobs[row - 1][col + 1] != ' ')                       //TOP RIGHT CORNER
            RemoveBlob(arrayOfBlobs, row-1, col+1);


        if (arrayOfBlobs[row - 1][col] != ' ')                           //ABOVE
            RemoveBlob(arrayOfBlobs, row - 1 , col);

        if (arrayOfBlobs[row - 1][col - 1] != ' ')                       //TOP LEFT CORNER
            RemoveBlob(arrayOfBlobs, row-1, col-1);

        if (arrayOfBlobs[row][col - 1] != ' ')                           //LEFT SIDE
            RemoveBlob(arrayOfBlobs, row, col-1);

        if (arrayOfBlobs[row + 1][col] != ' ')                           //BELOW
            RemoveBlob(arrayOfBlobs, row+1, col);

        if (arrayOfBlobs[row + 1][col + 1] != ' ')                      //BOTTOM RIGHT CORNER
            RemoveBlob(arrayOfBlobs, row+1, col+1);


        if (arrayOfBlobs[row + 1][col - 1] != ' ')                       //BOTTOM LEFT CORNER
            RemoveBlob(arrayOfBlobs, row+1, col-1);
}

//Upon call this stores the row and col of a blob once it is found
void StoreBlobDetails (int blobDetails [30] [2], const int row, const int col,const int blobCount)
{
    blobDetails [blobCount] [0] = row;
    blobDetails [blobCount] [1] = col;
}
