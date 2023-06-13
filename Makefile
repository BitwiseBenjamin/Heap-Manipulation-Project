CC=g++
CFLAGS=-c -Wall
EXEC = run

$(EXEC): Heap.o util.o run.o ELEMENT.o
	$(CC) -o $(EXEC) Heap.o util.o run.o ELEMENT.o

Heap.o: Heap.cpp Heap.hpp
	$(CC) $(CFLAGS) Heap.cpp

util.o: util.cpp util.hpp
	$(CC) $(CFLAGS) util.cpp

run.o: run.cpp Heap.hpp util.hpp ELEMENT.cpp
	$(CC) $(CFLAGS) run.cpp

ELEMENT.o: ELEMENT.cpp
	$(CC) $(CFLAGS) ELEMENT.cpp

clean:
	rm *.o 
