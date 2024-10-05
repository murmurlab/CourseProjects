#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void dtor( void ) {
	system("leaks a.out");
}

int main(int argc, char const *argv[])
{
	void **x;
		x = malloc(8);
	x[0] = malloc(123);
	atexit(dtor);
	// _Exit(1);
	// exit(1);
	// while (1)
	// {
	// 	printf("arst\n");
	// 	x = malloc(123);
	// 	// x = strdup("arositnarisetniarent");
	// 	if (!read(0, x, 123)) break;
	// 	fflush(stdout);
	// }
	
	return 0;
}
// void __attribute__((destructor))after_main()
// {
// 	system("leaks a.out");
// 	// system("leaks a.out");
// }
