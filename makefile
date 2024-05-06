CC = gcc
CFLAGS = -Wall -Wextra -g

all: StackOverFlow ZeroDevision NullPointer

StackOverFlow: Exe1/StackOverFlow.c
	$(CC) $(CFLAGS) -o StackOverFlow StackOverFlow.c

ZeroDevision: Exe1/ZeroDevision.c
	$(CC) $(CFLAGS) -o ZeroDevision ZeroDevision.c

NullPointer: Exe1/NullPointer.c
	$(CC) $(CFLAGS) -o NullPointer NullPointer.c

clean:
	rm -f StackOverFlow ZeroDevision NullPointer

