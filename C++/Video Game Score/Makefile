#VideoGameScore makefile
CC= g++ -std=c++11
VideoGameScore: VideoGameScoreApp.o
		$(CC) VideoGameScoreApp.o VideoGameScore.o -o VideoGameScore
VideoGameScoreApp.o: VideoGameScoreApp.cpp
		$(CC) -c VideoGameScoreApp.cpp
		$(CC) -c VideoGameScore.cpp
VideoGameScore.o: VideoGameScore.h VideoGameScore.cpp
		$(CC) -c VideoGameScore.h
		$(CC) -c VideoGameScore.cpp
clean: 
		rm -rf *o VideoGameScore