#include <stdio.h>
#include <stdlib.h>

void    buff()
{
    int *ptr;

    ptr = 0;
    // ptr = malloc(8196);
}

void    fun()
{
    int *ptr;

    ptr = 0;
    getchar();
    buff();
    // ptr = malloc(4096);
    getchar();
}

int main(int argc, char const *argv[])
{
    int *ptr;

    ptr = malloc(2048222);
    getchar();
    fun();
    getchar();
    return 0;
}
