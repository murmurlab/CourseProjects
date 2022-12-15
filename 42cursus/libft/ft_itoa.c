/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 01:29:57 by ahbasara          #+#    #+#             */
/*   Updated: 2022/12/16 02:35:58 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_digloc(int nb, char *src)
{
	char	digit;

	digit = 2;
	while (10 >= (nb / 10))
	{
		nb /= 10;
		digit++;
	}
	src = (char *)malloc(sizeof(char) * digit);
	return (digit);
}

char	*ft_itoa(int n)
{
	char	*str;
	char	l;

	l = ft_digloc(n, str);
	while (--l)
		str++;
	*str-- = 0;
	while (n >= 10)
	{
		*str-- = (n % 10) + 48;
		n /= 10;
	}
	*str-- = (n + 48);
	return (str);
}

int	main(int argv, char argc[][])
{
	(void)argv;
	printf("res: %d\n", ft_itoa(1234));
}