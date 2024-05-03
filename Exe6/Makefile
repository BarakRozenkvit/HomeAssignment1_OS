

all: add2PB findPhone

findPhone: findPhone.o
	gcc -Wall findPhone.o -o findPhone

add2PB: add2PB.o
	gcc -Wall add2PB.o -o add2PB

add2PB.o: add2PB.c
	gcc -Wall -c add2PB.c

findPhone.o:findPhone.c
	gcc -Wall -c findPhone.c

clean:
	rm *.o
	rm add2PB
	rm findPhone