#include <stdio.h>
int main()
{
    void *ptr;
    memset(ptr, 0xDEADBEEF, 5);
    return 0;
}