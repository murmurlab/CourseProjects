/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:29:50 by hece              #+#    #+#             */
/*   Updated: 2023/01/15 03:08:41 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			ft_check_format(args, &str, &len);
		}
		else
			len += q(NULL, 0, *(str++));
	}
	va_end(args);
	return (len);
}

/* int	main(void)
{
	ft_printf("Hello World! %d", 0);
	return (0);
} */