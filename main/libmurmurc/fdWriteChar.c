





// ahbasara

#include "murmurlibc.h"
/* #include <fcntl.h>  */

void	char2fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* int	main()
{
	int		fd;
	char	*buf;
	size_t	rs;

	buf = (char *)malloc(sizeof(char) * 2);
	fd = open ("./WWWWWWW", O_RDWR | O_CREAT , 777);
	printf("isopendf: %d\n", fd);
	ft_putstr_fd("asd",fd);
	rs = read(fd, buf, 2);
	printf("rs: %zu\n",rs);
	write(1, buf, 1);
	printf("buf: %s", buf);
	close(fd);
}
 */
