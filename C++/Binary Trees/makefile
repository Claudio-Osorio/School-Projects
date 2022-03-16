proj4.x: proj4_driver.o
	g++ -o proj4.x -std=c++11 proj4_driver.o
proj4_driver.o: proj4_driver.cpp bet.h bet.hpp
	g++ -c -std=c++11 proj4_driver.cpp
clean:
	-rm *.o

