/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:21:37 by codespace         #+#    #+#             */
/*   Updated: 2022/12/20 21:37:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	is_neg;
	int	res;

	is_neg = 1;
	while (((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	if (*str == '-')
		is_neg = -1;
	if ((is_neg == -1 || *str == '+') && str++)
	{
	}
	res = 0;
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + (*str++ - '0');
	return (res * is_neg);
}

/* int main(void)
{
    char    s1[44] = "++214748u3647";
    printf("%d\n", ft_atoi(s1));
    printf("%d", atoi(s1));
} */