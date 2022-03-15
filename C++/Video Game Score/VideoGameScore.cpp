//
// Created by Claudio Osorio on 11/26/2020.
//

#include "VideoGameScore.h"
#include <string>
#include <iostream>

using namespace std;

//Constructor
//Sets the name and score to defaults.
VideoGameScore::VideoGameScore()
{
    name = "";
    score = 0;
}

//Mutators
//will specify the name of the gamer
void VideoGameScore::setName (string nameGiven)
{
    name = nameGiven;
}
// will specify the score of the gamer
void VideoGameScore::setScore (double scoreGiven)
{
    score = scoreGiven;
}
//Function will set a value of 1 or 0 to the yesOrNo variable depending on whether the
//score was higher than 10000 (1) or not (0)
void VideoGameScore::setAboveTenThousand()
{
    if (score >= 10000)
    {
        yesOrNo = 1;
    }
    else
    {
        yesOrNo = 0;
    }

}

//Accessors
//Will return the name of the gamer
const string VideoGameScore::getName () const
{
    return name;
}

//will return the score of the gamer
const double VideoGameScore::getScore () const
{
    return score;
}
//Will return 1 or 0 if the score is higher than 10 000
const bool VideoGameScore::AboveTenThousand() const
{
    return yesOrNo;
}

