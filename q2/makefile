CC = gcc
FLAGS = -Wall -g

all: Poisson
.PHONY: all clean
Poisson : Poisson.o
	$(CC) $(FLAGS) -o Poisson Poisson.o -lm

Poisson.o : Poisson.c
	$(CC) $(FLAGS) -c Poisson.c

clean:
	rm -f Poisson Poisson.o

.PHONY : all clean
