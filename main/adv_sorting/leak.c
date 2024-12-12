#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void    buff()
{
    int *ptr;

    ptr = 0;
    ptr = malloc(8196);
}

void    fun()
{
    int *ptr;

    ptr = 0;
    getchar();
    buff();
    ptr = malloc(4096);
    getchar();
}

int main(int argc, char const *argv[])
{
    int *ptr;

    ptr = malloc(9999);
    getchar();
    fun();
    getchar();
    return 0;
}


void __attribute__((destructor))after_main()
{
   pause();
}