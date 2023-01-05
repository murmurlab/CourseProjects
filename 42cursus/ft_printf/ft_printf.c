/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:04:43 by ahbasara          #+#    #+#             */
/*   Updated: 2023/01/05 08:44:10 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

size_t	ft_printf(const char *s, ...)
{
	va_list	argl;
	char	*stock;

	stock = (char *)s;
	va_start(argl, s);
	while (*s)
	{
		if (*s == '%' && *++s)
		{
			if (*s == 'c')
				write(1, va_arg(argl, char*), 1);
			else if (*s == 's')
				//write(1, va_arg(argl, char*), ft_strlen(va_arg(argl, char*)));
				ft_putstr(va_arg(argl, char*));
			else if (*s == 'd')
			{
				
				//ft_putnbr(va_arg(argl, int));
			}
		}
		else
			write(1, s++, 1);
	}	
	return (s - stock);
}
