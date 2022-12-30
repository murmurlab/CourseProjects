/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:04:43 by ahbasara          #+#    #+#             */
/*   Updated: 2022/12/30 16:45:33 by ahbasara         ###   ########.fr       */
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
		if (*s == '%' && *(s + 1))
		{
			if (*++s == 'c')
				write(1, va_arg(argl, char), 1);
		}
		else
			write(1, s++, 1);
	}
}
