proj5.x: proj5.o passserver.o
	g++ -std=c++11 -o proj5.x proj5.o passserver.o -lcrypt
proj5.o: proj5.cpp passserver.o
	g++ -c -std=c++11 -lcrypt proj5.cpp
passserver.o: passserver.cpp passserver.h hashtable.h
	g++ -c -std=c++11 -lcrypt passserver.cpp hashtable.h
	
clean:
	-rm *.o
