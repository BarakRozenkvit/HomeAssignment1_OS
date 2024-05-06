CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99
LIBS =-lm

all: ex3

ex3: Poisson.o Proj3.o libpoisson.so
	$(CC) $(CFLAGS) Poisson.o Proj3.o -o ex3 $(LIBS)
 
libpoisson.so: Poisson.o
	$(CC) $(CFLAGS) -shared -o libpoisson.so Poisson.o

Poisson.o: Poisson.c Poisson.h
	$(CC) $(CFLAGS) -fPIC -c -o Poisson.o Poisson.c 

Proj3.o: Proj3.c Poisson.h
	$(CC) $(CFLAGS) -c -o Proj3.o Proj3.c 

clean:
	rm -f Poisson.o Proj3.o ex3 libpoisson.so
