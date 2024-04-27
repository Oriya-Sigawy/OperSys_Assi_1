#include <stdio.h>
#include <stdlib.h>

int max(int x, int y)
{
    return x > y ? x : y;
}

void create_arr(int *arr, unsigned int seed, int size)
{
    srand(seed);
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100 - 25;
    }
}

int maxSubArr(int size, int *array)
{
    int best = 0;
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += array[j];
            best = max(best, sum);
        }
    }
    return best;
}
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("ERROR!\nusage: %s <seed> <size>\n", argv[0]);
        exit(1);
    }
    int size = atoi(argv[2]);
    int *array = (int *)malloc(size * sizeof(int));
    unsigned int seed = atoi(argv[1]);
    create_arr(array, seed, size);
    int best = maxSubArr(size, array);
    printf("the result is %d\n", best);
    return 0;
}