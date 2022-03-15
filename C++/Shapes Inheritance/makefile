main.x: main.o shape.o square.o rectangle.o triangle.o circle.o
	g++ -o main.x -std=c++11 main.o shape.o square.o rectangle.o triangle.o circle.o
main.o: main.cpp
	g++ -c -std=c++11 main.cpp
shape.o: shape.h shape.cpp
	g++ -c -std=c++11 shape.h
	g++ -c -std=c++11 shape.cpp
square.o: square.h square.cpp
	g++ -c -std=c++11 square.h
	g++ -c -std=c++11 square.cpp
rectangle.o: rectangle.h rectangle.cpp
	g++ -c -std=c++11 rectangle.h
	g++ -c -std=c++11 rectangle.cpp
triangle.o: triangle.h triangle.cpp
	g++ -c -std=c++11 triangle.h
	g++ -c -std=c++11 triangle.cpp
circle.o: circle.h circle.cpp
	g++ -c -std=c++11 circle.h
	g++ -c -std=c++11 circle.cpp

 clean:
	-rm *.o
	-rm *.h.gch