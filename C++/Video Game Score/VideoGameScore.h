//
// Created by Claudio Osorio on 11/26/2020.
//

#ifndef INC_12__VIDEO_GAME_SCORES_PROGRAM_VIDEOGAMESCORE_H
#define INC_12__VIDEO_GAME_SCORES_PROGRAM_VIDEOGAMESCORE_H

#include <string>

using namespace std;

//Class Definition
class VideoGameScore {
private:
    string name; //name
    double score; //score
    bool yesOrNo; //Boolean is score above 10000?

public:
    //Constructor
    VideoGameScore();

    //mutators
    void setName (string name);
    void setScore (double score);
    void setAboveTenThousand();

    //accessors
    const string getName () const;
    const double getScore () const;
    const bool AboveTenThousand() const;
};


#endif //INC_12__VIDEO_GAME_SCORES_PROGRAM_VIDEOGAMESCORE_H