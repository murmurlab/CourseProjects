#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	*arr = malloc(10 * sizeof(int));
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	arr[5] = 6;
	arr[6] = 7;
	arr[7] = 8;
	arr[8] = 9;
	arr[9] = 10;
	free(arr);
	arr[8] = 99999999;
	printf("%d", arr[8]);
}