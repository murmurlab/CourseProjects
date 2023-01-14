#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		i;
	char	*l;
	fd = open("file", 600);
	printf("fd: %d\n", fd);
	i = 0;
	while (i++ < 10)
	{
		l = get_next_line(fd);
		write(1, l, ft_strlen(l));
	}
	
}