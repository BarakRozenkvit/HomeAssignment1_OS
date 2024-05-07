CC = gcc
CFLAGS = -Wall -Wextra -g

all: StackOverFlow ZeroDevision NullPointer

StackOverFlow: StackOverFlow.o
	$(CC) $(CFLAGS) -o StackOverFlow StackOverFlow.o

ZeroDevision: ZeroDevision.o
	$(CC) $(CFLAGS) -o ZeroDevision ZeroDevision.o

NullPointer: NullPointer.o
	$(CC) $(CFLAGS) -o NullPointer NullPointer.o

StackOverFlow.o: StackOverFlow.c
	$(CC) $(CFLAGS) -c StackOverFlow.c

ZeroDevision.o: ZeroDevision.c
	$(CC) $(CFLAGS) -c ZeroDevision.c

NullPointer.o: NullPointer.c
	$(CC) $(CFLAGS) -c NullPointer.c

clean:
	rm -f StackOverFlow ZeroDevision NullPointer StackOverFlow.o ZeroDevision.o NullPointer.o

