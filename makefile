Lab6Executable: main.o
	g++ -std=c++11 -g -Wall main.o -o Lab6Executable

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

clean: 
	rm *.o Lab6Executable
