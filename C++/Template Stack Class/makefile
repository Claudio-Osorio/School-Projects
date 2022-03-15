main.x: main.o
	g++ -o main.x -std=c++11 main.o
main.o: main.cpp stack.hpp
	g++ -c -std=c++11 main.cpp
	g++ -c -std=c++11 stack.hpp
clean:
	-rm *.o
	-rm *.hpp.gch
