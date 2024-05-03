CC = gcc
PARAMS = -Wall

all: Poisson

Poisson: Poisson.o
	$(CC) $(PARAMS) Poisson.o -o Poisson

Poisson.o: Poisson.c Poisson.h
	$(CC) $(PARAMS) -c Poisson.c


clean:
	rm *.o
	rm Poisson