





// ahbasara

#include "murmurlibc.h"

void	eol2fd(char *s, int fd)
{
	write(fd, s, xstrlen(s));
	write(fd, "\n", 1);
}
/* 
int	main(void)
{
	ft_putendl_fd("aaa",1);
}
 */
