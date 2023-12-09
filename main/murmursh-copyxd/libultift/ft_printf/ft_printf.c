/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:11:10 by marvin            #+#    #+#             */
/*   Updated: 2023/10/30 14:30:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(void *data)
{
	int		count;

	if (data == NULL)
		return (write(1, "0x0", 3));
	if (write(1, "0x", 2) == -1)
		return (-1);
	count = 2 + ft_print_digit2((unsigned long)data, 16, 0);
	return (count);
}

int	ft_printf_options(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_print_p(va_arg(args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_digit(va_arg(args, int), 10, 0));
	else if (specifier == 'u')
		return (ft_print_digit(va_arg(args, unsigned int), 10, 0));
	else if (specifier == 'x')
		return (ft_print_digit(va_arg(args, unsigned int), 16, 0));
	else if (specifier == 'X')
		return (ft_print_digit(va_arg(args, unsigned int), 16, 1));
	else
		return (ft_print_char('%'));
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		count;
	int		tmp;

	va_start(args, string);
	count = 0;
	while (*string != '\0')
	{
		if (*string == '%')
			tmp = ft_printf_options(*(++string), args);
		else
			tmp = write(1, string, 1);
		if (tmp == -1)
			return (-1);
		count += tmp;
		++string;
	}
	va_end(args);
	return (count);
}
