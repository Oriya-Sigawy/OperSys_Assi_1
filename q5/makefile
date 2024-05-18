CC = gcc
FLAGS = -Wall -g -Wextra -pg
all: max_sub_arr_n max_sub_arr_n2 max_sub_arr_n3
.PHONY: all clean
max_sub_arr_n: max_sub_arr_n.c
	$(CC) $(FLAGS) $^ -o $@
max_sub_arr_n2: max_sub_arr_n2.c
	$(CC) $(FLAGS) $^ -o $@
max_sub_arr_n3: max_sub_arr_n3.c
	$(CC) $(FLAGS) $^ -o $@
clean:
	rm -f *.o max_sub_arr_n max_sub_arr_n2 max_sub_arr_n3
