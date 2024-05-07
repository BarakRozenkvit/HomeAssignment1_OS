CC = gcc
CFLAGS = -Wall -Wextra -g

all: Poisson

Poisson: Poisson.o
	$(CC) $(CFLAGS) -o Poisson Poisson.o -lm

Poisson.o: Poisson.c
	$(CC) $(CFLAGS) -c Poisson.c

clean:
	rm -f Poisson Poisson.o
