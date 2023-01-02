/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nan0bit <nan0bit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:04:43 by ahbasara          #+#    #+#             */
/*   Updated: 2022/12/31 21:00:11 by nan0bit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *s, ...)
{
	va_list	argl;

	va_start(argl, s);
	while (*s)
	{
		if (*s == '%' && *++s)
		{
			if (*s == 'c')
				write(1, va_arg(argl, char), 1);
			else if (*s == 's')
			{
				/* code */
			}
			
		}
		else
			write(1, s++, 1);
	}
}
