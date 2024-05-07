.PHONY: Exe1 Exe2 Exe3 Exe4 Exe5 Exe6

all:
	make -C Exe1 all
	make -C Exe2 all
	make -C Exe3 all
	make -C Exe4 all
	make -C Exe5 all
	make -C Exe6 all

clean:
	make -C Exe1 clean
	make -C Exe2 clean
	make -C Exe3 clean
	make -C Exe4 clean
	make -C Exe5 clean
	make -C Exe6 clean