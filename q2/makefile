CC = gcc
FLAGS = -Wall -g

all: Poisson test
.PHONY: all clean
Poisson : Poisson.o
	$(CC) $(FLAGS) -o Poisson Poisson.o -lm

Poisson.o : Poisson.c
	$(CC) $(FLAGS) -c Poisson.c
test: test.c
	$(CC) $(FLAGS) -o test test.c

clean:
	rm -f Poisson Poisson.o

.PHONY : all clean test
