CC = gcc
FLAGS = -Wall -g -Wextra
all: add2PB findPhone
add2PB: add2PB.c
	$(CC) $(FLAGS) $^ -o $@
findPhone: findPhone.c
	$(CC) $(FLAGS) $^ -o $@
clean:
	rm -f *.o findPhone add2PB phoneBook
