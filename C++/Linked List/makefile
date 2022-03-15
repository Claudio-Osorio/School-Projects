### Claudio Osorio's makefile ###
all: mydriver.x driver.x
mydriver.x: mydriver.o
	g++ -o mydriver.x -std=c++11 mydriver.o
mydriver.o:	mydriver.cpp tlist.h tlist.hpp tnode.h
	g++ -c -std=c++11 mydriver.cpp
driver.x: driver.o
	g++ -o driver.x -std=c++11 driver.o
driver.o: driver.cpp tlist.h tlist.hpp tnode.h
	g++ -c -std=c++11 driver.cpp
clean:
	-rm *.o
	-rm *.h.gch
	-rm *.hpp.gch