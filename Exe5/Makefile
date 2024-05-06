all: maxSubArrayN maxSubArrayN2 maxSubArrayN3

maxSubArrayN2: maxSubArrayN2.c createArray.c createArray.h
	gcc -Wall -o maxSubArrayN2 maxSubArrayN2.c createArray.c -lm -pg -g

maxSubArrayN3: maxSubArrayN3.c createArray.c createArray.h
	gcc -Wall -o maxSubArrayN3 maxSubArrayN3.c createArray.c -lm -pg -g

maxSubArrayN: maxSubArrayN.c createArray.c createArray.h
	gcc -Wall -o maxSubArrayN maxSubArrayN.c createArray.c -lm -pg -g

clean:
	rm maxSubArrayN maxSubArrayN2 maxSubArrayN3