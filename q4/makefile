CC = gcc
FLAGS = -Wall -g -Wextra -fprofile-arcs -ftest-coverage
all: dijkstra test
dijkstra: dijkstra.c
	$(CC) $(FLAGS) $^ -o $@
test: test.c
	$(CC) $(FLAGS) $^ -o $@
clean:
	rm -f *.o dijkstra test *.gcda *.gcno *.gcov
