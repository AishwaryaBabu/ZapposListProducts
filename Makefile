all: main 

main: main.o list.o  
	g++ -pg main.o list.o -o main

main.o: main.cpp 
	g++ -pg -c main.cpp

list.o: list.cpp list.h 
	g++ -pg -c list.cpp

clean:
	rm *.o main 
