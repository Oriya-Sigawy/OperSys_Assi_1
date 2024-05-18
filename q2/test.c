#include <stdlib.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    assert(system("./Poisson 1.1 2 > result_1.1_2.txt") == 0);
    assert(system("cmp result_1.1_2.txt expected_1.1_2.txt") == 0);
    system("rm result_1.1_2.txt");
    assert(system("./Poisson 2.1 5 > result_2.1_5.txt") == 0);
    assert(system("cmp result_2.1_5.txt expected_2.1_5.txt") == 0);
    system("rm result_2.1_5.txt");
    assert(system("./Poisson 3 3.1 4 > result_error.txt") != 0);
    assert(system("cmp result_error.txt expected_error.txt") == 0);
    system("rm result_error.txt");
    assert(system("./Poisson > result_error.txt") != 0);
    assert(system("cmp result_error.txt expected_error.txt") == 0);
    system("rm result_error.txt");

    return 0;
}