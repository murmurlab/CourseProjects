/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 07:45:26 by ahbasara          #+#    #+#             */
/*   Updated: 2022/12/18 08:18:51 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h> 

void	ft_putchar_fd(char	c, int fd)
{
	write(fd, &c, 1);
}

int	main()
{
	int		fd;
	char	*buf;	
	size_t	rs;

	buf = (char *)malloc(sizeof(char) * 2);
	fd = open ("./WWWWWWW", O_RDWR | O_CREAT | O_EXCL, 777);
	ft_putchar_fd('a',fd);
	rs = read(fd, buf, 0);
	printf("rs: %zu\n",rs);
	write(1, buf, 1);
}