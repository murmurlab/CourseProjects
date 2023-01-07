/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:04:43 by ahbasara          #+#    #+#             */
/*   Updated: 2023/01/06 07:21:08 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_putstr(char *s, char p)
{
	size_t	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], p);
	return (i);
}

size_t	ft_itoa_base(unsigned long n, char *set, char sign)
{
	char	base;

	base = ft_putstr(set, 0);
	if ((int)n < 0 && sign)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= (unsigned long)base)
		ft_itoa_base(n / base, set, sign);
	write(1, &set[n % base], 1);
	return (1);
}

size_t	ft_printf(const char *s, ...)
{
	va_list	argl;
	char	*stock;

	stock = (char *)s;
	va_start(argl, s);
	while (*s)
	{

		s += (
			-1*~(0 + !(((*s != '%') && (write(1, s, 1) || 1)) ||
			!(((*(s + 1) == 'c') && (write(1, va_arg(argl, char*), 1) || 1)) || 
			((*(s + 1) == 's') && (ft_putstr(va_arg(argl, char*), 1) || 1)) ||
			((*(s + 1) == 'p') && (ft_itoa_base(va_arg(argl, unsigned long), "0123456789abcdef", (ft_putstr("0x", 2) && 0)) || 1)) ||
			((*(s + 1) == 'd') && (ft_itoa_base(va_arg(argl, int), "0123456789", 1) || 1)) ||
			((*(s + 1) == 'x') && (ft_itoa_base(va_arg(argl, unsigned int), "0123456789abcdef", 0) || 1)) ||
			((*(s + 1) == 'X') && (ft_itoa_base(va_arg(argl, unsigned int), "0123456789ABCDEF", 0) || 1)) ||
			((*(s + 1) == 'u') && (ft_itoa_base(va_arg(argl, unsigned int), "0123456789", 1) || 1)) ||
			1
			)))
		);
		
	}	
	return (s - stock);
}

/* int	main(void)
{
	//int a;
	//void	*p = &a;
	ft_printf("my,   |%o| asdds\n", -1234);
	printf("orig, %d asdds\n", (~4));
} */