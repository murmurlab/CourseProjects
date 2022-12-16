/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 01:29:57 by ahbasara          #+#    #+#             */
/*   Updated: 2022/12/16 03:20:20 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_diglen(int nb)
{
	char	digit;

	digit = 2;
	if (nb < 0)
	{
		nb *= -1;
		digit++;
	}
	while (10 <= nb)
	{
		nb /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	char	*str;
	char	l;

	l = ft_diglen(n);
	str = malloc(sizeof(char) * l);
	while (--l - 1)
		str++;
	*str-- = 0;
	while (n >= 10)
	{
		*str-- = (n % 10) + 48;
		n /= 10;
	}
	*str = (n + 48);
	return (str);
}

/* int	main(void)
{
	printf("res: %s\n", ft_itoa(1234));
} */