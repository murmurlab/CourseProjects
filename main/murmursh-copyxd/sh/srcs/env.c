#include <stdio.h>

int main(int argc, char const *argv[])
{
    extern char     **environ;

    printf("start\n");
    for (size_t i = 0; environ[i]; i++)
    {
        printf("%s\n", environ[i]);
    }
    printf("end\n");
    
    return 0;
}
