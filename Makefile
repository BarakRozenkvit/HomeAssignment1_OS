.PHONY: Exe2 Exe3 Exe4 Exe5 Exe6

all: Exe2 Exe3 Exe4 Exe5 Exe6

Exe2:
	cd Exe2 && make all

Exe3:
	cd Exe3 && make all

Exe4:
	cd Exe4 && make all

Exe5:
	cd Exe5 && make all

Exe6:
	cd Exe6 && make all


clean:
	cd Exe2 && make clean
	cd Exe3 && make clean
	cd Exe4 && make clean
	cd Exe5 && make clean
	cd Exe6 && make clean