/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:04:43 by ahbasara          #+#    #+#             */
/*   Updated: 2023/01/14 13:15:43 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long int	q(char *s, char p, char kar)
{
	unsigned long long int	i;

	i = 0;
	if (p && !s)
		return (write(1, "(null)", 6));
	while (s && s[i])
		write(1, &s[i++], p);
	return ((!s && write(1, &kar, (!s || 0))) + i);
}

unsigned long long int	x(unsigned long long int i, char *s, char m)
{
	unsigned long long int	digit;
	unsigned long long int	lne;
	char					base;

	base = q(s, 0, 0);
	lne = 1;
	digit = 1;
	if (m && (long long int)i < 0)
	{
		write(1, "-", (lne++ || 1));
		i *= -1;
	}
	while ((digit * base) && i / (digit * base))
		digit *= (base * (lne++ || 1));
	while (digit && (i / digit || !i))
	{
		q(NULL, 0, s[(i / digit) % base]);
		digit /= base;
	}
	return (lne);
}

int	ft_printf(const char *s2, ...)
{
	unsigned long long int	lne;
	va_list					argl;
	char					*s;

	s = (char *)s2;
	lne = 0;
	va_start(argl, s2);
	while (*s)
	{
		(((*s != '%') && ((lne += q(NULL, 0, *s++)) || 1)) || (((*(++s)) == \
		'c' && s++) && ((lne += q(NULL, 0, va_arg(argl, int))) || 1)) || ((*\
		s == 's' && s++) && ((lne += q(va_arg(argl, char*), 1, 0)) || 1)) || \
		((*s == 'u' && s++) && ((lne += x(va_arg(argl, unsigned int), \
		"0123456789", 0)) || 1)) || (((*s == 'd' || *s == 'i' || *s == 'u') && \
		s++) && ((lne += x(va_arg(argl, int), "0123456789", 1)) || 1)) || ((*s \
		== 'p' && s++) && ((lne += (q("0x", 1, 0) + x(va_arg(argl, unsigned \
		long), "0123456789abcdef", 0))) || 1)) || ((*s == 'x' && s++) && ((lne \
		+= x(va_arg(argl, unsigned int), "0123456789abcdef", 0)) || 1)) || ((*s \
		== 'X' && s++) && ((lne += x(va_arg(argl, unsigned int), \
		"0123456789ABCDEF", 0)) || 1)) || ((*s == '%' && s++) && ((lne += q(\
		NULL, 0, '%')) || 1))
		);
	}
	return ((int)lne);
}
