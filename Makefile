all: fork1 wait ctrlc
.PHONY: all

fork1: fork1.o
	cc -o fork1 fork1.o

wait: wait.o
	cc -o wait wait.o

ctrlc: ctrlc.o
	cc -o ctrlc ctrlc.o

fork1.o:
	cc -c fork1.c

wait.o:
	cc -c wait.c

ctrlc.o:
	cc -c ctrlc.c

.PHONY: clean

clean:
	rm fork1 wait ctrlc *.o
