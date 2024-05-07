all: maxSubArrayN maxSubArrayN2 maxSubArrayN3

maxSubArrayN2: maxSubArrayN2.o createArray.o createArray.h
	gcc -Wall -o maxSubArrayN2 maxSubArrayN2.o createArray.o -lm

maxSubArrayN3: maxSubArrayN3.o createArray.o createArray.h
	gcc -Wall -o maxSubArrayN3 maxSubArrayN3.o createArray.o -lm

maxSubArrayN: maxSubArrayN.o createArray.o createArray.h
	gcc -Wall -o maxSubArrayN maxSubArrayN.o createArray.o -lm

maxSubArrayN2.o: maxSubArrayN2.c createArray.h
	gcc -Wall -c maxSubArrayN2.c -pg -g

maxSubArrayN3.o: maxSubArrayN3.c createArray.h
	gcc -Wall -c maxSubArrayN3.c -pg -g

maxSubArrayN.o: maxSubArrayN.c createArray.h
	gcc -Wall -c maxSubArrayN.c -pg -g

createArray.o: createArray.c createArray.h
	gcc -Wall -c createArray.c

clean:
	rm maxSubArrayN maxSubArrayN2 maxSubArrayN3
	rm *.o