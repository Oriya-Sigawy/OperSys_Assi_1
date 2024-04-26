#include <stdio.h>
#include <stdlib.h>

int max(int x, int y)
{
    return x > y ? x : y;
}

void create_arr(int *arr, unsigned int seed, int size)
{
    srand(seed);
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % 100 - 25;
    }
}

int main(int argc, char **argv)
{
    int size = argv[2] - '0';
    int *array = (int *)malloc(size * sizeof(int));
    unsigned int seed = argv[1] - '0';
    create_arr(array, seed, size);
    int best = 0;
    for (size_t i = 0; i < size; i++)
    {
        int sum = 0;
        for (size_t j = i; j < size; j++)
        {
            sum += array[j];
            best = max(best, sum);
        }
    }
    printf("the result is %d", best);
    return 0;
}