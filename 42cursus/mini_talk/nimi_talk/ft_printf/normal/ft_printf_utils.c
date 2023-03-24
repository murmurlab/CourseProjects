/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:34:37 by ahbasara          #+#    #+#             */
/*   Updated: 2023/01/15 03:04:14 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_check_format(va_list argl, const char **str, int *len)
{
	if ((**str) == 'c' && (*str)++)
		*len += q(NULL, 0, va_arg(argl, int));
	else if ((**str) == 's' && (*str)++)
		*len += q(va_arg(argl, char *), 1, 0);
	else if ((**str) == 'u' && (*str)++)
		*len += x(va_arg(argl, unsigned int), "0123456789", 0);
	else if (((**str) == 'd' || (**str) == 'i' || (**str) == 'u') && (*str)++)
		*len += x(va_arg(argl, int), "0123456789", 1);
	else if ((**str) == 'p' && (*str)++)
		*len += (q("0x", 1, 0) + x(va_arg(argl, unsigned long), \
		"0123456789abcdef", 0));
	else if ((**str) == 'x' && (*str)++)
		*len += x(va_arg(argl, unsigned int), "0123456789abcdef", 0);
	else if ((**str) == 'X' && (*str)++)
		*len += x(va_arg(argl, unsigned int), "0123456789ABCDEF", 0);
	else if ((**str) == '%' && (*str)++)
		*len += q(NULL, 0, '%');
}
