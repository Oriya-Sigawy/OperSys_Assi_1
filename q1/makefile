CC = gcc
FLAGS = -Wall -g -Wextra
all: ex1 ex2 ex3
.PHONY: all clean
ex1: ex1.c
	$(CC) $(FLAGS) $^ -o $@
ex2: ex2.c
	$(CC) $(FLAGS) $^ -o $@
ex3: ex3.c
	$(CC) $(FLAGS) $^ -o $@
clean:
	rm -f *.o ex1 ex2 ex3
