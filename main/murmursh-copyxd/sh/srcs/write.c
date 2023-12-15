#include <unistd.h>
#include "include.h"

int main(int argc, char const *argv[])
{
	char	*buff;

	buff = get_next_line(0);
	write(1, buff, strlen(buff));
	free(buff);
	buff = get_next_line(0);
	write(1, buff, strlen(buff));
	free(buff);
	buff = get_next_line(0);
	write(1, buff, strlen(buff));
	free(buff);
	buff = get_next_line(0);
	write(1, buff, strlen(buff));
	free(buff);
	buff = get_next_line(0);
	write(1, buff, strlen(buff));
	free(buff);
	
	return 0;
}
