cc = gcc
flags = -Wall -g

all: libpoisson.so main 
.PHONY: all clean
main : main.o libpoisson.so
	$(cc) $(flags) main.o -L. -lpoisson -lm -o main

main.o : main.c
	$(cc) $(flags) -c main.c

libpoisson.so : poisson.c poisson.h
	$(cc) -shared poisson.c -fPIC -o libpoisson.so 

.PHONY: clean all
clean:
	rm -f *.o main libpoisson.so
