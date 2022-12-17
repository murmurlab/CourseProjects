/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:21:37 by codespace         #+#    #+#             */
/*   Updated: 2022/12/17 23:25:47 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	is_neg;
	int	res;

	is_neg = 1;
	i = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-')
		is_neg = -1;
	if ((is_neg == -1 || str[i] == '+') && i++)
		;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	return (res * is_neg);
}


/* int main(void)
{
    char    s1[44] = "++214748u3647";
    printf("%d\n", ft_atoi(s1));
    printf("%d", atoi(s1));
} */