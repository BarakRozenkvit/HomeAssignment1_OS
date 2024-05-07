CC = gcc
CFLAGS = -Wall -g -fprofile-arcs  -ftest-coverage -Wextra -pedantic -std=c99

all: Dijkstra

Dijkstra: Dijkstra.o
	$(CC) $(CFLAGS) Dijkstra.o -o Dijkstra

Dijkstra.o: Dijkstra.c Dijkstra.h
	$(CC) $(CFLAGS) -c Dijkstra.c

clean:
	rm -f Dijkstra.o Dijkstra Dijkstra.gcno Dijkstra.c.gcov Dijkstra.gcda