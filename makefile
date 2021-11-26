all: compile run

compile:
	gcc -I ./include -c ./src/bash.c -o ./lib/bash.o
	gcc -I ./include -o ./bin/bash -s ./src/program.c ./lib/bash.o

run:
	./bin/bash