CC = gcc
PARAMS = -Wall

all: Main

Main: main.o libpoisson.so
	$(CC) $(PARAMS) -lm -L. -lpoisson main.o -o Main

main.o: Poisson.h
	$(CC) $(PARAMS) -c main.c

libpoisson.so: Poisson.c Poisson.h
	$(CC) $(PARAMS) -fPIC -c Poisson.c -o poisson.o
	$(CC) -shared poisson.o -o libpoisson.so


clean:
	rm *.so
	rm *.o
	rm Main
