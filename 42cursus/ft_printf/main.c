/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:09:04 by ahbasara          #+#    #+#             */
/*   Updated: 2023/01/06 07:21:56 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

size_t	mr_putstr(char *s, char p, char kar)
{
	size_t	i;

	i = 0;
	while (s && s[i] && !kar)
		write(1, &s[i++], p);
	return (write(1, &kar, (kar || 0)) + i);
}

unsigned long long int	itoa_base_v2(unsigned long long int i, char *s, char m)
{
	unsigned long long int	digit;
	unsigned long long int	lne;
	char					base;

	base = mr_putstr(s, 0, 0);
	lne = 1;
	digit = 1;

	if (m && (long long int)i < 0)
	{
		write(1, "-", (lne++ || 1));
		i *= -1;
	}
	while (i / (digit * base))
		digit *= base * (lne++ || 1);
	while (digit && (i / digit || !i))
	{
		mr_putstr(NULL, 1, s[(i / digit) % base]);
		digit /= base;
	}
	return (lne);
}

int	main(void)
{
	static const unsigned long long int	*asd;

	char str[5] = "abcde";
	char x;
	char y;

	x = 15;
	y = 5;
	printf("w%dw", ( 1 &&(x /= y)));
	printf("u%du", x);
	printf("\n%llu\n", itoa_base_v2(-2540923, strdup("0123456789"), 1));
	//unsigned long long int	a;
	//a = 01777777777777777777777;
	//a = 18446744073709551615ull;
}

/* if (*s != '%')
			write(1, s, 1);		
		else if (*++s == 'c')
			write(1, va_arg(argl, char*), 1);
		else if (*s == 's')
			//write(1, va_arg(argl, char*), ft_strlen(va_arg(argl, char*)));
			ft_putstr(va_arg(argl, char*), 1);
		else if (*s == 'p')
			ft_itoa_base(va_arg(argl, unsigned long), "0123456789abcdef", (ft_putstr("0x", 2) && 0));
		else if (*s == 'd')
			ft_itoa_base(va_arg(argl, int), "0123456789", 1);
		else if (*s == 'x')
			ft_itoa_base(va_arg(argl, unsigned long), "0123456789abcdef", 0);
		s++; */