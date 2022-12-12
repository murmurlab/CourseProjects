#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char	*fuck(char *str);

int	main(void)
{
	char *de = "deneme";
	printf("------->>:  %s\n", fuck(de));
	char	*num;
	char	*mem;
	int		a = 223233232;
	char	b = 1;

	int *p = &b;
	printf("adressssss : %p", p);
	p+=1;
	printf("adressssss : %p", p);
	b = a;
	//printf("%d", b);

	mem = malloc(sizeof(char)*32);
	num = "abcdefgh";
	strcpy(mem, "selame");
	printf("mem: %s\n",mem);
	//ft_bzero(&mem[2], 2);
	clock_t begin = clock();
	ft_memcpy(&mem[0], num, 4);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("%f\n", time_spent);
	printf("arr[0] = %c\narr[1] = %c\narr[2] = %c\narr[3] = %c\narr[4] = %c\nmem first addr: %s\n ", mem[0], mem[1], mem[2], mem[3], mem[4], mem);
}

// ahmetfaruk
// ahmahmahma
// ahmetfaruk
// xxxixxxlxi