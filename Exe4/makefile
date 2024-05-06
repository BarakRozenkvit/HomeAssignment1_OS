CC = gcc
CFLAGS = -Wall -g -fprofile-arcs  -ftest-coverage -Wextra -pedantic -std=c99

all: ex4

ex4: Dijkstra.o 
	$(CC) $(CFLAGS) Dijkstra.o -o ex4

Dijkstra.o: Dijkstra.c Dijkstra.h
	$(CC) $(CFLAGS) -lgcov -c Dijkstra.c


clean:
	rm -f Dijkstra.o ex4 Dijkstra.gcno