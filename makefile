CC = gcc
CFLAGS = -Wall -Wextra -g

all: Poisson

Poisson: Poisson.c
	$(CC) $(CFLAGS) -o Poisson Poisson.c -lm

clean:
	rm -f Poisson
