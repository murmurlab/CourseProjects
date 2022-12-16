/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 01:29:57 by ahbasara          #+#    #+#             */
/*   Updated: 2022/12/16 19:26:28 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_recursive(int nb,char *str)
{
	if (nb >= 10)
	{
		ft_recursive(nb / 10, str - 1);
		*str = ((nb % 10) + 48);
	}
	if (nb < 10)
		*str = (nb + 48);
}

char	*ft_itoa(int nb)
{
	char	*str;
	char	digit;
	char	*ostr;
	int		n;
	int		stat;

	stat = (nb < 0);
	n = nb;
	digit = 2;
	if (stat)
	{
		n *= -1;
		digit++;
	}
	while (10 <= n)
	{
		n /= 10;
		digit++;
	}
	str = malloc(sizeof(char) * digit);
	ostr = str;
	if (nb == -2147483648)
		return (strcpy(str, "-2147483648"));
	if (stat)
	{
		*str++ = '-';
		nb *= -1;
	}
	ft_recursive(nb, (str + ((sizeof(char) * digit) - 2 - stat)));
	return (ostr);
}

/* int	main(void)
{
	printf("res: %s\n", ft_itoa(0));
} */