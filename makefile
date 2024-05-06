CC = gcc
CFLAGS = -Wall -Wextra -g

all: StackOverFlow ZeroDevision NullPointer

StackOverFlow: StackOverFlow.c
	$(CC) $(CFLAGS) -o StackOverFlow StackOverFlow.c

ZeroDevision: ZeroDevision.c
	$(CC) $(CFLAGS) -o ZeroDevision ZeroDevision.c

NullPointer: NullPointer.c
	$(CC) $(CFLAGS) -o NullPointer NullPointer.c

clean:
	rm -f StackOverFlow ZeroDevision NullPointer

