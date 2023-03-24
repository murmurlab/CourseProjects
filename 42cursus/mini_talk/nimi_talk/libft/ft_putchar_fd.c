/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 07:45:26 by ahbasara          #+#    #+#             */
/*   Updated: 2022/12/19 22:29:15 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <fcntl.h>  */

void	ft_putchar_fd(char c, int fd)
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