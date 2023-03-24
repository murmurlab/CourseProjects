/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:13:08 by ahbasara          #+#    #+#             */
/*   Updated: 2022/12/20 05:07:08 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* 
void	ft_putnbr_fd(int n, int fd)
{
	char	*s;
	
	s = malloc(ft_strlen(ft_itoa(n)));
	ft_memcpy(s, ft_itoa(n), ft_strlen(ft_itoa(n)));
	write(fd, s, ft_strlen(ft_itoa(n)));
}
 */

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n * -1;
		}
		if (n >= 9)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		ft_putchar_fd((n % 10) + '0', fd);
	}
}

/* 
int	main(void)
{
    ft_putnbr_fd(5,1);
}
 */